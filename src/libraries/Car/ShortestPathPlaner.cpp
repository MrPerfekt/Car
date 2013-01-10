/*!
Copyright 2012 Andreas Gruber
*/

#include "ShortestPathPlaner.h"
#include "OrientationCoordinates.h"
#include "Path.h"
#include "float.h"
#include "TurnMovement.h"
#include "StraightMovement.h"

ShortestPathPlaner::ShortestPathPlaner(PositionCalculator &positionCalculator, PathExecutor &pathExecutor)
	:PathPlaner(positionCalculator,pathExecutor)
{
}

Path* ShortestPathPlaner::calculatePath(const OrientationCoordinates& startPosition, const OrientationCoordinates& endPosition){
	double minAngleStart = 0, 
		minAngleEnd = 0, 
		minDistance = 0, 
		minFullDistance = DBL_MAX;
	bool minFirstLeft = true, minSecondLeft = true;

	double r = Config::getMinSteeringRadius();
    //!Circle Centers
    Vector cc[4];
    for(int i = 0; i < 4; i++){
        int iC = i / 2; //!Circle/Line Nr
        int iS = i % 2; //!Side Nr
		const OrientationCoordinates &pos = (iC == 0) ? startPosition : endPosition;

		double iAngle = pos.getAngle() + 2*PI / 4 * (1 - iS * 2);
        cc[i].setToUnitVectorByAngle(iAngle);
		cc[i] *= r;
		cc[i] += pos;
    }
    //!Circle Tangent
    Vector vhelp = Vector(0, 0);
    for(int id0 = 0; id0 < 2; id0++){
        int i0S = id0 % 2; //!Side Nr
        for(int i1S = 0; i1S < 2; i1S++){ 
            int id1 = 2 + i1S; //! = id0+2

            Vector v = cc[id1].clone();//!Distance of both circles
			v -= cc[id0];              //!
            //!
            //!Main Gradient
            //!
            //!Vector v contains the vektor circle0 to circle1
			//!MainAngle contains the angle between circle 0 and its horizontal line and circle1.
			vhelp.set(1,0);
            double mainAngle = v.angleBetween(vhelp); 
	Serial.print(mainAngle);
	Serial.print("  ");
			if(cc[id1].getY() < cc[id0].getY())
                mainAngle = 2*PI - mainAngle;

            //!
            //!Angle
            //!
            //!Calculate the start end end angle
			double angleStart = PI * 3 + (mainAngle - startPosition.getAngle()) * (i0S == 0 ? -1 : 1);
            //!The path of the second circle will be driven in the other direction.
			double angleEnd = PI * 5 + (mainAngle - endPosition.getAngle()) * (i1S == 0 ? 1 : -1);
            //!The initialication distance is the distance between both circles, which is preaty fine for i0S == i1S.
            double distance = v.getLength();
            //!
            //!If the two circles have to be connected with tangents which are paralell i0S == i1S.
            //!
            if(i0S != i1S){
                distance /= 2;//!Distance from circle to the midpoint of both circles
                //!
                //!Pitch Angle
                //!
                //!PitchAngle contains the Angle which is required to create a tangent to a poit at the horizontal line with the halfe distance of both circles.
                double pitchAngle = acos(r/(distance/* /2 */));
                //!Add the difference of the angle to the final angle
				angleStart += PI/2-pitchAngle;
                angleEnd += PI/2-pitchAngle;
                //!
                //!Distance which have to be driven
                //!With the Pythagorean theorem the distance can be calculated with the distance from the circle center to the midpoint and the radius.
                //!
                distance = sqrt(distance * distance/* /4 */ + r*r) * 2;
            }
			angleStart = fmod(angleStart,PI * 2);
			angleEnd = fmod(angleEnd,PI * 2);
                
            //!
            //!FullDistance is the distance which have to be driven by the car.
            //!This includes also the path of the circles which is calculated by radius * angle
            //!U / (full degrees) * (part degrees)
            //!2 * r * pi / ( 2 * pi) * angle
            //!r * angle
            //!
            double fullDistance = distance + r * (angleEnd+angleStart);
			
	Serial.print(mainAngle);
	Serial.print("  ");
	Serial.print(angleStart);
	Serial.print("  ");
	Serial.print(angleEnd);
	Serial.print("  ");
	Serial.print(distance);
	Serial.print("  ");
	Serial.print(fullDistance);
	Serial.print("  ");
	Serial.println();

			if(fullDistance < minFullDistance){
                minFirstLeft = i0S == 0;
				minSecondLeft = i1S == 0;
				minAngleStart = angleStart;
				minAngleEnd = angleEnd;
				minDistance = distance;
				minFullDistance = fullDistance;
			}
        }
    }
	Serial.println();
	Serial.print(minAngleStart);
	Serial.print("  ");
	Serial.print(minAngleEnd);
	Serial.print("  ");
	Serial.print(minDistance);
	Serial.print("  ");
	Serial.print(minFullDistance);
	Serial.print("  ");
	Serial.println();
	Serial.println();
	Path*p = new Path();
	
	TurnMovement*tmStart = new TurnMovement();
	tmStart->setAngleRadius(minAngleStart,r*(minFirstLeft ? 1 : -1));
	p->addMovement(tmStart);

	p->addMovement(new StraightMovement(minDistance));

	TurnMovement*tmEnd = new TurnMovement();
	tmEnd->setAngleRadius(minAngleStart,r*(minSecondLeft ? 1 : -1));
	p->addMovement(tmEnd);
	return p;
}