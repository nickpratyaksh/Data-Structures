#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

void display(struct stack *stack);
void push(struct stack **top, int data);
void pop(struct stack **top);

int main()
{
    struct stack stack;
    stack.data = 1;
    stack.next = NULL;
    struct stack *top = &stack;

    push(&top, 2);
    // pop(&top);
    display(top);

    return 0;
}

void display(struct stack *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void push(struct stack **top, int data)
{
    struct stack *ptr = *top;
    struct stack *new = (struct stack *)malloc(sizeof(struct stack));
    new->data = data;
    new->next = ptr;
    *top = new;
}

void pop(struct stack **top)
{
    struct stack *ptr = *top;
    *top = ptr->next;
}