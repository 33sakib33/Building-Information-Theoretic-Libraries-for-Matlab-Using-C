#include<stdio.h>
int main(){
 double array[10]={3,5,6,12.545,34.45453,54,62,70,78,83};
    int numberOfBins=4;
    int numberOfElementsInTheArray=17;
    float widthOfBins=(float)numberOfElementsInTheArray/numberOfBins;
    float compareWoB=(int)numberOfElementsInTheArray/numberOfBins;
    int widthOfBins2=widthOfBins+1;
    compareWoB=compareWoB+.5;
    int bin=1;
    int reset=1;
    int flag=1;
    int remainingBins=numberOfBins-1;
    int remaining=numberOfElementsInTheArray;
    int outputArray[13];
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
    for(int iterator1=0;iterator1<numberOfElementsInTheArray;iterator1++){
        printf("%d ",outputArray[iterator1]);
    }

}
