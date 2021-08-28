#include"mex.h"
#include"matrix.h"
#include<stdio.h>
#include<math.h>




void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
    double *jointPointer= mxGetPr(prhs[0]);
    long long row=mxGetM(prhs[0]);
    long long col=mxGetN(prhs[0]);

    double *mPointer =mxGetPr(prhs[1]);

    double **jointPr= new double *[col];
    for(long long itr1=0;itr1<col;itr1++){
        jointPr[itr1]=jointPointer+itr1*row;
    }

    double condentropy=0;
    for(int itr1=0;itr1<col;itr1++){
        for(int itr2=0;itr2<row;itr2++){
            if(jointPr[itr1][itr2]!=0 && mPointer[itr1]!=0){
                condentropy+=(jointPr[itr1][itr2]*(log(mPointer[itr1]/jointPr[itr1][itr2])));
            }
        }
    }
    condentropy/=log(2.000000);

    plhs[0]=mxCreateDoubleMatrix(1,1,mxREAL);
    *mxGetPr(plhs[0])=condentropy;
    delete []jointPr;

}
