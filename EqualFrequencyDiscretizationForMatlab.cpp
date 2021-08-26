#include"mex.h"
#include"matrix.h"
#include<stdlib.h>
#include<stdio.h>
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
    double *inputArray,*binCount;
    long long numberOfBins,numberOfElementsInTheInputArray,frequencyInBins,extra,flag=0,flag2=2,bin=1,reset=0;
    inputArray=mxGetPr(prhs[0]);
    binCount=mxGetPr(prhs[1]);
     numberOfBins=(long long)*binCount;
     numberOfElementsInTheInputArray=mxGetNumberOfElements(prhs[0]);
     if(numberOfElementsInTheInputArray%numberOfBins!=0){
     frequencyInBins=(long long)((numberOfElementsInTheInputArray+numberOfBins-1)/numberOfBins);

     flag2=-1;
     }
     else {
            frequencyInBins=numberOfElementsInTheInputArray/numberOfBins;
        // mexPrintf("hello");
     }
    extra=numberOfElementsInTheInputArray%numberOfBins;

    //printf("%d\n",frequencyOfBins);

    plhs[0]=mxCreateDoubleMatrix(numberOfElementsInTheInputArray,1,mxREAL);
    double *outputArray;
    outputArray=mxGetPr(plhs[0]);
    //outputArray=(int*) calloc(sizeof(int),numberOfElementsInTheInputArray);
    for(long long iterator1=0;iterator1<numberOfElementsInTheInputArray;iterator1++){
            outputArray[iterator1]=bin;
            extra--;
            reset++;
            if(reset==frequencyInBins){
                bin++;
                reset=0;
                if(flag2==-1)
                flag2=0;
            }
            if(extra<=0 && flag==0 && flag2==0){
                frequencyInBins--;
                flag=1;
            }

    }
    /*for(int iterator1=0;iterator1<numberOfElementsInTheInputArray;iterator1++){
        printf(" %d",outputArray[iterator1]);
    }*/

}
