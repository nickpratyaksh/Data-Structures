#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void print(struct node *ptr);
void printReverse(struct node *ptr);
void insert(struct node **head, int data, int pos, struct node **tail);
void delete(struct node **head, int data, struct node **tail);

int main()
{
    struct node node;
    node.data = 1;
    node.prev = NULL;
    node.next = NULL;
    struct node *head = &node;
    struct node *tail = &node;
    insert(&head, 2, 1, &tail);
    // delete (&head, 2, &tail);
    print(head);
    printf("------------------------\n");
    printReverse(tail);

    return 0;
}

void print(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void printReverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->prev;
    }
}

void insert(struct node **head, int data, int pos, struct node **tail)
{
    struct node *ptr = *head;
    while (ptr->data != pos)
        ptr = ptr->next;

    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = ptr->next;
    new->prev = ptr;
    ptr->next = new;
    if (new->next == NULL)
        *tail = new;
    else
        new->next->prev = new;
}

void delete(struct node **head, int data, struct node **tail)
{
    struct node *ptr = *head;
    if (ptr->data == data)
    {
        ptr->next->prev = NULL;
        *head = ptr->next;
        free(ptr);
    }
    else
    {
        while (ptr->next->data != data)
            ptr = ptr->next;
        struct node *tmp = ptr->next;
        ptr->next = ptr->next->next;
        if (ptr->next == NULL)
            *tail = ptr;
        else
            ptr->next->prev = ptr;
        free(tmp);
    }
}