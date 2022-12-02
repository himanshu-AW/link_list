#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
        printf("\n New node cannot be generated ");
    else
        return (p);
}
void insert_f(struct node **q)
{
    struct node *p;
    p = getnode();
    if (p != NULL)
    {
        printf("\nEnter node info value : ");
        scanf("%d", &p->info);
        p->next = *q;
        *q = p;
    }
}
void delete_f(struct node **q)
{
    int x;
    struct node *p;
    if (*q == NULL)
        printf("\nLink list is empty !!");
    else
    {
        p = *q;
        x = p->info;
        *q = p->next;
        free(p);
        // return(x);
    }
}
void display(struct node *q)
{
    if (q == NULL)
        printf("\n Link list is empty ");
    else
    {
        while (q != NULL)
        {
            printf("-> %d ", q->info);
            q = q->next;
        }
    }
}
void main()
{
    struct node *list;
    list = NULL;
    int x, choice;
    char ch;
    do
    {
        printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n\n\tEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_f(&list);
            break;
        case 2:
            delete_f(&list);
            break;
        case 3:
            display(list);
            break;
        default:
            printf("\nYou have Entered wrong choice !!");
        }
        printf("\nDo you wish to continue (y/n) :");
        fflush(stdin);
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
}