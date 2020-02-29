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
    double max1=array1[9];
    double min1=array1[2];
    int binCount=4;
    double width=(max1-min1)/binCount;
    int position;
    int outputArray[10];
    for(int iterator1=0;iterator1<10;iterator1++){
        if(array1[iterator1]==min1)outputArray[iterator1]=1;
        else if(array1[iterator1]==max1)outputArray[iterator1]=binCount;
        else{ double position=(array1[iterator1]-min1)/width;
        double positionComparartor=(int)position+1;
        outputArray[iterator1]=position+1;
        }
    }
    for(int iterator1=0;iterator1<10;iterator1++){
        printf(" %d",outputArray[iterator1]);
    }


}