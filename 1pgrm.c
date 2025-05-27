#include <stdio.h>

int partition(int a[],int low,int high)
{
    int pivot=a[low],i=low+1,j=high,temp;
    while(i<=j){
        while(i<=high&&a[i]<=pivot) i++;
         while(a[j]>pivot) j--;
        if(i<j){
           temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            
        }
    }
    a[low]=a[j];
    a[j]=pivot;
    return j;
}

    void quicksort(int a[],int low,int high){
        if(low<high){
int p=partition(a,low,high);
        
            quicksort(a,low,p-1);
            quicksort(a,p+1,high);
        }    // Your code here!
    
}
int main(){
int a[100],n;
printf("enter the number of ele\n");
scanf("%d",&n);
printf("enter the %d elements\n",n);
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
quicksort(a,0,n-1);
printf("sorted\n");
for(int i=0; i<n; i++)
printf("%d ", a[i]);
printf("\n");
}
