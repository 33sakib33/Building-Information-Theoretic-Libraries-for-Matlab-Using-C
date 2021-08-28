#include"mex.h"
#include"matrix.h"
#include<bits/stdc++.h>

long long countStates(double *arrayParameter,long long sizeOfArray)
{
    double minimum=arrayParameter[0];
    double maximum=arrayParameter[0];
    for(long long iterator1=0; iterator1<sizeOfArray; iterator1++)
    {
        minimum=(arrayParameter[iterator1]>minimum)?minimum:arrayParameter[iterator1];
        maximum=(arrayParameter[iterator1]<maximum)?maximum:arrayParameter[iterator1];
    }
    for(long long iterator1=0; iterator1<sizeOfArray; iterator1++)
        arrayParameter[iterator1]=arrayParameter[iterator1]-minimum;
    long long numberOfStates=maximum-minimum+1;
    return numberOfStates;
}

void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[]){
        double *sample=mxGetPr(prhs[0]);
        int len= mxGetScalar(prhs[1]);

        long long len_in=(long long)len;
        long long stateCount= countStates(sample,len_in);
       //long long stateCount=2;
        plhs[0]=mxCreateDoubleMatrix(stateCount,1,mxREAL);
        double* probArray;
        probArray=mxGetPr(plhs[0]);

        for(int itr=0;itr<len_in;itr++){
                probArray[(int)sample[itr]]++;
        }
        for(int itr1=0;itr1<stateCount;itr1++){
            if(len_in!=0)
            probArray[itr1]/=len_in;
        }



}
