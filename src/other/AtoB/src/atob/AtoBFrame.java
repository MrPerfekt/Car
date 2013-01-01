/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package atob;

import java.awt.*;
import javax.swing.JFrame;

/**
 *
 * @author Andreas
 */
class OrientedCoordinates extends Vector{
    public double angle;
    public OrientedCoordinates(double x,double y, double angle){
        super(x,y);
        this.angle = angle;
    }
}
class Vector{
    public double x, y;
    Vector() {
        this(0,0);
    }
    public Vector(double x,double y){
        this.x = x;
        this.y = y;
    }
    
    public double getLength(){
        return Math.sqrt(x*x+y*y);
    }
    public Vector multiply(double i){
        x *= i;
        y *= i;
        return this;
    }
    public Vector divide(double i){
        x /= i;
        y /= i;
        return this;
    }
    public Vector add(Vector v){
        x += v.x;
        y += v.y;
        return this;
    }
    public Vector substract(Vector v){
        x -= v.x;
        y -= v.y;
        return this;
    }
    public Vector makeNormal(boolean left){
        double sX = x;
        x = y*(left ? -1 : 1);
        y = sX*(left ? 1 : -1);
        return this;
    }
    public Vector makeUnit(){
        double len = getLength();
        divide(len);
        return this;
    }
    public double dotProduct(Vector v){
        return x*v.x+y*v.y;
    }
    public double angleBetween(Vector v){
        return Math.acos(dotProduct(v) / getLength() / v.getLength());
    }
    public Vector setToUnitVectorByAngle(double angle){
        set(Math.cos(angle),Math.sin(angle));
        return this;
    }
    public Vector set(double x, double y) {
        this.x = x;
        this.y = y;
        return this;
    }
    public Vector set(Vector v) {
        this.x = v.x;
        this.y = v.y;
        return this;
    }
    
    @Override
    public Vector clone(){
        return new Vector(x, y);
    }
    
    @Override
    public String toString(){
        return "x: " + x + "  y: " + y;
    }
}
public class AtoBFrame extends JFrame{
    
    public AtoBFrame(){
    }
    
    static final int pSize = 5;
    public static void drawLine(Graphics g, double k, double d){
        g.drawLine(-10000, (int)(k*(-10000)+d), 10000, (int)(k*(10000)+d));
    }
    public static void drawLine(Graphics g, Vector v0, Vector v1){
        g.drawLine((int)v0.x,(int)v0.y,(int)v1.x,(int)v1.y);
    }
    public static void drawPoint(Graphics g,Vector v){
        g.fillOval((int)(v.x-pSize/2), (int)(v.y-pSize/2), pSize, pSize);
    }
    public static void drawCircle(Graphics g,Vector v,double r){
        g.drawOval((int)(v.x-r), (int)(v.y-r), (int)(r*2), (int)(r*2));
    }
    
    static final double circle = 2*Math.PI;
    public static double circleToDegree(double angle){
        return angle * 2 * Math.PI / circle;
    }
    
    public OrientedCoordinates p[] = new OrientedCoordinates[]{
            new OrientedCoordinates(100,250,0 * 2*Math.PI / 360),
            new OrientedCoordinates(400,250,0 * 2*Math.PI / 360),
        };
    
    @Override
    public void paint( Graphics gInp ){
        Graphics2D g = ((Graphics2D)gInp);
        //AffineTransform at = new AffineTransform();
        //at.scale(1, -1);
        //at.translate(0, -getHeight());
        //g.setTransform(at);
        
        g.setColor(Color.WHITE);
        g.fill3DRect(0, 0, getWidth(), getHeight(), true);
        g.setColor(Color.BLACK);
        
        double r = 50;
        //!Circle Centers
        Vector[] cc = new Vector[4]; //!Circle Centers
        for(int i = 0; i < 4; i++){
            int iC = i / 2; //!Circle/Line Nr
            int iS = i % 2; //!Side Nr
            double iAngle = p[iC].angle + 2*Math.PI / 4 * (1 - iS * 2);
            cc[i] = new Vector().setToUnitVectorByAngle(iAngle).multiply(r).add(p[iC]);
        }
        //!Circle Tangent
        Vector vhelp = new Vector(0, 0);
        for(int id0 = 0; id0 < 2; id0++){
            int i0C = 0; //!Circle/Line Nr
            int i1C = 1; 
            int i0S = id0 % 2; //!Side Nr
            for(int i1S = 0; i1S < 2; i1S++){ 
                int id1 = i1C*2 + i1S; //! = id0+2                
                
                Vector v = cc[id1].clone().substract(cc[id0]);//!Distance of both circles
                //!
                //!Main Gradient
                //!
                //!Vector v contains the vektor circle0 to circle1
                //!MainAngle contains the angle between circle 0 and its horizontal line and circle1.
                double mainAngle = v.angleBetween(vhelp.set(1,0)); 
                if(cc[id1].y < cc[id0].y)
                    mainAngle = 2*Math.PI - mainAngle;
                System.out.println(mainAngle);
                //!
                //!Angle
                //!
                //!Calculate the start end end angle
                double angleStart = Math.PI * 3 + (mainAngle - p[i0C].angle) * (i0S == 0 ? -1 : 1);
                //!The path of the second circle will be driven in the other direction.
                double angleEnd = Math.PI * 5 + (mainAngle - p[i1C].angle) * (i1S == 0 ? 1 : -1);
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
                    double pitchAngle = Math.acos(r/(distance/* /2 */));
                    //!Add the difference of the angle to the final angle
                    angleStart += Math.PI/2-pitchAngle;
                    angleEnd += Math.PI/2-pitchAngle;
                    //!
                    //!Distance which have to be driven
                    //!With the Pythagorean theorem the distance can be calculated with the distance from the circle center to the midpoint and the radius.
                    //!
                    distance = Math.sqrt(distance * distance/* /4 */ + r*r) * 2;
                    //!
                    //!Tangent boundary point
                    //!
                    //!Calculates the direction, multiply that vektor with the radius and add the circle position.
                    int direction = i0S == 0 ? 1 : -1;
                    //!Describes the angle of point where the tangent start
                    double finalPitchAgnle = mainAngle+pitchAngle*direction;
                    v.setToUnitVectorByAngle(finalPitchAgnle).multiply(r).add(cc[id0]);
                    
                    //!Only for painting
                    drawPoint(g, v);
                    drawLine(g, v, cc[id1].clone().substract(cc[id0]).divide(2).add(cc[id0]).substract(v).multiply(2).add(v));
                }else{
                    //!Create normal vector and set the length to the radius
                    v.makeNormal(i0S == 0).makeUnit().multiply(r).add(cc[id0]);
                    
                    //!Only for painting
                    drawPoint(g, v);
                    drawLine(g, v, cc[id1].clone().substract(cc[id0]).add(v));
                }
                angleStart %= (Math.PI*2);
                angleEnd %= (Math.PI*2);
                
                //!
                //!FullDistance is the distance which have to be driven by the car.
                //!This includes also the path of the circles which is calculated by radius * angle
                //!U / (full degrees) * (part degrees)
                //!2 * r * pi / ( 2 * pi) * angle
                //!r * angle
                //!
                double fullDistance = distance + r * (angleEnd+angleStart);
                
                
                //!Only for Output
                if(i0S == 0)
                    System.out.print("left  ");
                else
                    System.out.print("right ");
                if(i1S == 0)
                    System.out.print("left  ");
                else
                    System.out.print("right ");
                
                System.out.printf("a:%4d, b:%4d, d:%4d, fd:%4d\n",
                        Math.round(Math.toDegrees(angleStart)),
                        Math.round(Math.toDegrees(angleEnd)),
                        Math.round(distance),
                        Math.round(fullDistance)
                        );
            }
        }        
        System.out.println();
        
        g.setColor(Color.yellow);
        for(int i = 0; i < 2;i++){
            double ak = Math.tan(p[i].angle);
            double ad = p[i].y - p[i].x * ak;
            drawLine(g, ak, ad);
        }
        g.setColor(Color.green);
        for(int i = 0; i < 2;i++){
            drawPoint(g, p[i]);
        }
        g.setColor(Color.red);
        for(int i = 0; i < 4;i++){
            drawPoint(g,cc[i]);
            drawCircle(g, cc[i], r);
        }
    }
}
