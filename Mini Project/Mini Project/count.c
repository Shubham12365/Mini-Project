#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
void countSort(int a[],int n){
    int max=INT_MIN;
    int i,j;
    for(i=0;i<n;i++){
      if(max<a[i]){
         max=a[i]; 
      }
    }
    int *count=(int *)malloc((max+1)*sizeof(int));
    //count[max+1]={0};
    for(i=0;i<max+1;i++){
      count[i]=0;
    }
    for( i=0;i<n;i++){
      count[a[i]]=count[a[i]]+1;
    }
    i=0;j=0;
    while (i<=max)
    {
        if(count[i]>0){
            a[j]=i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
    }
    
}

void printArr(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    
    int a[]={9,1,4,14,4,15,6};
    int n=7;
    printArr(a,n);
    countSort(a,n);
    printArr(a,n);

return 0;
}
