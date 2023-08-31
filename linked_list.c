#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};

void print(struct node *head);
void insert(struct node **head, int data);


void main(){
    struct node one;
    struct node two;
    struct node three;
    struct node *head = &one;
    one.data = 1;
    one.next = &two;
    two.data = 2;
    two.next = &three;
    three.data = 3;
    three.next = NULL;

    insert(&head, 8);
    print(head);

}

void print(struct node *ptr){

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void insert(struct node **head, int data){

    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = *head;
    *head = new;
}
