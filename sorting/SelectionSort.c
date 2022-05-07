//Selection sort
#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void SelectionSort(int *arr,int size){
    for(int i=0;i<size;i++){
        int min_index=i;
        for(int j=i;j<size;j++){
            if(*(arr+j)<*(arr+min_index)) min_index=j;
        }
        swap(arr+i,arr+min_index);
    }
}

int main(){
    // input array
    int arr[]={1,8,5,2,31,17};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("Selection sort\n");
    printf("INPUT  : ");
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
    SelectionSort(arr,size);
    printf("OUTPUT : ");
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}