#include<bits/stdc++.h>
#include"matrix.h"
#include"mex.h"
using namespace std;

void normalize(double *arr,long long *state,long long size1){
    long long min1=arr[0];
    long long max1=arr[0];
    for(int itr1=0;itr1<size1;itr1++){
        min1=(min1>arr[itr1])?arr[itr1]:min1;
        max1=(max1<arr[itr1])?arr[itr1]:max1;
    }
    *state=max1-min1+1;
    for(int itr1=0;itr1<size1;itr1++){
        arr[itr1]-=min1;
    }
}
void mvar(double *arr1,double *arr2, long long state1, long long state2 ,long long size1,double *merged){
    long long flag[state1][state2];
    memset(flag,0,sizeof flag);
    long long stateCount=-1;
    for(int itr1=0;itr1<size1;itr1++){
            long long f1=arr1[itr1];
            long long f2=arr2[itr1];
        if(flag[f1][f2]!=-1){
            stateCount++;
            flag[f1][f2]=stateCount;
            merged[itr1]=flag[f1][f2];
        }
        else{
            merged[itr1]=flag[f1][f2];
        }
    }
}
void mvar2(double *arr1,double *arr2, long long state1, long long state2 ,long long size1,double *merged){
    long long flag[state1][state2];
    map<pair<double,double>,long long> a;
    memset(flag,0,sizeof flag);
    long long stateCount=-1;
    for(int itr1=0;itr1<size1;itr1++){
            double f1=arr1[itr1];
            double f2=arr2[itr1];
            pair<double,double> p = make_pair(f1,f2);
        if(a.find(p)==a.end()){
           // mexPrintf("asdasdas");
            stateCount++;
            a[p]=stateCount;
            merged[itr1]=stateCount;
        }
        else{
             merged[itr1]=a[p];
        }
    }

}


void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[]){

    double *arr1, *arr2;
    arr1=mxGetPr(prhs[0]);
    arr2=mxGetPr(prhs[1]);
    long long size1=mxGetM(prhs[0])*mxGetN(prhs[0]);
    long long size2=mxGetM(prhs[1])*mxGetN(prhs[1]);
    long long state1,state2;
    normalize(arr1,&state1,size1);
    normalize(arr2,&state2,size2);

    plhs[0]=mxCreateDoubleMatrix(size1,1,mxREAL);
    double *merged=mxGetPr(plhs[0]);
    mvar(arr1,arr2,state1,state2,size1,merged);
    //mvar2(arr1,arr2,state1,state2,size1,merged);



    return;
}
