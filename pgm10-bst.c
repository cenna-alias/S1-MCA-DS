#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node* lchild;
    int data;
    struct node* rchild;
} *root = NULL, *new, *p;
void create()
{
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to the node: ");
    scanf("%d", &new->data);
    new->lchild = NULL;
    new->rchild = NULL;
}
void search(struct node* rt)
{
    if (new->data < rt->data)
    {
        if (rt->lchild == NULL)
            rt->lchild = new;
        else
            search(rt->lchild);
    }
    else if (new->data > rt->data)
    {
        if (rt->rchild == NULL)
            rt->rchild = new;
        else
            search(rt->rchild);
    }
    else
    {
        printf("Duplicate data not allowed.\n");
        free(new);
    }
}
void insert()
{
    create();
    if (root == NULL)
        root = new;
    else
        search(root);
}
void preorder(struct node* rt)
{
    if (rt != NULL)
    {
        printf("%d -> ", rt->data);
        preorder(rt->lchild);
        preorder(rt->rchild);
    }
}
void postorder(struct node* rt)
{
    if (rt != NULL)
    {
        postorder(rt->lchild);
        postorder(rt->rchild);
        printf("%d -> ", rt->data);
    }
}
void inorder(struct node* rt)
{
    if (rt != NULL)
    {
        inorder(rt->lchild);
        printf("%d -> ", rt->data);
        inorder(rt->rchild);
    }
}
void deletenode(struct node* rt)
{   
    if (rt->lchild == NULL && rt->rchild == NULL)
    {
        if (rt == root)
        {
            free(rt);
            root = NULL;
        }
        else if (rt == p->lchild)
            p->lchild = NULL;
        else
            p->rchild = NULL;

        if (rt != root)
            free(rt);
    }
    else if (rt->lchild != NULL && rt->rchild == NULL)
    {
        if (rt == root)
        {
            root = rt->lchild;
            free(rt);
        }
        else if (rt == p->lchild)
        {
            p->lchild = rt->lchild;
            free(rt);
        }
        else
        {
            p->rchild = rt->lchild;
            free(rt);
        }
    }
    else if (rt->lchild == NULL && rt->rchild != NULL)
    {
        if (rt == root)
        {
            root = rt->rchild;
            free(rt);
        }
        else if (rt == p->lchild)
        {
            p->lchild = rt->rchild;
            free(rt);
        }
        else
        {
            p->rchild = rt->rchild;
            free(rt);
        }
    }   
    else
    {
        struct node* succParent = rt;
        struct node* succ = rt->rchild;
        while (succ->lchild != NULL)
        {
            succParent = succ;
            succ = succ->lchild;
        }
        rt->data = succ->data;
        if (succParent != rt)
            succParent->lchild = succ->rchild;
        else
            succParent->rchild = succ->rchild;

        free(succ);
    }
}
void dsearch(struct node* rt, int val)
{
    if (rt == NULL)
    {
        printf("Element not found\n");
        return;
    }
    if (val < rt->data)
    {
        p = rt;
        if (rt->lchild != NULL)
            dsearch(rt->lchild, val);
        else
            printf("Element not found\n");
    }
    else if (val > rt->data)
    {
        p = rt;
        if (rt->rchild != NULL)
            dsearch(rt->rchild, val);
        else
            printf("Element not found\n");
    }
    else
    {
        deletenode(rt);
    }
}
void delete()
{
    int val;
    printf("Enter the value to be deleted: ");
    scanf("%d", &val);
    dsearch(root, val);
}
int main()
{
    int ch;
    do
    {
        printf("\n1) Insert\n2) Preorder\n3) Postorder\n4) Inorder\n5) Delete\n6) Exit");
        printf("\nChoose Option: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            if (root == NULL)
                printf("Tree is empty\n");
            else
            {
                preorder(root);
                printf("\n");
            }
            break;
        case 3:
            if (root == NULL)
                printf("Tree is empty\n");
            else
            {
                postorder(root);
                printf("\n");
            }
            break;
        case 4:
            if (root == NULL)
                printf("Tree is empty\n");
            else
            {
                inorder(root);
                printf("\n");
            }
            break;
        case 5:
            delete();
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    } while (1);
    return 0;
}

