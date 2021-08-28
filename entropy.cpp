#include"mex.h"
#include"matrix.h"
#include<bits/stdc++.h>

double entropy(double *probarray,int sizeOfArray){
    double H;
    for(int itr1=0;itr1<sizeOfArray;itr1++){
       H=H-probarray[itr1]*log(probarray[itr1]);
    }
    H=H/log(2);
    return H;
}

void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[]){
    double* probArray=mxGetPr(prhs[0]);
    int sizeOfArray=mxGetScalar(prhs[1]);
    plhs[0]=mxCreateDoubleMatrix(1,1,mxREAL);
    double *entropyH=mxGetPr(plhs[0]);
    *entropyH=entropy(probArray,sizeOfArray);
}
