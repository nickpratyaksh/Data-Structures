#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print(struct node *head);
void insert(struct node **head, int data, int pos);
void delete(struct node **head, int data);

int main()
{
    struct node one;
    struct node *head = &one;
    one.data = 1;
    one.next = NULL;
    insert(&head,2, 1);
    delete(&head, 1);
    print(head);

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

void insert(struct node **head, int data, int pos)
{
    struct node *ptr = *head;
    while (ptr->data != pos)
        ptr = ptr->next;

    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = ptr->next;
    ptr->next = new;
}

void delete(struct node **head, int data)
{
    struct node *ptr = *head;
    if (ptr->data == data)
    {
        *head = ptr->next;
        free(ptr);
    }
    else
    {
        while (ptr->next->data != data)
            ptr = ptr->next;
        struct node *tmp = ptr->next;
        ptr->next = ptr->next->next;
        free(tmp);
    }
}