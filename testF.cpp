#include<stdio.h>
#include<stdlib.h>
int main(){
    double array[10]={3,5,6,12,34,54,62,70,78,83};
    int numberOfBins=4;
    int numberOfElementsInTheArray=45;
    float widthOfBins=(float)numberOfElementsInTheArray/numberOfBins;
    float compareWoB=(int)numberOfElementsInTheArray/numberOfBins;
    int widthOfBins2=widthOfBins+1;
    compareWoB=compareWoB+.5;
    int state;
    if(widthOfBins>=compareWoB){
        widthOfBins2=(int)widthOfBins+1;
        state=1;
    }
    else {
            widthOfBins2=(int)widthOfBins;
            state=2;
    }
      printf("heherer %d\n",widthOfBins2);
    int flag=0;
    int remaining=numberOfElementsInTheArray;
    int rB=numberOfBins-1;
    //if(widthOfBins>=0)
    int bin=1;
    int reset=1;
    int flag2=0;
    int outputArray[numberOfElementsInTheArray];
    for(int iterator1=0;iterator1<numberOfElementsInTheArray;iterator1++){
        outputArray[iterator1]=bin;
        reset++;
        remaining--;
        //printf("%d ",remaining);

        if(state==1){
        if(rB!=0 && numberOfElementsInTheArray%numberOfBins!=0 && flag!=1 && flag2==2){
        if((remaining%rB)==0 && remaining/rB-widthOfBins2==-1){
            widthOfBins2=remaining/(rB);
            printf("eee here: %d \n",widthOfBins2);
            flag=1;
        }
        }
    }
        else if(state==2){
        if(rB!=0 && numberOfElementsInTheArray%numberOfBins!=0 && flag!=1 && flag2==2){
        if((remaining%rB)==0){
        if((remaining/rB)-widthOfBins2==1){
            widthOfBins2=remaining/(rB);
            printf("eee here: %d \n",widthOfBins2);
            printf("State 2");
            flag=1;
        }
        }
        }
        }
        if(reset>widthOfBins2){
            bin++;
            rB--;
            printf("Bin: %d Rb: %d remaining: %d\n",bin,rB,remaining);
            reset=1;
            flag2=2;
        }

    }
    int arrayBins[numberOfBins+1]={0};
    for(int iterator1=0;iterator1<numberOfElementsInTheArray;iterator1++)
    arrayBins[outputArray[iterator1]]++;
    for(int iterator1=1;iterator1<=numberOfBins;iterator1++)
        printf("%d ",arrayBins[iterator1]);
    //for(int iterator1=0;iterator1<numberOfElementsInTheArray;iterator1++)
       // printf("\n%d ",outputArray[iterator1]);

}
