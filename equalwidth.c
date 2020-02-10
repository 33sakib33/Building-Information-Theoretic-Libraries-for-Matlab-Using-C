#include<stdio.h>
typedef struct bins{
    int *array;
    int count;
}bin;
bin *b;
int main(){

    int a[10]={6,14,18,23,25,33,35,43,47,48};
    int min=10000000,max=0;
    int k=3;
    int width=(10)/k;
    b = (bin*)calloc(k,sizeof(bin));
    for(int i=0;i<k;i++){
        b[i].array=(int*)calloc(width,sizeof(int));
    }
    int count;
    int count1=0;
    int count2=0;
    for(int i=0;i<10;i++){
            //printf("d");
        for(int j=i*width;j<(i+1)*width;j++){
            if(10<=j){
                //printf("d");
                break;

            }
            else if(count2>=k){
                break;
            }
            else{
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
            printf("%d ",b[i].array[j]);
        }
        printf("\n");
    }
}
