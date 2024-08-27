#include<stdio.h>

void selectionsort(int a[20],int size)
{
    
    int n=size;
    int k,j,temp,min,l,loc;
    k=0;
    while(k<(n-1))
    {
        min=a[k];
        loc=k;
        j=k+1;
        while(j<n)
        {
            if(min>a[j])
            {
                min=a[j];
                loc=j;
            }    
            j++;
        }
        temp=a[k];
        a[k]=a[loc];
        a[loc]=temp;
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
    selectionsort(a,size);
    display(a,size);
    


}