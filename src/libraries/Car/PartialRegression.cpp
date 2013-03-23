/*!
Copyright 2013 Andreas Gruber
*/

#include "PartialRegression.h"
#include "Vector.h"
#include "Matrix.h"


PartialRegression::PartialRegression(const uint8_t equationPow)
:equationPow(equationPow)
,n(0)
//,solution(new double[equationPow])
,solution((double*) malloc(sizeof(double) * equationPow))
//,xsum(new double[2*equationPow-1])
,xsum((double*) malloc(sizeof(double) * (2*equationPow-1)))
//,xysum(new double[equationPow])
,xysum((double*) malloc(sizeof(double) * equationPow))
,sum(new Matrix(equationPow)){
    for(uint8_t i = 0; i < 2*equationPow-1; i++)
        xsum[i] = 0;
    for(int i = 0; i < equationPow; i++)
        xysum[i] = solution[i] = 0;
}
PartialRegression::~PartialRegression() {
	//delete[] xsum;
	free(xsum);
	//delete[] xysum;
	free(xysum);
	//delete[] solution;
	free(solution);
	delete sum;
}
void PartialRegression::addPoint(const Vector &p){
	double pot = 1;
    for(int j = 0; j < 2*equationPow-1; j++){
		xsum[j] += pot;
		pot *= p.getX();
	}
	pot = p.getY();
    for(int j = 0; j < equationPow; j++){
		xysum[j] += pot;
		pot *= p.getX();
	}
}
double* PartialRegression::calculate(const uint8_t epot){
	if(epot > equationPow || epot < 0) return 0;
	solEpot = epot;
    for(int i = 0; i < epot; i++)
        for(int j = 0; j < epot; j++)
            sum->set(i,j,xsum[2*(epot-1)-i-j]);
    double det = sum->getDeterminant();
    for(int i = 0; i < epot; i++){
        for(int j = 0; j < epot; j++)
            sum->set(j,i,xysum[epot-1-j]);
        solution[i] = sum->getDeterminant() / det;
        for(int j = 0; j < epot; j++)
            sum->set(j,i,xsum[2*(epot-1)-i-j]);
    }
    return solution;
}
double PartialRegression::calculateY(double x){
    double y = 0,p = 1;
    for(int calcPot = 0; calcPot < solEpot;calcPot++){
        y += p*solution[solEpot-1-calcPot];
        p *= x;
    }
    return y;
}