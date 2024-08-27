#include<stdio.h>

int partition(int a[20], int leftend, int rightend) {
    int left = leftend, right = rightend, temp;
    int pivot = a[left];
    while (left < right) 
    {
        while (left < rightend && a[left] <= pivot)
            left++;
        while (right > leftend && a[right] > pivot)
            right--;
        if (left < right) {
            temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }
    temp = a[leftend];
    a[leftend] = a[right];
    a[right] = temp;
    return right;
}


void quicksort(int a[20],int leftend,int rightend)
{
    if(leftend>=rightend)
    {

    }
    else
    {
        int p ;
        p = partition(a,leftend,rightend);
        quicksort(a,leftend,p-1);
        quicksort(a,p+1,rightend);

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
    quicksort(a,0,size-1);
    display(a,size);
    


}