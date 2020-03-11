#include<bits/stdc++.h>
using namespace std;

void jointProbability(double *arrayParameter1, double *arrayParamter2,long state1,long state2,long arrayLen, double **jointProbability12){

    for(int iterator1=0;iterator1<state1;iterator1++){
        for(int iterator2=0;iterator2<state2;iterator2++){
          jointProbability12[iterator1][iterator2]=0;

        }
    }


    for(int iterator1=0;iterator1<arrayLen;iterator1++){
            int i=arrayParameter1[iterator1];
            int j=arrayParamter2[iterator1];
            jointProbability12[i][j]++;

    }

     for(int iterator1=0;iterator1<state1;iterator1++){
        for(int iterator2=0;iterator2<state2;iterator2++){
                if( jointProbability12[iterator1][iterator2]!=0)
          jointProbability12[iterator1][iterator2]=jointProbability12[iterator1][iterator2]/arrayLen;

        }
    }
}

int main(){
     double inputArrayX[9]={0,1,1,0,1,3,4,1,2};
    double inputArrayY[9]={0,1,3,2,1,2,3,1,2};
    long lengthOfArray=9;
     long stateX=5;
    long stateY=4;
    double **jointProbabilityXY;
    jointProbabilityXY=new double*[stateX];

    for(int iterator1=0;iterator1<stateX;iterator1++){

        jointProbabilityXY[iterator1] = new double[stateY];

    }
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
    for(int i=0;i<stateX;i++){
        for(int j=0;j<stateY;j++){
            cout<<jointProbabilityXY[i][j]<<"    ";
        }
        cout<<endl;
    }
}
