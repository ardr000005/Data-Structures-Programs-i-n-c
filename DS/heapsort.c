#include<stdio.h>

void createheap(int a[20],int n)
{
    int i=1,j,temp;
    while(i<=n)
    {
        j=i;
        while((j-1)/2>=0 && a[j] > a[(j-1)/2])
        {
            temp = a[(j-1)/2];
            a[(j-1)/2]=a[j];
            a[j]=temp;
            j=(j-1)/2;
        }
        i++;
    }
}

void removemax(int a[20], int n) {
    int temp;
    temp = a[0];
    a[0] = a[n];
    a[n] = temp;
}


int rebuildheap(int a[20],int n)
{
    int rchild,lchild,child,temp,j,flag=0;
    if(n==0)
    {
        return 0;
    }
    else
    {
    j=0;
    flag=1;
    while(flag==1)
    {
     lchild=(2*j)+1;
     rchild=(2*j)+2;
     if(rchild<=n)
     {
        if(a[rchild]>a[lchild])
        child = rchild;
        else
        child = lchild;
     }
     else if(lchild<=n)
     {
        child = lchild;
     }
     else
     flag=0;
     if(a[child]>a[j])
     {
        temp=a[j];
        a[j]=a[child];
        a[child]=temp;
        j=child;
     }
     else
     flag=0;
    }
    }
}

void heapsort(int a[20],int n)
{
    int i;
    createheap(a,n);
    for(i=n;i>=1;i--)
    {
        
        removemax(a,i);
        rebuildheap(a,i-1);
    }

}

void display(int a[20],int n)
{
    int i=0;
    printf("\nThe Elements of the array is \n ");
    for(i=0;i<n;i++)
    {
        printf("%3d",a[i]);
    }
}

void main()
{
    int i,a[20],size;
    printf("Enter the size of the array \n");
    scanf("%d",&size);
    printf("Enter the elements of the array \n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort(a,size);
    display(a,size);
    


}