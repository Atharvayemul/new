#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define Max 10
int q_arr[Max];
int f = -1, r = -1;
void insert(int item);
int del();
int isFull();
int isEmpty();
void display();
int peek();
void main()
{
    int ch, item;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter an element to be inserted:");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            item = del();
            printf("%d is deleted from the queue", item);
            break;
        case 3:
            printf("%d is the front of the queue", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("wrong choice");
        }
    }
}
void insert(int item)
{
    if (isFull())
    {
        printf("\nQueue overflow");
        exit(1);
    }
    if (f == -1)
        f = 0;
    r = r + 1;
    q_arr[r] = item;
}
int del()
{
    int item;
    if (isEmpty())
    {
        printf("\nQueue underflow");
        exit(1);
    }
    item = q_arr[f];
    f = f + 1;
    return item;
}
int peek()
{
    if (isEmpty())
    {
        printf("\nQueue is empty");
        exit(1);
    }
    return q_arr[f];
}
int isEmpty()
{
    if (f == -1 || f == r + 1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if (r == Max - 1)
        return 1;
    else
        return 0;
}
void display()
{
    int i;
    if (isEmpty())
    {
        printf("\n Queue is empty");
        exit(1);
    }
    printf("\nQueue elements are:");
    for (i = f; i <= r; i++)
        printf("%d", q_arr[i]);
}
