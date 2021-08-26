#include"mex.h"
#include"matrix.h"
#include<bits/stdc++.h>

void findMinAndMax(double *minP,double *maxP,double *arrayParameter,int lengthOfArray)
{
    double min1=*minP;
    double max1=*maxP;
    for(int iterator1=1; iterator1<lengthOfArray; iterator1++)
    {
        if(arrayParameter[iterator1]>max1)
            max1=arrayParameter[iterator1];
        if(arrayParameter[iterator1]<min1)
            min1=arrayParameter[iterator1];
    }
    *maxP=max1;
    *minP=min1;
}
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if(nrhs!=2) mexErrMsgTxt("invalid input");
    double *inputArray;
    inputArray=mxGetPr(prhs[0]);
    double numberOfBins=mxGetScalar(prhs[1]);
    int numberOfElementsInTheArray=mxGetNumberOfElements(prhs[0]);
    double max1=inputArray[0];
    double min1=inputArray[0];
    findMinAndMax(&min1,&max1,inputArray,numberOfElementsInTheArray);
    /*for(int i=1;i<numberOfElementsInTheArray;i++){
        double temp=inputArray[i];
        if(min1>temp)min1=temp;
        else if(max1<temp)max1=temp;
    }*/
    double width=(max1-min1)/numberOfBins;
    int discretizationLevel;
    plhs[0]=mxCreateDoubleMatrix(numberOfElementsInTheArray,1,mxREAL);
    double *outputArray;
    double discretizationLevelt;
    outputArray=mxGetPr(plhs[0]);
    bool flag1[(int)numberOfBins+65];
    memset(flag1,false,sizeof flag1);
    double df=0;
    double eps;
   // int* mark = new int[numberOfBins+1];
   // memset(mark,0,sizeof mark);
    for(int iterator1=0; iterator1<numberOfElementsInTheArray; iterator1++)
    {
        if(inputArray[iterator1]==min1){outputArray[iterator1]=1;}
        else if(inputArray[iterator1]==max1){outputArray[iterator1]=(int)numberOfBins;}
        else
        {
            //discretizationLevel=(int )((inputArray[iterator1]-min1)/width);
            discretizationLevelt=(inputArray[iterator1]-min1);
            discretizationLevel=(int)(discretizationLevelt/width+1);
            //double positionComparartor=(int)discretizationLevel+1;

            eps = (discretizationLevelt) - (discretizationLevel*width);
            if(eps>(discretizationLevel-1)*0.0000000001) discretizationLevel = discretizationLevel+1;
            outputArray[iterator1]=(double)discretizationLevel;
        }

    }
    if(nlhs>1){
            if(flag1[discretizationLevel]==false){
                df++;
                flag1[discretizationLevel]=true;
            }
            plhs[1] = mxCreateDoubleMatrix(1,1,mxREAL);
            double *dfpp = mxGetPr(plhs[1]);
            dfpp[0] = df;
            }
    return;

    /*for(int iterator1=0;iterator1<numberOfElementsInTheArray;iterator1++){
        printf(" %d",outputArray[iterator1]);
    }*/


}

/*void mexFunction(int nlhs,mxArray *plhs[],int nrhs,const mxArray *prhs[])
{
    //input:
    //prhs[0] = features
    //prhs[1] = the number of quantization

    //output:
    //plhs[0] = discritized value
    //plhs[1] = degres of fredom(unique value)

    if(nrhs!=2) mexErrMsgTxt("invalid input");

    double *pt2 = mxGetPr(prhs[0]),*pt1;
    double minVal=pt2[0],maxVal = pt2[0],step,Q,temp;
    int lenght = mxGetNumberOfElements(prhs[0]);

    for(int i=1; i<lenght; i++)
    {
        temp = pt2[i];
        if(temp<minVal) minVal = temp;
        else if(temp>maxVal) maxVal = temp;
    }

    Q = mxGetScalar(prhs[1]);
    step = (maxVal-minVal)/Q;

    plhs[0] = mxCreateDoubleMatrix(lenght,1,mxREAL);
    pt1 = mxGetPr(plhs[0]);
    double disVal,secondDis;
    int* mark = new int[(int)Q+1];
    int pos;
    double doublePos,uniq=0;
    for(int i=0; i<=Q; i++) mark[i]=0;
    for(int i=0; i<lenght; i++)
    {
        if(pt2[i]==minVal) pos = 1;
        else if(pt2[i]==maxVal) pos = (int)Q;
        else
        {
            disVal = pt2[i] - minVal;
            pos = (int)(disVal/step + 1);
//             doublePos = disVal/step;
//             if(pos==doublePos) pos++;
            secondDis = disVal - (pos*step);
            if(secondDis>(pos-1)*0.0000000001) pos = pos+1;
        }
        pt1[i] = (double)(pos);

        if(nlhs>1) //calculate degrees of fredom
        {

                if(mark[pos]==0)
                {
                    uniq++;
                    mark[pos]=1;
                }

            plhs[1] = mxCreateDoubleMatrix(1,1,mxREAL);
            double *p = mxGetPr(plhs[1]);
            p[0] = uniq;
        }
    }
}*/

