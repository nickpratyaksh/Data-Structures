#include <stdio.h>

struct stack
{
    int stack[10];
    int top;
};

void display(struct stack *stack);
void push(struct stack *stack, int data);
void pop(struct stack *stack);

int main()
{
    struct stack stack;
    stack.top = -1;
    push(&stack, 1);
    // pop(&stack);
    display(&stack);

    return 0;
}

void display(struct stack *stack)
{
    for (int i = stack->top; i >= 0; i--)
        printf("%d\n", stack->stack[i]);
}

void push(struct stack *stack, int data)
{
    stack->stack[++stack->top] = data;
}

void pop(struct stack *stack)
{
    stack->top--;
}