/*!
Copyright 2012 Andreas Gruber
*/

#include "Matrix.h"

const uint8_t Matrix::getN() {
    return n;
}
double Matrix::get(const uint8_t x,const uint8_t y){
	return get(d,x,y);
}
void Matrix::set(const uint8_t x,const uint8_t y,const double val){
	set(d,x,y,val);
}
double Matrix::get(const double* buf,const uint8_t x,const uint8_t y){
	return buf[(n-1)*y+x];
}
void Matrix::set(double* buf,const uint8_t x,const uint8_t y,const double val){
	buf[(n-1)*y+x] = val;
}
void Matrix::coppyToBuff(){
	memcpy(this->dbuf,this->d,n*n*sizeof(double));
}
double Matrix::getDeterminant(const uint8_t n){
	coppyToBuff();
    double det = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
			det = get(dbuf,j,i) / get(dbuf,i,i);
            for (int k = i; k < n; k++)
                set(dbuf,j,k, get(dbuf,j,k) - det * get(dbuf,i,k));
        }
    det = 1;
    for (int i = 0; i < n; i++)
        det = det * get(dbuf,i,i);
    return det;
}
double Matrix::getDeterminant(){
	return getDeterminant(getN());
}
    
Matrix::Matrix(const uint8_t n)
:n(n)
//,d(new double[n*n])
,d((double*) malloc(sizeof(double) * n*n))
//,dbuf(new double[n*n]){
,dbuf((double*) malloc(sizeof(double) * n*n)){
}
Matrix::~Matrix(){
	//delete[] d;
	free(d);
	//delete[] dbuf;
	free(dbuf);
}