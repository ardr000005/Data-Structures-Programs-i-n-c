#include<stdio.h>

void merge(int a[20],int left,int mid,int right)
{
    int i=left,j=mid+1,k=left,temp[20];
    while(i<=mid && j<= right)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=right)
    {
        temp[k]=a[j];
        j++;
        k++;
    }
    i=left;
    while(i<=right)
    {
        a[i]=temp[i];
        i++;
    }
}

void mergesort(int a[20],int left,int right)
{
    if(left<right)
    {
        int mid;
        mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        merge(a,left,mid,right);

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
    mergesort(a,0,size-1);
    display(a,size);
    


}