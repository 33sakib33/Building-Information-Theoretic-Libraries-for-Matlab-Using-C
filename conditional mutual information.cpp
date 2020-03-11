#include<bits/stdc++.h>
#include<stdio.h>
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
    for(int iterator1=0; iterator1<sizeOfArray; iterator1++)
        arrayParameter[iterator1]=arrayParameter[iterator1]-minimum;
    long long numberOfStates=maximum-minimum+1;
    return numberOfStates;
}
int main()
{
    double inputArrayX[5]= {0,1,1,0,1};
    double inputArrayY[5]= {1,1,0,1,0};
    double inputArrayZ[5]= {1,0,1,2,1};
    long long lengthOfArray=5;
    long long stateX=countStates(&inputArrayX[0],lengthOfArray);
    long long stateY=countStates(&inputArrayY[0],lengthOfArray);
    long long  stateZ=countStates(&inputArrayZ[0],lengthOfArray);

    double conditionalEntropyXZ=0;
    long long maxState;
    double conditionalEntropyXP=0;
    double mergedArray[lengthOfArray];

    double probabilityX[stateX];
    double probabilityZ[stateZ];

    double **jointProbabilityXY;
    double **jointProbabilityXP;

    jointProbabilityXY= new double*[stateX];

    for(long long iterator1=0; iterator1<stateX; iterator1++)
    {

        jointProbabilityXY[iterator1] = new double[stateY];

    }
    //printf("dsd");
    double **jointProbabilityXZ;
    jointProbabilityXZ= new double*[stateX];

    for(long long iterator1=0; iterator1<stateX; iterator1++)
    {

        jointProbabilityXZ[iterator1] = new double[stateZ];

    }
    double **jointProbabilityYZ;
    jointProbabilityYZ= new double*[stateY];

    for(long long iterator1=0; iterator1<stateY; iterator1++)
    {

        jointProbabilityYZ[iterator1] = new double[stateZ];

    }

    probability(&probabilityZ[0],&inputArrayZ[0],lengthOfArray,stateZ);
    //printf("sdsd");
    //for(int i=0;i<stateX;i++)printf("%f ",probabilityX[i]);
    jointProbability(&inputArrayX[0],&inputArrayZ[0],stateX,stateZ,lengthOfArray,jointProbabilityXZ);
    //printf("m\b");
    //printf("dsd");
    jointProbability(&inputArrayY[0],&inputArrayZ[0],stateY,stateZ,lengthOfArray,jointProbabilityYZ);


    //conditionalEntropyXY=conditionalEntropy(&probabilityX[0],jointProbabilityXY,lengthOfArray,stateX,stateY);
    mergeVariables(jointProbabilityYZ,mergedArray,inputArrayY,inputArrayZ,lengthOfArray,stateY,stateZ);
    maxState=countStates(mergedArray,lengthOfArray);
    double probabilityP[maxState];
    conditionalEntropyXZ=conditionalEntropy(&probabilityZ[0],jointProbabilityXZ,lengthOfArray,stateX,stateZ);

    jointProbabilityXP= new double*[stateX];

    for(long long iterator1=0; iterator1<stateX; iterator1++)
    {

        jointProbabilityXP[iterator1] = new double[maxState];

    }
    jointProbability(&inputArrayX[0],&mergedArray[0],stateX,maxState,lengthOfArray,jointProbabilityXP);


    probability(&probabilityP[0],&mergedArray[0],lengthOfArray,maxState);
    conditionalEntropyXP=conditionalEntropy(&probabilityP[0],jointProbabilityXP,lengthOfArray,stateX,maxState);
    double mutinfo;
    mutinfo=conditionalEntropyXZ-conditionalEntropyXP;

    printf("\n%f",mutinfo);


    return 0;

}
