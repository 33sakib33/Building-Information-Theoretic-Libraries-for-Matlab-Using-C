#include"mex.h"
#include"matrix.h"
#include<stdio.h>
#include<math.h>

void mergeVariables(double **jointProbability12,double *mergedArray,double* arrayParameter1, double* arrayParameter2,long long arrayLen,long long state1,long long state2)
{
    long long maxState=0;
    long long temp12[state1][state2];
    for(long long iterator1=0; iterator1<state1; iterator1++)
    {
        for(long long iterator2=0; iterator2<state2; iterator2++)
        {
            if(jointProbability12[iterator1][iterator2]!=0)
            {
                maxState++;
                temp12[iterator1][iterator2]=maxState-1;
            }
            else
                temp12[iterator1][iterator2]=-1;

        }
    }
    for(long long iterator1=0; iterator1<arrayLen; iterator1++)
    {
        if(temp12[(int)arrayParameter1[iterator1]][(int)arrayParameter2[iterator1]]!=-1)
            mergedArray[iterator1]=temp12[(int)arrayParameter1[iterator1]][(int)arrayParameter2[iterator1]];
    }

}
double conditionalEntropy(double *probability1,double **probability12,long long arrayLen,long long state1,long long state2)
{
    double returnContdEntropy=0;
    for(long long iterator1=0; iterator1<state1; iterator1++)
    {
        for(long long iterator2=0; iterator2<state2; iterator2++)
        {
            if(probability12[iterator1][iterator2]!=0 && probability1[iterator2]!=0)
                returnContdEntropy=returnContdEntropy+(probability12[iterator1][iterator2]*log(probability12[iterator1][iterator2]/probability1[iterator2]));
        }
    }
    returnContdEntropy=returnContdEntropy/log(2);
    returnContdEntropy=returnContdEntropy*-1;
    return returnContdEntropy;
}
void probability(double* probArray,double *arrayParameter,long long arrayLen,long long state1)
{
    for(long long iterator1=0; iterator1<state1; iterator1++)
    {
        probArray[iterator1]=0;
    }
    for(long long iterator1=0; iterator1<arrayLen; iterator1++)
    {
        long long i=arrayParameter[iterator1];
        probArray[i]++;
    }
    for(long long iterator1=0; iterator1<state1; iterator1++)
    {
        probArray[iterator1]= probArray[iterator1]/arrayLen;
    }
}
void jointProbability(double *arrayParameter1, double *arrayParamter2,long long state1,long long state2,long long arrayLen, double **jointProbability12)
{

    for(long long iterator1=0; iterator1<state1; iterator1++)
    {
        for(long long iterator2=0; iterator2<state2; iterator2++)
        {
            jointProbability12[iterator1][iterator2]=0;

        }
    }


    for(long long iterator1=0; iterator1<arrayLen; iterator1++)
    {
        long long i=arrayParameter1[iterator1];
        long long j=arrayParamter2[iterator1];
        jointProbability12[i][j]++;

    }

    for(long long iterator1=0; iterator1<state1; iterator1++)
    {
        for(long long iterator2=0; iterator2<state2; iterator2++)
        {
            if( jointProbability12[iterator1][iterator2]!=0)
                jointProbability12[iterator1][iterator2]=jointProbability12[iterator1][iterator2]/arrayLen;

        }
    }
}
long long countStates(double *arrayParameter,long long sizeOfArray)
{
    double minimum=arrayParameter[0];
    double maximum=arrayParameter[0];
    for(long long iterator1=0; iterator1<sizeOfArray; iterator1++)
    {
        minimum=(arrayParameter[iterator1]>minimum)?minimum:arrayParameter[iterator1];
        maximum=(arrayParameter[iterator1]<maximum)?maximum:arrayParameter[iterator1];
    }
    for(long long iterator1=0; iterator1<sizeOfArray; iterator1++)
        arrayParameter[iterator1]=arrayParameter[iterator1]-minimum;
    long long numberOfStates=maximum-minimum+1;
    return numberOfStates;
}
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *inputArrayX,*inputArrayY,*inputArrayZ,conditionalEntropyXZ=0,conditionalEntropyXM=0;
    size_t sizeX,sizeY,sizeZ;
    long long lengthOfArrayX,lengthOfArrayY,lengthOfArrayZ,stateX,stateY,stateZ,stateM;
    inputArrayX=mxGetPr(prhs[0]);
    inputArrayY=mxGetPr(prhs[1]);
    inputArrayZ=mxGetPr(prhs[2]);
    sizeX=mxGetNumberOfElements(prhs[0]);
    sizeY=mxGetNumberOfElements(prhs[1]);
    sizeZ=mxGetNumberOfElements(prhs[2]);
    lengthOfArrayX=(long long)sizeX;
    lengthOfArrayY=(long long)sizeY;
    lengthOfArrayZ=(long long)sizeZ;
    //for(int i=0;i<lengthOfArrayX;i++)mexPrintf("%lf ",inputArrayX[i]);
    stateX=countStates(&inputArrayX[0],lengthOfArrayX);
    stateY=countStates(&inputArrayY[0],lengthOfArrayY);
    stateZ=countStates(&inputArrayZ[0],lengthOfArrayZ);
    long long lengthOfArray=lengthOfArrayX;
    double probabilityX[stateX];
    double probabilityZ[stateZ];
    double mergedArray[lengthOfArray];
    double **jointProbabilityXY;
    double **jointProbabilityXM;
    double **jointProbabilityXZ;
    double **jointProbabilityYZ;
    /*
           for(int i=0;i<5;i++){
            mexPrintf("%lf ",inputArrayX[i]);
        }
            mexPrintf("\n");
         for(int i=0;i<5;i++){
            mexPrintf("%lf ",inputArrayY[i]);
        }
         mexPrintf("\n");
         for(int i=0;i<5;i++){
            mexPrintf("%lf ",inputArrayZ[i]);
        }
      */


    jointProbabilityXY= new double*[stateX];

    for(long long iterator1=0; iterator1<stateX; iterator1++)
    {

        jointProbabilityXY[iterator1] = new double[stateY];

    }
    //printf("dsd");

    jointProbabilityXZ= new double*[stateX];

    for(long long iterator1=0; iterator1<stateX; iterator1++)
    {

        jointProbabilityXZ[iterator1] = new double[stateZ];

    }

    jointProbabilityYZ= new double*[stateY];

    for(long long iterator1=0; iterator1<stateY; iterator1++)
    {

        jointProbabilityYZ[iterator1] = new double[stateZ];

    }
    probability(&probabilityZ[0],&inputArrayZ[0],lengthOfArrayZ,stateZ);
    //for(long long i=0;i<stateZ;i++)mexPrintf("%lf ",probabilityZ[i]);
    jointProbability(&inputArrayX[0],&inputArrayZ[0],stateX,stateZ,lengthOfArray,jointProbabilityXZ);
    jointProbability(&inputArrayY[0],&inputArrayZ[0],stateY,stateZ,lengthOfArray,jointProbabilityYZ);
    /*for(int i=0;i<stateX;i++){
        for(int j=0;j<stateZ;j++){
            mexPrintf("%lf ",jointProbabilityXZ[i][j]);
        }
    }*/
    mergeVariables(jointProbabilityYZ,mergedArray,inputArrayY,inputArrayZ,lengthOfArray,stateY,stateZ);
    //for(int i=0;i<lengthOfArray;i++)mexPrintf("%lf ",mergedArray[i]);
    stateM=countStates(mergedArray,lengthOfArray);
    //mexPrintf("%lld ",stateM);
    double probabilityM[stateM];
    conditionalEntropyXZ=conditionalEntropy(&probabilityZ[0],jointProbabilityXZ,lengthOfArray,stateX,stateZ);

    jointProbabilityXM= new double*[stateX];

    for(long long iterator1=0; iterator1<stateX; iterator1++)
    {

        jointProbabilityXM[iterator1] = new double[stateM];

    }
    jointProbability(&inputArrayX[0],&mergedArray[0],stateX,stateM,lengthOfArray,jointProbabilityXM);
    /* for(int i=0;i<stateX;i++){
      for(int j=0;j<stateM;j++){
          mexPrintf("%lf ",jointProbabilityXM[i][j]);
      }
    }*/
    probability(&probabilityM[0],&mergedArray[0],lengthOfArray,stateM);
    //for(long long i=0;i<stateM;i++)mexPrintf("%lf ",probabilityM[i]);
    conditionalEntropyXM=conditionalEntropy(&probabilityM[0],jointProbabilityXM,lengthOfArray,stateX,stateM);

    plhs[0]=mxCreateDoubleMatrix(1,1,mxREAL);
    double *mutualinformation;
    mutualinformation=mxGetPr(plhs[0]);
    *mutualinformation=conditionalEntropyXZ-conditionalEntropyXM;
    //mexPrintf("%lf\n",conditionalEntropyXM);
    //mexPrintf("%lf\n",conditionalEntropyXZ);



}
