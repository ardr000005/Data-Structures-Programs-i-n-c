#include<stdio.h>
void read_poly(int a[2][10],int n)
{
    int i=0;
    printf("Enter the polynomial \n");
    for(i=0;i<n;i++)
    {
        printf("Enter the co-efficient and exponent of the %d term",i+1);
        scanf("%d%d",&a[0][i],&a[1][i]);
    }
}

int add_poly(int x[2][10],int y[2][10],int z[2][10],int n,int m)
{
    int i,j,k;
    i=0;
    j=0;
    k=0;
    while(i<n && j<m)
    {
        if(x[1][i]==y[1][j])
        {
            z[0][k]=x[0][i]+y[0][j];
            z[1][k]=x[1][i];
            i++;
            j++;
            k++;
        }
        else if(x[1][i]<y[1][j])
        {
            z[0][k]=x[0][i];
            z[1][k]=x[1][i];
            i++;
            k++;
        }
        else if(x[1][i]>y[1][j])
        {
            z[0][k]=y[0][j];
            z[1][k]=y[1][j];
            j++;
            k++;
        }  
    }

    while(i<n)
    {
        z[0][k]=x[0][i];
        z[1][k]=x[1][i];
        i++;
        k++;
    }
    while(j<m)
    {
         z[0][k]=y[0][j];
        z[1][k]=y[1][j];
        j++;
        k++;
    }

    return k;
}
void display(int d[2][10],int l)
{
    int j;
    for(j=0;j<l;j++)
    {
        if(j!=(l-1))
        printf("%dX^%d+",d[0][j],d[1][j]);
        else
        printf("%dX^%d",d[0][j],d[1][j]);
    }
}
void main()
{
    int p1[2][10],p2[2][10],sum[2][10],t1,t2,t3,q;
    printf("Enter the terms of the first polynomial\n");
    scanf("%d",&t1);
    read_poly(p1,t1);
           
    printf("Enter the terms of the second polynomial\n");
    scanf("%d",&t2);
    read_poly(p2,t2);

    t3=add_poly(p1,p2,sum,t1,t2);

    printf("The First Polynomial is \n");
    display(p1,t1);

    printf("\nThe Second Polynomial is \n");
    display(p2,t2);

    printf("\nThe Sum Polynomial is \n");
    display(sum,t3);
}