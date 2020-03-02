#include<stdio.h>
#include<stdlib.h>
int main(){
    double inputArrray;
    int numberOfElementsInTheInputArray=13;
    double binCount;
    int numberOfBins=5;
    int frequencyOfBins=(int)((numberOfElementsInTheInputArray+numberOfBins)/numberOfBins);
    int extra=numberOfElementsInTheInputArray%numberOfBins;
    int *outputArray;
    printf("%d\n",frequencyOfBins);
    int bin=1;
    int flag=0;
    int reset=0;
    outputArray=(int*) calloc(sizeof(int),numberOfElementsInTheInputArray);
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
    for(int iterator1=0;iterator1<numberOfElementsInTheInputArray;iterator1++){
        printf(" %d",outputArray[iterator1]);
    }
    
}