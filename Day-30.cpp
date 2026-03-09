#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int exp;
    struct node *next;
};

struct node *create(int n)
{
    struct node *head = NULL, *temp, *newnode;
    int c, e;

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &c, &e);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->coef = c;
        newnode->exp = e;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        if(temp->exp == 0)
            printf("%d", temp->coef);
        else if(temp->exp == 1)
            printf("%dx", temp->coef);
        else
            printf("%dx^%d", temp->coef, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main()
{
    int n;
    struct node *poly;

    scanf("%d", &n);

    poly = create(n);

    display(poly);

    return 0;
}