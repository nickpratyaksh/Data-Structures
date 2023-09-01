#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};

void print(struct node *head);
void insertStart(struct node **head, int data);
void insertEnd(struct node *ptr, int data);
void insertMiddle(struct node *ptr, int data, int pos);
void deleteStart(struct node **head);


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

    insertMiddle(head,9, 2);
    deleteStart(&head);
    print(head);

}

void print(struct node *ptr){

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void insertStart(struct node **head, int data){

    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = *head;
    *head = new;
}

void insertEnd(struct node *ptr, int data){
    while(ptr->next != NULL)
        ptr = ptr->next;

    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    ptr->next = new;
}

void insertMiddle(struct node *ptr, int data, int pos){
    while(ptr->data != pos)
        ptr = ptr->next;

    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = ptr->next;
    ptr->next = new;
}

void deleteStart(struct node **head){
    struct node *ptr = *head;
    *head = ptr->next;
    free(ptr);
}