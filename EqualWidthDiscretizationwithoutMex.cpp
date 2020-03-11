
#include<stdlib.h>
#include<stdio.h>
void findMinAndMax(double *minP,double *maxP,double *arrayParameter,int lengthOfArray){
    for(int iterator1=0;iterator1<lengthOfArray;iterator1++){
        if(arrayParameter[iterator1]>*maxP)
            *maxP=arrayParameter[iterator1];
        if(arrayParameter[iterator1]<*minP)
            *minP=arrayParameter[iterator1];
    }
}
int main(){
    double inputArray[9]={2,5,12,15,22,25,35,9,31};
    //inputArray=mxGetPr(prhs[0]);
    //double *binCount=mxGetPr(prhs[1]);
    int numberOfBins=5;
    int numberOfElementsInTheArray=9;
    double max1=0;
    double min1=99999999;
    findMinAndMax(&min1,&max1,inputArray,numberOfElementsInTheArray);
    double width=(max1-min1)/numberOfBins;
    int discretizationLevel;
    //plhs[0]=mxCreateDoubleMatrix(numberOfElementsInTheArray,1,mxREAL);
    int outputArray[numberOfElementsInTheArray];
    //outputArray=mxGetPr(plhs[0]);
    for(int iterator1=0;iterator1<numberOfElementsInTheArray;iterator1++){
        if(inputArray[iterator1]==min1)
            outputArray[iterator1]=1;
        else if(inputArray[iterator1]==max1)
            outputArray[iterator1]=numberOfBins;
        else{
            discretizationLevel=(int)((inputArray[iterator1]-min1)/width);
            //double positionComparartor=(int)discretizationLevel+1;
            outputArray[iterator1]=discretizationLevel+1;

        }
    }

    for(int iterator1=0;iterator1<numberOfElementsInTheArray;iterator1++){
        printf(" %d",outputArray[iterator1]);
    }


}
