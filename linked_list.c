#include <stdio.h>

struct linked_list
{
    int data;
    struct linked_list next;
};


void main(){
    struct linked_list one;
    struct linked_list two;
    struct linked_list three;
    struct linked_list head = one;
    one.data = 1;
    one.next = two;
    two.data = 2;
    two.next = three;
    three.data = 3;
    three.next = NULL;

    struct linked_list ptr = head;
    
    while(ptr != NULL){
        printf("%d", ptr.data);
        ptr = ptr.next;
    }

}