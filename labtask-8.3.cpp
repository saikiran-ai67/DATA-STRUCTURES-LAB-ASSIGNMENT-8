#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(struct node *head, int n)
{
    struct node *temp, *newnode;
    int x;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;

        if(head == NULL)
        {
            head = newnode;
            newnode->next = head;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            newnode->next = head;
            temp = newnode;
        }
    }

    return head;
}

struct node *insert(struct node *head, int value, int pos)
{
    struct node *temp = head;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;

    if(pos == 1)
    {
        while(temp->next != head)
            temp = temp->next;

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
    else
    {
        for(int i=1;i<pos-1;i++)
            temp = temp->next;

        newnode->next = temp->next;
        temp->next = newnode;
    }

    return head;
}

void display(struct node *head, int n)
{
    struct node *temp = head;

    for(int i=0;i<n;i++)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node *head = NULL;
    int n, value, pos;

    scanf("%d",&n);

    head = create(head,n);

    scanf("%d",&value);
    scanf("%d",&pos);

    head = insert(head,value,pos);

    display(head,n+1);

    return 0;
}
