#include<stdio.h>
int a[20];
int front=-1;
int rear=-1;
int addfront(int item,int n)
{
    if(front == 0 && rear == n-1)
    {
        printf("\n Queue is full\n");
        return 0;
    }
    else if(front==-1)
    {
        front=0;
        rear=0;
        a[front]=item;
        printf("item inserted\n");
    }
    else if(front>0)
    {
        front--;
        a[front]=item;
    }
    else
    {
        int i;
        i=rear;
        while(i>=front)
        {
            a[i+1]=a[i]
            i--;
        }
        a[front]=item;
        rear++;
    }

}

int addrear(int item,int n)
{
    if(front == 0 && rear == n-1)
    {
        printf("\n Queue is full\n");
        return 0;
    }
    else if(front==-1)
    {
        front=0;
        rear=0;
        a[rear]=item;
        printf("item inserted\n");
    }
    else if(rear<n-1)
    {
        rear++;
        a[rear]=item;
    }
    else
    {
        i=front;
        while(i<=rear)
        {
            a[i-1]=a[i];
            i++;
        }
        q[rear]=item;
        front--;

    }
}

int deleterear(int n)
{
    if(front==-1 && rear ==-1)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else if(front==rear)
    {
        item=a[rear];
        front=-1;
        rear=-1;
    }
    else
    {
        item=a[rear];
        rear--;
    }
}

int deletefront(int n)
{
    if(front==-1 && rear ==-1)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else if(front==rear)
    {
        item=a[front];
        front=-1;
        rear=-1;
    }
    else
    {
        item=a[front];
        front++;
    }
}