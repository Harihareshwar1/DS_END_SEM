#include "stdio.h"
#include "string.h"
#define N 10

char keys[N][30];

int values[N];


int getIndex(char key[]){
       for(int i = 0;i< N;i++){
        if(strcmp(keys[i],key)==0){
            return i;
        }
       }
       return -1;
}



int get_value(char key[]){
    if(getIndex(key)!=-1){
        return values[getIndex(key)];
    }
    else{
        printf("Key not found\n");
        return -1000;
    }
}

int counter = 0;
void insert(char key[],int value){
if(getIndex(key)!=-1){
    values[getIndex(key)] = value;
}
    else{
        strcpy(keys[counter],key);
        values[counter] = value;
        counter++;
    }
}


int main(){


    insert("hari",10);
    printf("%d",get_value("hari"));
}