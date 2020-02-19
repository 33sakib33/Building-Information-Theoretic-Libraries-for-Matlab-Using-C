//#include"mex.h"
//#include"matrix.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct binStructure
{
    int *arrayOfElements;
    int countOfElements;
} bins;

bins *bin;

int main()
{

    double inputArray[10]={1.7,2.5,3,4,5,6,7,8,8.6,10.5};

    //pointerForTheArray=mxGetPr(prhs[0]);
    //int min=10000000,max=0;
   // int numberOfElementsInTheInputArray=mxGetNumberOfElements(prhs[0]);
    int numberOfElementsInTheInputArray=10;
    double numberOfBins=5;

    //numberOfBins=mxGetPr(prhs[1]);
    int binCount=4;
    //mexPrintf("%d\n",pots);
    int widthOfTheBins=((numberOfElementsInTheInputArray)/binCount);
    /*if(numberOfElementsInTheInputArray%binCount!=0)
        widthOfTheBins=widthOfTheBins+1;*/
    bin = (bins*)calloc(binCount,sizeof(bins));
    int *outputArray;
    outputArray=(int*)calloc(numberOfElementsInTheInputArray,sizeof(int));

    /*for(int iterator1=0; iterator1<binCount; iterator1++)
    {

        bin[iterator1].arrayOfElements=(int*)calloc(width,sizeof(int));
    }*/

    int countOfElementsInTheBin;
    int countSignalForNewBin=0;
    int countForBins=0;
    int remainingElements=numberOfElementsInTheInputArray;
    printf("%d\n",remainingElements);
    int iterator1Track;
    int flag=1;

    //printf("%d\n",width);
    for(int iterator1=0; iterator1<numberOfElementsInTheInputArray; iterator1++)
    {
        //printf("d");
        for(int iterator2=iterator1*widthOfTheBins; iterator2<(iterator1+1)*widthOfTheBins; iterator2++)
        {

            /*if(numberOfElementsInTheInputArray<=iterator2)
            {
                //printf("d");
                break;

            }*/
            if(flag==2){
                iterator2=iterator1;
                flag=1;
            }

         if(countForBins>=binCount)
            {

                break;
            }
            else
            {
                //printf("%d\n",count2);
                //countOfElementsInTheBin=b[countForBins].countOfElements;
                //bin[countForBins].arrayOfElements[countOfElements]=inputArray[iterator2];
                //countOfElementsInTheBin++;
                //bin[countforBins].countOfElementsInTheBin=countOfElementsInTheBin;
                outputArray[iterator2]=countForBins+1;
                iterator1Track=iterator2;
                iterator1=iterator2;
                remainingElements--;
                printf("hello\n");
                countSignalForNewBin++;
            //printf("sds");
                if(countSignalForNewBin>=widthOfTheBins)
                {
                    countSignalForNewBin=0;
                    countForBins++;

                }
            }
        }
          if(numberOfElementsInTheInputArray%binCount!=0 && countForBins==binCount-2){
                printf("%d\n",remainingElements);
                widthOfTheBins=remainingElements;
                 //iterator1=iterator1Track-1;
                 printf("this:%d\n",iterator1);
                 flag=2;
            }
            countSignalForNewBin=0;
    }
   /* for(int iterator1=0; iterator1<binCount; iterator1++)
    {
        for(int iteartor2=0; iterator2<bin[iterator1].countOfElements; iterator2++)
        {
            mexPrintf("%d ",bin[iteartor1].arrayOfElements[iterator2]);
        }
        mexPrintf("\n");
    }*/
    //double *ptr;

   // plhs[0]=mxCreateDoubleMatrix(pots,width,mxREAL);
   // double *pointerForOutput;
    //pointerForOutput=mxGetPr(plhs[0]);
    int outputIndex=0;
    /*for(int iterator1=0; iterator1<binCount; iterator1++)
    {

        for(int iterator2=0; iterator2<b[iterator1].countOfElements; iterator2++)
        {

            pointerForOutput[outputIndex]=bin[iterator1].array[iterator2];
            outputIndex++;
        }
    }*/
    for(int iterator1=0; iterator1<numberOfElementsInTheInputArray; iterator1++)
    {
        printf("%d ",outputArray[iterator1]);
    }


}
