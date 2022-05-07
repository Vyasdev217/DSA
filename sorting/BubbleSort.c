//Bubble sort
#include<stdio.h>

void swap(int *a,int *b){
	int temp=*b;
	*b=*a;
	*a=temp;
}

void printarr(int *arr,int size){
	for(int i=0;i<size;i++)
		printf("%d ",*(arr+i));
}

void BubbleSort(int *arr,int size){
	for(int i=0;i<size;i++){
		for(int j=size-1;j>i;j--){
			if(*(arr+j)<*(arr+j-1))
				swap(arr+j,arr+j-1);
		}
	}
}

int main(){
    // input array
    int arr[]={1,8,5,2,31,17};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("Bubble sort\n");
    printf("INPUT  : ");
    printarr(arr,size);
    printf("\n");
    BubbleSort(arr,size);
    printf("OUTPUT : ");
    printarr(arr,size);
    printf("\n");
    return 0;
}
