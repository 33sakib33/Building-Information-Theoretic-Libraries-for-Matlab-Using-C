#include<bits/stdc++.h>
#include"mex.h"
#include"matrix.h"
using namespace std;


double joint_entropy(double **jointProbabilityArray, int state1,int state2){
        double HXY=0;
        for(int itr1=0;itr1<state1;itr1++){
            for(int itr2=0;itr2<state2;itr2++){
                if(jointProbabilityArray[itr1][itr2]){
                    HXY=HXY-jointProbabilityArray[itr1][itr2]*log(jointProbabilityArray[itr1][itr2]);
                }
            }
        }
        HXY=HXY/log(2);
        return HXY;
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
    double *jointPointer= mxGetPr(prhs[0]);
    long long row=mxGetM(prhs[0]);
    long long col=mxGetN(prhs[0]);

    double *mPointer =mxGetPr(prhs[0]);
    int state1=mxGetScalar(prhs[1]);
    int state2=mxGetScalar(prhs[2]);

    double **jointPr= new double *[col];
    for(long long itr1=0;itr1<col;itr1++){
        jointPr[itr1]=jointPointer+itr1*row;
    }
    plhs[0]=mxCreateDoubleMatrix(1,1,mxREAL);
    double *jointEntropy;
    jointEntropy=mxGetPr(plhs[0]);
    *jointEntropy=joint_entropy(jointPr,state1,state2);


}
