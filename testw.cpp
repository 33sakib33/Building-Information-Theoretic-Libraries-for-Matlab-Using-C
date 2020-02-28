#include<stdio.h>
#include<stdlib.h>

int main(){
    double array1[10]={44.0000001,85,55,59,67.545454,72.00005,73.23,79.5,82.232,87.531};
    double max1=array1[9];
    double min1=array1[0];
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
