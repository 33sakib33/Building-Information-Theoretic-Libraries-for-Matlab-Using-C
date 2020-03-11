#include<bits/stdc++.h>
using namespace std;
void jointProbability(double *arrayParameter1, double *arrayParamter2,long long state1,long long state2,long long arrayLen, double **jointProbability12){

    for(long long iterator1=0;iterator1<state1;iterator1++){
        for(long long iterator2=0;iterator2<state2;iterator2++){
          jointProbability12[iterator1][iterator2]=0;

        }
    }


    for(long long iterator1=0;iterator1<arrayLen;iterator1++){
            long long i=arrayParameter1[iterator1];
            long long j=arrayParamter2[iterator1];
            jointProbability12[i][j]++;

    }

     for(long long iterator1=0;iterator1<state1;iterator1++){
        for(long long iterator2=0;iterator2<state2;iterator2++){
                if( jointProbability12[iterator1][iterator2]!=0)
          jointProbability12[iterator1][iterator2]=jointProbability12[iterator1][iterator2]/arrayLen;

        }
    }
}

void mergeVariables(double **jointProbability12,double *mergedArray,double* arrayParameter1, double* arrayParameter2,long long arrayLen,long long state1,long long state2){
        long long maxState=0;
        long long temp12[state1][state2];
        for(long long iterator1=0;iterator1<state1;iterator1++){
            for(long long iterator2=0;iterator2<state2;iterator2++){
                if(jointProbability12[iterator1][iterator2]!=0){
                    maxState++;
                    temp12[iterator1][iterator2]=maxState;
                }
                else temp12[iterator1][iterator2]=-1;

            }
        }
        for(long long iterator1=0;iterator1<arrayLen;iterator1++){
                //if(temp12[(int)arrayParameter1[iterator1]][(int)arrayParameter2[iterator1]]!=-1)
            mergedArray[iterator1]=temp12[(int)arrayParameter1[iterator1]][(int)arrayParameter2[iterator1]];
        }

}
long long countStates(double *arrayParameter,long long sizeOfArray){
    double minimum=arrayParameter[0];
    double maximum=arrayParameter[0];
    for(long long iterator1=0;iterator1<sizeOfArray;iterator1++){
        minimum=(arrayParameter[iterator1]>minimum)?minimum:arrayParameter[iterator1];
        maximum=(arrayParameter[iterator1]<maximum)?maximum:arrayParameter[iterator1];
    }
    for(int iterator1=0;iterator1<sizeOfArray;iterator1++) arrayParameter[iterator1]=arrayParameter[iterator1]-minimum;
    long long numberOfStates=maximum-minimum+1;
    return numberOfStates;
}
int main(){
    double state;
    double inputArrayY[5]={1,1,0,1,0};
    double inputArrayZ[5]={1,0,1,2,1};
    long long lengthOfArray=5;
    long long stateY=3;
    long long  stateZ=3;
    double **jointProbabilityYZ;
     jointProbabilityYZ= new double*[stateY];

    for(long long iterator1=0;iterator1<stateY;iterator1++){

        jointProbabilityYZ[iterator1] = new double[stateZ];

    }
    double mergedArray[5];
    jointProbability(&inputArrayY[0],&inputArrayZ[0],stateY,stateZ,lengthOfArray,jointProbabilityYZ);

    mergeVariables(jointProbabilityYZ,mergedArray,inputArrayY,inputArrayZ,lengthOfArray,stateY,stateZ);
        state=countStates(mergedArray,lengthOfArray);
    for(int i=0;i<5;i++){
        cout<<mergedArray[i]<<" ";
    }
    cout<<endl<<state;
}
