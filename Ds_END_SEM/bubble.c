#include "stdio.h"



void bubbleSort(int *arr,int n){
      for(int i = 0;i < n;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
      }
}


int main(){
    int arr[] = {8,3,1,4,5,2,7,6};
    bubbleSort(arr,8);
    for(int i = 0;i < 8;i++){
        printf("%4d",arr[i]);
    }
}