#include <stdio.h>
int insert(int arr[], int size, int val, int pos);
int delete(int arr[], int size, int pos);


void main(){
    int array[15] = {1,2,3,4,5,6,7,8,9,10};
    delete(array, 10, 5);

    for (int i = 0; i < 13; i++)
        printf("%d\n",array[i]);
}

int insert(int arr[], int size, int val, int pos){
    for(int i = size; i >= pos; i--){
        arr[i+1] = arr[i];
    }
    arr[pos]=val;
    return arr[size];
}

int delete(int arr[], int size, int pos){
    for (int i = pos-1; i < size; i++)
    {
        arr[i] = arr[i+1];
    }
    return arr[size];
    
}