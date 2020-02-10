#include"mex.h"
#include"matrix.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct bins{
    int *array;
    int count;
}bin;
bin *b;
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){

    double *a;
    a=mxGetPr(prhs[0]);
    int min=10000000,max=0;
    int n=mxGetNumberOfElements(prhs[0]);
    double *k;
    k=mxGetPr(prhs[1]);
    int pots=(int)*k;
    mexPrintf("%d\n",pots);
    int width=(n)/pots;
    b = (bin*)calloc(pots,sizeof(bin));
    for(int i=0;i<pots;i++){
        b[i].array=(int*)calloc(width,sizeof(int));
    }
    int count;
    int count1=0;
    int count2=0;
    //printf("%d\n",width);
    for(int i=0;i<10;i++){
            //printf("d");
        for(int j=i*width;j<(i+1)*width;j++){
            if(10<=j){
                //printf("d");
                break;

            }
            else if(count2>=pots){
                break;
            }
            else{
                //printf("%d\n",count2);
                count=b[count2].count;
                b[count2].array[count]=a[j];
                count++;
                b[count2].count=count;
                count1++;
                if(count1>=2){
                    count1=0;
                    count2++;
                }
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<b[i].count;j++){
            mexPrintf("%d ",b[i].array[j]);
        }
        mexPrintf("\n");
    }
    //double *ptr;
    
    plhs[0]=mxCreateDoubleMatrix(pots,width,mxREAL);
    double *ptr2;
    ptr2=mxGetPr(plhs[0]);
        count=0;
       for(int i=0;i<pots;i++){
        for(int j=0;j<b[i].count;j++){
            ptr2[count]=b[i].array[j];
            count++;   
        }
    }
    
    
}
