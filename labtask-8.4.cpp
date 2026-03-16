#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create(struct node *head,int n)
{
    struct node *temp,*newnode;
    int x;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);

        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;

        if(head==NULL)
        {
            head=newnode;
            newnode->next=head;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            newnode->next=head;
            temp=newnode;
        }
    }

    return head;
}

struct node* delete_last(struct node *head)
{
    struct node *temp=head;
    struct node *prev=NULL;

    if(head==NULL)
        return NULL;

    if(head->next==head)
    {
        free(head);
        return NULL;
    }

    while(temp->next!=head)
    {
        prev=temp;
        temp=temp->next;
    }

    prev->next=head;
    free(temp);

    return head;
}

void display(struct node *head)
{
    struct node *temp=head;

    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}

int main()
{
    struct node *head=NULL;
    int n;

    scanf("%d",&n);

    head=create(head,n);

    head=delete_last(head);

    display(head);

    return 0;
}
