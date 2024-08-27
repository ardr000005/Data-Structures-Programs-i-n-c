#include<stdio.h>
#include<stdlib.h>

struct poly
{
    int coeff;
    int expo;
    struct poly* next;
} *p1,*p2,*s,*m;
p1=NULL;
p2=NULL;
s=NULL;
m=NULL;

void create_poly1(int coeff,int expo)
{
    struct poly *newnode,*current;
    newnode=(struct poly*)malloc(sizeof(struct poly));
    newnode->coeff=coeff;
    newnode->expo=expo;
    newnode->next=NULL;
    if(p1==NULL)
    {
        p1=newnode;
        printf("\nadded\n");
    }
    else
    {
        current=p1;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newnode;
        printf("\nadded\n");
    }

}
void create_poly2(int coeff,int expo)
{
    struct poly *newnode,*current;
    newnode=(struct poly*)malloc(sizeof(struct poly));
    newnode->coeff=coeff;
    newnode->expo=expo;
    newnode->next=NULL;
    if(p2==NULL)
    {
        p2=newnode;
        printf("\nadded\n");
    }
    else
    {
        current=p2;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newnode;
        printf("\nadded\n");
    }    
}

void addpoly()
{
    if(p1==NULL && p2 == NULL)
    {
        printf("Cannot add nothing exits\n");
    }
    else
    {
        struct poly *newnode,*current1,*current2,*current3;
        current1=p1;
        current2=p2;
        while(current1!=NULL && current2!=NULL)
        {
        newnode=(struct poly*)malloc(sizeof(struct poly));
        newnode->coeff=NULL;
        newnode->expo=NULL;
        newnode->next=NULL;
        if(current1->expo==current2->expo)
        {
            newnode->coeff=p1->coeff+p2->coeff;
            newnode->expo=p1->expo;
            current1=current1->next;
            current2=current2->next;
        }
        else if(current1->expo<current2->expo)
        {
            newnode->coeff=p1->coeff;
            newnode->expo=p1->expo;
            current1=current1->next;
        }
        else if(current1->expo>current2->expo)
        {
            newnode->coeff=p2->coeff;
            newnode->expo=p2->expo;
            current2=current2->next;
        }
        if(s==NULL)
        {
            s=newnode;
        }
        else
        {
            current3=s;
            while(current3->next!=NULL)
            {
                current3=current3->next;
            }
            current3->next=newnode;
        }
        }

        while(current1!=NULL)
        {
            newnode=(struct poly*)malloc(sizeof(struct poly));
            newnode->coeff=current1->coeff;
            newnode->expo=current1->expo;
            newnode->next=NULL;

            while(current3->next!=NULL)
            {
                current3=current3->next;
            }
            current3->next=newnode;
            
        }

        while(current2!=NULL)
        {
            newnode=(struct poly*)malloc(sizeof(struct poly));
            newnode->coeff=current2->coeff;
            newnode->expo=current2->expo;
            newnode->next=NULL;

            while(current3->next!=NULL)
            {
                current3=current3->next;
            }
            current3->next=newnode;
            
        }
    }
}

void multiply_poly()
{
    
}

void displaypoly(struct poly* p)
{
    struct poly* current;
    if(p==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        current=p;
        while(current!=NULL)
        {
            printf("%dX^%d+",current->coeff,current->expo);
            current=current->next;
        }
    }
}
