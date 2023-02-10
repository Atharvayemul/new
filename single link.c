#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
void display(struct node *start);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *del1(struct node *start);
void del2();
void main()
{
    struct node *start = NULL;
    int ch, data, item;
    clrscr();
    while (1)
    {
        printf("\n1.Add  at begining\n2.Add at end\n3.Delete at begining\n4.Delete at end\n5.Display\n6.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter data:");
            scanf("%d", &data);
            start = addatbeg(start, data);
            break;
        case 2:
            printf("\nEnter data");
            scanf("%d", &data);
            start = addatend(start, data);
            break;
        case 3:
            start = del1(start);
            printf("First node deleted");
            break;
        case 4:
            del2();
            printf("Last node deleted");
            break;
        case 5:
            display(start);
            break;
        case 6:
            exit(0);
        default:
            printf("wrong choice");
        }
    }
}
struct node *addatbeg(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Memory not available");
        exit(1);
    }
    tmp->info = data;
    tmp->link = start;
    start = tmp;
    return start;
}
struct node *addatend(struct node *start, int data)
{
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Memory not available");
        exit(1);
    }
    tmp->info = data;
    p = start;
    while (p->link != NULL)
        p = p->link;
    p->link = tmp;
    tmp->link = NULL;
    return start;
}
void display(struct node *start)
{
    struct node *p;
    p = start;
    printf("List is:");
    while (p != NULL)
    {
        printf("%d", p->info);
        p = p->link;
    }
}
struct node *del1(struct node *start)
{
    struct node *tmp;
    tmp = start;
    start = start->link;
    free(tmp);
    return start;
}
void del2()
{
    struct node *tmp, *p;
    p->link = NULL;
    p->link = tmp->link;
    free(tmp);
}
