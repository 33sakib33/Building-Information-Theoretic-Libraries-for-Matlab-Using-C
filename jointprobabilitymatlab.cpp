#include"mex.h"
#include"matrix.h"
#include<bits/stdc++.h>

double Entropy(double *probarray,int sizeOfArray){
    double H;
    for(int itr1=0;itr1<sizeOfArray;itr1++){
       H=H-probarray[itr1]*log(probarray[itr1]);
    }
    H=H/log(2);
    return H;
}

void jointProbability(long long *arrayParameter1,
                      long long *arrayParamter2,long long state1,long long state2,
                      long long arrayLen, double **jointProbability12)

                      {

    for(long long iterator1=0;iterator1<state1;iterator1++){
        for(long long iterator2=0;iterator2<state2;iterator2++){
          jointProbability12[iterator2][iterator1]=0;

        }
    }


    for(long long iterator1=0;iterator1<arrayLen;iterator1++){
            long long i=arrayParameter1[iterator1];
            long long j=arrayParamter2[iterator1];
            jointProbability12[j][i]++;

    }

     for(long long iterator1=0;iterator1<state1;iterator1++){
        for(long long iterator2=0;iterator2<state2;iterator2++){
                if( jointProbability12[iterator2][iterator1]!=0)
          jointProbability12[iterator2][iterator1]=jointProbability12[iterator2][iterator1]/arrayLen;

        }
    }
}
long long countStates(long long *arrayParameter,long long sizeOfArray)
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

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
     double *tX;
    double *tY;

    tX=mxGetPr(prhs[0]);
    tY=mxGetPr(prhs[1]);
    long long lengthOfArray=mxGetNumberOfElements(prhs[0]);
    long long *inputArrayX=new long long[lengthOfArray] ;
    long long *inputArrayY=new long long[lengthOfArray] ;
    for(int i=0;i<lengthOfArray;i++){
        inputArrayX[i]=tX[i];
        inputArrayY[i]=tY[i];
    }
    long long tempStateX=0;
    long long tempStateY=0;
    if (nrhs>=3)
    {
        long long MGL = (long long) mxGetScalar(prhs[2]);
        tempStateY = tempStateX = MGL;
    }
    long long stateX=countStates(inputArrayX,lengthOfArray);
    long long  stateY=countStates(inputArrayY,lengthOfArray);
    stateX=(stateX>tempStateX)?stateX:tempStateX;
    stateY=(stateY>tempStateY)?stateY:tempStateY;
    double **jointProbabilityXY = new double* [stateY];
    //jointProbabilityXY=new double*[stateX];
    plhs[0]=mxCreateDoubleMatrix(stateX,stateY,mxREAL);
    double * temp=mxGetPr(plhs[0]);
    for(int iterator1=0;iterator1<stateY;iterator1++){

        jointProbabilityXY[iterator1] = temp+(long long)iterator1*stateX;

    }
    plhs[1] = mxCreateDoubleMatrix(stateX,1,mxREAL);
    plhs[2] = mxCreateDoubleMatrix(stateY,1,mxREAL);
    double *probabilityX=mxGetPr(plhs[1]);
    double *probabilityY=mxGetPr(plhs[2]);
    memset(probabilityX,0,sizeof(probabilityX));
    memset(probabilityY,0,sizeof(probabilityY));

    //double jointProbabilityXY[stateX][stateY];
   /* for(int i=0;i<stateX;i++){
        for(int j=0;j<stateY;j++){
            jointProbabilityXY[i][j]=0;
        }
    }
    for(int i=0;i<lengthOfArray;i++){
        int a=inputArrayX[i];
        int b=inputArrayY[i];
        jointProbabilityXY[a][b]++;
    }
    for(int i=0;i<stateX;i++){
        for(int j=0;j<stateY;j++){
            jointProbabilityXY[i][j]/=lengthOfArray;
        }
    }*/
    jointProbability(&inputArrayX[0],&inputArrayY[0],stateX,stateY,lengthOfArray,jointProbabilityXY);
   /* for(int i=0;i<stateX;i++){
        for(int j=0;j<stateY;j++){
            mexPrintf("%f ",jointProbabilityXY[j][i]);
        }
        mexPrintf("\n");
    }*/
    for(int iterator1=0;iterator1<stateX;iterator1++){
        for(int iterator2=0;iterator2<stateY;iterator2++){
            probabilityX[iterator1]+=jointProbabilityXY[iterator2][iterator1];
        }
    }
    for(int iterator1=0;iterator1<stateX;iterator1++){
        for(int iterator2=0;iterator2<stateY;iterator2++){
            probabilityY[iterator2]+=jointProbabilityXY[iterator2][iterator1];
        }
    }

  if (jointProbabilityXY) {delete []jointProbabilityXY;}
  //if (inputArrayX) delete []inputArrayX;
 // if (inputArrayY) delete []inputArrayY;
    return;
}
