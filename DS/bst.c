#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree* rlink;
    struct tree* llink;
}*root=NULL;

int bst_insert(int element)
{
    struct tree *current,*newnode,*parent;
    newnode = (struct tree*) malloc(sizeof(struct tree));
    newnode->data=element;
    newnode->rlink=NULL;
    newnode->llink=NULL;
    if(root==NULL)
    {
        root=newnode;
        printf("\nElement inserted\n");
    }
    else
    {
        current = root;
        while(current!=NULL)
        {
            parent=current;
            if(element>current->data)
            current = current->rlink;
            else if(element < current->data)
            current=current->llink;
            else if(element == current->data)
            {
            printf("Duplicate node\n");
            return 0;
            }
        }
        if(element>parent->data)
        {
            parent->rlink=newnode;
            printf("\n Element inserted \n");
        }
        else if(element<parent->data)
        {
            parent->llink=newnode;
            printf("\n Element inserted \n");
        }
    }
}

void bst_search(int element)
{
    struct tree *current,*parent;
    int flag = 0;
    current = root;
    if(current == NULL)
        printf("No Element exist");
    else
    {
        while(current != NULL )
        {
            if(current->data == element)
            flag=1;
            else
            {
                parent = current;
            if(element<current->data)
                current = current->llink;
            else if(element>current->data)
                current = current->rlink;  
            }     
        }
        if(flag == 1)
        {
            printf("Element found\n");
        }
        else
        {
            printf("Element not found\n");
        }
    }   
}

struct tree* succesor(struct tree *current)
{
    struct tree *temp;
    temp=current->rlink;
    if(temp!=NULL)
    {
    while(temp->llink==NULL)
    {
        temp=temp->llink;
    }
    }
    return temp;
}

void bst_delete(int element)
{
    struct tree *current,*parent,*succ;
    int flag = 0;
    parent=NULL;
    if(current == NULL)
        printf("No Element exist");
    else
    {
        current = root;
        while(current != NULL )
        {
            if(current->data == element)
            {
            flag=1;
            break;
            }
            else
            {
                parent = current;
            if(element<current->data)
                current = current->llink;
            else if(element>current->data)
                current = current->rlink;  
            }     
        }
        if(flag == 0)
        {
            printf("Element not found found\n");
        }
        else
        {
            printf("Element found\n");

        if(current->rlink==NULL && current->llink==NULL)
        {
            if(parent==NULL)
            {
                root=NULL;
                free(current);
                printf("\nitem deleted\n");
            }
            else if(parent->rlink==current)
            {
                parent->rlink=NULL;
                free(current);
                printf("\nitem deleted\n");
            }
            else if(parent->llink==current)
            {
                parent->llink=NULL;
                free(current);
                printf("\nitem deleted\n");
            }
        }

        else if(current->rlink==NULL && current->llink!=NULL)
        {
            if(parent==NULL)
            {
                root=root->llink;
                free(current);
                printf("\nitem deleted\n");
            }
            else if(parent->rlink==current)
            {
                parent->rlink=current->llink;
                free(current);
                printf("\nitem deleted\n");
            }
            else if(parent->llink==current)
            {
                parent->llink=current->llink;
                free(current);
                printf("\nitem deleted\n");
            }
        }

        else if(current->rlink!=NULL && current->llink==NULL)
        {
            if(parent==NULL)
            {
                root=root->rlink;
                free(current);
                printf("\nitem deleted\n");
            }
            else if(parent->rlink==current)
            {
                parent->rlink=current->rlink;
                free(current);
                printf("\nitem deleted\n");
            }
            else if(parent->llink==current)
            {
                parent->llink=current->rlink;
                free(current);
                printf("\nitem deleted\n");
            }
        }

        else if(current->rlink!=NULL && current->llink!=NULL)
        {
            int item;
            succ = succesor(current);
            item=succ->data;
            bst_delete(item);
            current->data=item;
        }
        }

    } 
}

void preorder(struct tree *root)
{
    struct tree* ptr;
    ptr=root;
    if(ptr!=NULL)
    {
        printf("%3d",ptr->data);
        preorder(ptr->llink);
        preorder(ptr->rlink);       
    }
}

void inorder(struct tree *root)
{
    struct tree* ptr;
    ptr=root;
    if(ptr!=NULL)
    {
        inorder(ptr->llink);
        printf("%3d",ptr->data);
        inorder(ptr->rlink);       
    }
}

void postorder(struct tree *root)
{
    struct tree* ptr;
    ptr=root;
    if(ptr!=NULL)
    {
        postorder(ptr->llink);
        postorder(ptr->rlink);
        printf("%3d",ptr->data);       
    }
}

void main()
{
    int ch,q=1,b,element,delement;
    while(q==1)
    {
        printf("\n  MENU  \n");
        printf("Choose the operations \n");
        printf("1 = Insert an element \n 2 = Traverse \n 3 = Delete an Element \n 4 = Exit ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("Enter the element to be inserted ");
                     scanf("%d",&element);
                     bst_insert(element);
                     break;
            case 2 : printf("\n 1 - Preorder Traversal \n 2 = Inorder Traversal \n 3 = PostOrder Traversal \n");
                     scanf("%d",&b);
                     switch(b)
                     {
                        case 1 : preorder(root);
                                 break;
                        case 2 : inorder(root);
                                 break;
                        case 3 : postorder(root);
                                 break;
                     }
                     break;

            case 3 :  printf("Enter the element to be deleted ");
                      scanf("%d", &delement);
                      bst_delete(delement);
                      break;

            case 4 : printf("Exiting Operation \n");
                     q=0;
                     break;
                     
        }
    }

}