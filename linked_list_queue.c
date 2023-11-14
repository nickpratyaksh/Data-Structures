#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};

void display(struct queue *ptr);
void enqueue(struct queue **rear, int data);
void dequeue(struct queue **front);

int main()
{
    struct queue queue;
    queue.data = 1;
    queue.next = NULL;
    struct queue *front = &queue;
    struct queue *rear = &queue;

    enqueue(&rear, 2);
    dequeue(&front);
    display(front);

    return 0;
}

void display(struct queue *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(struct queue **rear, int data)
{
    struct queue *ptr = *rear;
    struct queue *new = (struct queue *)malloc(sizeof(struct queue));
    new->data = data;
    new->next = NULL;
    ptr->next = new;
    *rear = new;
}

void dequeue(struct queue **front)
{
    struct queue *ptr = *front;
    *front = ptr->next;
}