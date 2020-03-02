#include"mex.h"
#include"matrix.h"
#include<stdlib.h>
#include<stdio.h>
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
    double *inputArray;
    inputArray=mxGetPr(prhs[0]);
    double *binCount=mxGetPr(prhs[1]);
    int numberOfBins=(int)*binCount;
    int numberOfElementsInTheInputArray=mxGetNumberOfElements(prhs[0]);
    int frequencyOfBins=(int)((numberOfElementsInTheInputArray+numberOfBins)/numberOfBins);
    int extra=numberOfElementsInTheInputArray%numberOfBins;

    //printf("%d\n",frequencyOfBins);
    int bin=1;
    int flag=0;
    int reset=0;
    plhs[0]=mxCreateDoubleMatrix(numberOfElementsInTheInputArray,1,mxREAL);
    double *outputArray;
    outputArray=mxGetPr(plhs[0]);
    //outputArray=(int*) calloc(sizeof(int),numberOfElementsInTheInputArray);
    for(int iterator1=0;iterator1<numberOfElementsInTheInputArray;iterator1++){
            outputArray[iterator1]=bin;
            extra--;
            reset++;
            if(reset==frequencyOfBins){
                bin++;
                reset=0;
            }
            if(extra==0 && flag==0){
                frequencyOfBins--;
                flag=1;
            }

    }
    /*for(int iterator1=0;iterator1<numberOfElementsInTheInputArray;iterator1++){
        printf(" %d",outputArray[iterator1]);
    }*/

}
