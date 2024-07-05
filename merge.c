#include<stdio.h>
#include<stdlib.h>

#include<time.h>

void merge(int a[], int low,int mid, int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int b[high];
    int p;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
            i++;
            k++;
    }
    while(j<=high){
        b[k]=a[j];
            j++;
            k++;
    }
    for(p=low;p<=high;p++){
        a[p]=b[p];
    }
}
void ms(int a[],int low, int high){
    if(low<high){
    int mid = (low+high)/2;
    ms(a,low,mid);
    ms(a,mid+1,high);
    merge(a,low,mid,high);
    }
}
int main(){
    int max;
    int i;
    clock_t begin,end;
    printf("Enter the number of elements: ");
    scanf("%d",&max);
    int a[max];
    for(i=0;i<=max-1;i++){
        a[i]=rand() %max+1;
    }
    begin=clock();
   
    ms(a,0,max-1);
    end=clock();
    float t=((float)end-begin)/CLOCKS_PER_SEC;
	printf("\nThe time taken is %f",t);
    /*for(i=0;i<=max-1;i++){
        printf("\t%d",a[i]);
    }*/
    return 0;
}
