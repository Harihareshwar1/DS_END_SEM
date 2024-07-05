#include "stdio.h"



void insertionSort(int *arr,int n){
     for(int i = 1;i < n;i++){
        int t = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > t){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = t;
     }
}


int main(){
    int arr[] = {8,3,1,4,5,2,7,6};
    insertionSort(arr,8);
    for(int i = 0;i < 8;i++){
        printf("%4d",arr[i]);
    }
}