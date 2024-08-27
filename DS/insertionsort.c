#include<stdio.h>

void insertionsort(int a[20],int n)
{
    int k=1,temp,j;
    while(k<n)
    {
        j=k-1;
        temp=a[k];
        while(temp<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        k++;
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
    insertionsort(a,size);
    display(a,size);
    


}