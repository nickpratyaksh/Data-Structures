#include <stdio.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void print(struct node *head);
void insertStart(struct node **head, int data);
void insertEnd(struct node *ptr, int data);
void insertMiddle(struct node *ptr, int data, int pos);
void deleteStart(struct node **head);
void deleteEnd(struct node *ptr);
void deleteMiddle(struct node *ptr, int data);


void main(){
    struct node one, two, three;
    struct node *head = &one;
    one.data = 1;
    one.prev = NULL;
    one.next = &two;
    two.data = 2;
    two.prev = &one;
    two.next = &three;
    three.data = 3;
    three.prev = &two;
    three.next = NULL;

    // insertMiddle(head,9, 2);
    // deleteStart(&head);
    // deleteEnd(head);
    insertEnd(head,4);
    insertEnd(head,5);
    // insertEnd(head,6);
    deleteMiddle(head,3);
    print(head);

}

void print(struct node *ptr){

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void insertStart(struct node **head, int data){
    struct node *ptr = *head;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = *head;
    new->prev = NULL;
    ptr->prev = new;
    *head = new;
}

void insertEnd(struct node *ptr, int data){
    while(ptr->next != NULL)
        ptr = ptr->next;

    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    new->prev = ptr;
    ptr->next = new;
}

void insertMiddle(struct node *ptr, int data, int pos){
    while(ptr->data != pos)
        ptr = ptr->next;

    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = ptr->next;
    new->prev = ptr;
    ptr->next = new;
}

void deleteStart(struct node **head){
    struct node *ptr = *head;
    ptr->next->prev = NULL;
    *head = ptr->next;
    free(ptr);

}

void deleteEnd(struct node *ptr){
    while(ptr->next->next != NULL)
        ptr = ptr->next;
        free(ptr->next);
        ptr->next = NULL;
}

void deleteMiddle(struct node *ptr, int data){
    while(ptr->next->data != data)
        ptr = ptr->next;
        struct node *tmp = ptr->next;
        ptr->next = ptr->next->next;
        ptr->next->prev = ptr;
        free(tmp);
}