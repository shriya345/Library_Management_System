#include<stdio.h>
void merge(int a[],int low,int mid,int high){
    int b[100],i=low,j=mid+1,k=low;
    while(i<=mid && j<=high) 
    b[k++]= (a[i]<a[j]) ? a[i++]:a[j++];
    while(i<=mid)
    b[k++]= a[i++];
    while(j<=high)
     b[k++]=a[j++];
    for(i=low;i<=high;i++){
        a[i]=b[i];
    }
}
void mergesort(int a[],int low,int high){  
  
        int mid=(low+high)/2;
          if(low < high){
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
        
    }
}




int main() {
    int n, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergesort(a, 0, n - 1);

    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
