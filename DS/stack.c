#include<stdio.h>
int Top=-1;
void push(int a[20],int element,int size)
{
    if(Top==(size-1))
    {
        printf("Stack is full");
    }
    else
    {
        Top++;
        a[Top]=element;
        printf("Element inserted\n");
    }
}

int pop(int a[20],int size)
{
    int d_elem;
    if(Top == -1)
    {
        printf("Stack is empty");
        return -100;
    }
    else
    {
        d_elem=a[Top];
        Top--;
        return d_elem;       
    }
}

void display(int a[20],int size)
{
    if(Top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        int i=Top;
        printf("\n The Elements of the Stack are \n");
        while(i>=0)
        {
            printf("%3d",a[i]);
            i--;
        }
    }
}

void main()
{
    int a[20],q=1,ch,elem,d_elem,size;
    printf("\nEnter the size of the stack\n");
    scanf("%d",&size);
    while(q==1)
    {
        printf("\n MENu \n");
        printf(" Choose The Operations \n");
        printf(" 1 = push \n 2 = pop \n 3 = display \n 4 = Exit \n ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("Enter the element to be inserted into the stack \n");
                     scanf("%d",&elem);
                     push(a,elem,size);
                     break;
            case 2 : d_elem=pop(a,size);
                     if(d_elem!=-100)
                     printf("Element deleted\n The element is %d \n",d_elem);
                     break;
            case 3 : display(a,size);
                     break;
            case 4 : printf("Exiting Operations \n");
                     q=0;
                     break;
        }
    }   
}