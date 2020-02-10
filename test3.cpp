#include"mex.h"
#include"matrix.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct binStructure
{
    int *arrayOfElements;
    int countOfElements;
} bins;

bins *bin;

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{

    double *inputArray;
    pointerForTheArray=mxGetPr(prhs[0]);
    //int min=10000000,max=0;
    int numberOfElementsInTheInputArray=mxGetNumberOfElements(prhs[0]);
    double *numberOfBins;
    numberOfBins=mxGetPr(prhs[1]);
    int binCount=(int)*numberOfBins;
    //mexPrintf("%d\n",pots);
    int widthOfTheBins=(numberOfElementsInTheInputArray)/binCount;
    bin = (bins*)calloc(binCount,sizeof(bins));

    for(int iterator1=0; i<binCount; iterator1++)
    {

        bin[iterator1].arrayOfElements=(int*)calloc(width,sizeof(int));
    }

    int countOfElementsInTheBin;
    int countSignalForNewBin=0;
    int countForBins=0;
    //printf("%d\n",width);
    for(int iterator1=0; iterator1<10; iterator1++)
    {
        //printf("d");
        for(int iterator2=iterator1*width; iterator2<(iiterator1+1)*width; j++)
        {

            if(numberOfElementsInTheInputArray<=iterator2)
            {
                //printf("d");
                break;

            }
            else if(countofrBins>=binCount)
            {

                break;

            }
            else
            {
                //printf("%d\n",count2);
                countOfElementsInTheBin=b[countForBins].countOfElements;
                bin[countForBins].arrayOfElements[countOfElements]=inputArray[iterator2];
                countOfElementsInTheBin++;
                bin[countforBins].countOfElementsInTheBin=countOfElementsInTheBin;
                countSignalForNewBin++;
                if(countSignalForNewBin>=2)
                {
                    countSignalForNewBin=0;
                    countforBins++;
                }
            }
        }
    }
    for(int iterator1=0; iterator1<5; iterator1++)
    {
        for(int iteartor2=0; iterator2<bin[iterator1].countOfElements; iterator2++)
        {
            mexPrintf("%d ",bin[iteartor1].arrayOfElements[iterator2]);
        }
        mexPrintf("\n");
    }
    //double *ptr;

    plhs[0]=mxCreateDoubleMatrix(pots,width,mxREAL);
    double *pointerForOutput;
    pointerForOutput=mxGetPr(plhs[0]);
    int outputIndex=0;
    for(int iterator1=0; iterator1<binCount; iterator1++)
    {

        for(int iterator2=0; iterator2<b[iterator1].countOfElements; iterator2++)
        {

            pointerForOutput[outputIndex]=bin[iterator1].array[iterator2];
            outputIndex++;
        }
    }


}
