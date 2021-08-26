#include"mex.h"
#include"matrix.h"
#include<bits/stdc++.h>
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
    double *jointprb= mxGetPr(prhs[0]);
    long long jointprob_row= mxGetM(prhs[0]);
    long long jointprob_col= mxGetM(prhs[0]);
    double **usedjointprob = new double *[jointprob_col];
    for(int itr1=0;itr1<jointprob_col;itr1++){
        usedjointprob[itr1] =  jointprb + (long long) itr1*jointprob_row;
    }
    double *prob_1, *prob_2;
    long long prob_1_size, prob_2_size;
    prob_1=mxGetPr(prhs[1]);
    prob_1_size=mxGetM(prhs[1])*mxGetN(prhs[1]);
    prob_2=mxGetPr(prhs[2]);
    prob_2_size=mxGetM(prhs[2])*mxGetN(prhs[2]);
    double degree_of_freedom1=mxGetScalar(prhs[3]);
    double degree_of_freedom2=mxGetScalar(prhs[4]);
    double sampleSize= mxGetScalar(prhs[5]);
    plhs[0]=mxCreateDoubleMatrix(1,1,mxREAL);
    double *mutualinf=mxGetPr(plhs[0]);
    double res=0.0;
    for(long long itr1=0;itr1<jointprob_col;itr1++){
        for(long long itr2=0;itr2<jointprob_row;itr2++){
            if(usedjointprob[itr1][itr2]!=0 && prob_1[itr2]!=0 && prob_2[itr1]!=0){
                res+=usedjointprob[itr1][itr2]* log(usedjointprob[itr1][itr2]/prob_1[itr2]/prob_2[itr1]);
            }
        }
    }
    double log2saved=log(2.0000);
    res/=log2saved;
    double bias=(degree_of_freedom1-1)*(degree_of_freedom2-1)/(2*sampleSize*log2saved);
    *mutualinf=res-bias;
    return;
}

