#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int push(int array[], int top)
{
    int value;
    printf("Enter the data to be push\n");
    scanf("%d", &value);
    if (top == MAX - 1)
        printf("Stack Overflow");
    else
    {

        top++;
        array[top] = value;
    }
    return top;
}
int pop(int array[], int top)
{
    int value;
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {
        value = array[top];
        top--;
        printf("Poped element is: %d \n", value);
    }
    return top;
}
void display(int array[], int top)
{
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {
        while (top >= 0)
        {
            printf("%d\n", array[top]);
            top--;
        }
    }
}

int main()
{
    int stack[MAX];
    int choice, n, data;
    int top = -1;
    printf("Enter the number of elements of the stack\n");
    scanf("%d", &n);
    printf("*********Stack operations using array*********");

    printf("\n----------------------------------------------\n");
    while (1)
    {
        printf("Choose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("Enter the choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            top = push(stack, top);
            break;
        case 2:
            top = pop(stack, top);
            break;
        case 3:
            printf("All the elements of the stack are:\n");
            display(stack, top);
            break;
        case 4:
            exit(1);
            break;
        default:
            break;
        }
    }
}
