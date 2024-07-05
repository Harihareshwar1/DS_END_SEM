#include "stdio.h"

int helper(int arr[],int start,int end){
    int temp = arr[end];
    int swap;
    int i = start -1;
    for(int j = start;j <=end-1;j++){
         if(arr[j] <=temp){
            i++;
            swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
         }
    }
    i++;
     swap = arr[i];
     arr[i] = temp;
     arr[end] = swap;
    
    return i;
}

void quick(int *arr,int start,int end){
     if(end<=start) return;
     int pivot = helper(arr,start,end);
     quick(arr,start,pivot-1);
     quick(arr,pivot+1,end);
      
}





int main(){
    int arr[] = {8,3,1,4,5,2,7,6};
    quick(arr,0,7);
    for(int i = 0;i < 8;i++){
        printf("%4d",arr[i]);
    }
}