//Merge sort
#include<stdio.h>

void printarr(int *arr,int size){
	for(int i=0;i<size;i++)
		printf("%d ",*(arr+i));
}

void MergeSort(int *arr,int l,int r){
    if(r-l<1)return;
    int m=(l+r)/2;
    MergeSort(arr,l,m);
    MergeSort(arr,m+1,r);
    int temp[r-l+1];
    int lm=l,mr=m+1;
    int i=0;
    for(i=0;i<r-l+1;i++){
        if(lm>m||mr>r)break;
        if(*(arr+lm)<*(arr+mr)){
            temp[i]=*(arr+lm);
            lm++;
        }
        else{
            temp[i]=*(arr+mr);
            mr++;
        }
    }
    if(lm!=m+1){
        for(i;i<r-l+1;i++){
            temp[i]=*(arr+lm);
            lm++;
        }
    }
    else{
        for(i;i<r-l+1;i++){
            temp[i]=*(arr+mr);
            mr++;
        }
    }
    for(int i=0;i<r-l+1;i++){
        *(arr+l+i)=temp[i];
    }
}

int main(){
    // input array
    int arr[]={1,8,5,2,31,17};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("Merge sort\n");
    printf("INPUT  : ");
    printarr(arr,size);
    printf("\n");
    MergeSort(arr,0,size-1);
    printf("OUTPUT : ");
    printarr(arr,size);
    printf("\n");
    return 0;
}
