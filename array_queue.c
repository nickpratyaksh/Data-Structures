#include <stdio.h>

struct queue
{
    int queue[10];
    int front, rear;
};

void display(struct queue *queue);
void enqueue(struct queue *queue, int data);
void dequeue(struct queue *queue);

int main()
{
    struct queue queue;
    queue.front = 0;
    queue.rear = -1;

    // enqueue(&queue, 1);
    // dequeue(&queue);
    display(&queue);

    return 0;
}

void display(struct queue *queue)
{
    for (int i = queue->front; i <= queue->rear; i++)
        printf("%d\n", queue->queue[i]);
}

void enqueue(struct queue *queue, int data)
{
    queue->queue[++queue->rear] = data;
}

void dequeue(struct queue *queue)
{
    queue->front++;
}