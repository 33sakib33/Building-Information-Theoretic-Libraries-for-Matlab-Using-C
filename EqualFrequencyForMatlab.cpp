#include"mex.h"
#include"matrix.h"
#include<stdlib.h>
#include<stdio.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
    double *inputArray;
    inputArray=mxGetPr(prhs[0]);
    double *binCount=mxGetPr(prhs[1]);
    int numberOfBins=(int)*binCount;
    int numberOfElementsInTheArray=mxGetNumberOfElements(prhs[0]);
    double widthOfBins=(double)numberOfElementsInTheArray/numberOfBins;
    double compareWoB=(int)numberOfElementsInTheArray/numberOfBins;
    int widthOfBins2=widthOfBins+1;
    compareWoB=compareWoB+.5;
    int bin=1;
    int reset=1;
    int flag=1;
    int remainingBins=numberOfBins-1;
    int remaining=numberOfElementsInTheArray;
    plhs[0]=mxCreateDoubleMatrix(numberOfElementsInTheArray,1,mxREAL);
     double *outputArray;
     outputArray=mxGetPr(plhs[0]);
    if(widthOfBins>=compareWoB){
        widthOfBins2=(int)widthOfBins+1;
    }
    else {
            widthOfBins2=(int)widthOfBins;
    }
    for(int iterator1=0;iterator1<numberOfElementsInTheArray;iterator1++){
        outputArray[iterator1]=bin;
        reset++;
        remaining--;
          if(reset>widthOfBins2){
            bin++;
            remainingBins--;
            //printf("Bin: %d Rb: %d remaining: %d\n",bin,rB,remaining);
            reset=1;
        }
        if(remainingBins==0 && flag==1){
            //printf("hehe %d\n",remaining);
            widthOfBins2=remaining;
            flag=0;
        }
    }
       // for(int iterator1=0;iterator1<numberOfElementsInTheArray;iterator1++){
        //mexPrintf("%f ",outputArray[iterator1]);
    //}
}
