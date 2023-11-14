#include <stdio.h>
void print(int arr[], int size);
int insert(int arr[], int size, int val, int pos);
int delete(int arr[], int size, int pos);
void LSearch(int arr[], int size, int val);
void BSearch(int arr[], int size, int val);

void main(){
    int array[15] = {1,2,3,4,5,6,7,8,9,10};
    delete(array, 10, 5);
    // LSearch(array, 10, 5);
    print(array, 9);
    BSearch(array, 9, 4);
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
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

void LSearch(int arr[], int size, int val){
    for(int i = 0; i <= size; i++){
        if(arr[i] == val)
         printf("Item found at %d",i);
    }
}

void BSearch(int arr[], int size, int val){
    int L = 0, U = size;
    while (L <= U)
    {
        int Mid = (L+U)/2;
        if(arr[Mid] == val){
        printf("\nItem found at %d",Mid+1);
        return;
        }
        if(val > Mid)
            L = Mid + 1;    
        else
            U = Mid - 1;
    }
    
}