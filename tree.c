#include <stdio.h>
//TREE Using LOCAL var
//So we now have to pass HEAD var too in the parameters using pointer to pointer as its now a local var

struct Number
{
    struct Number *left;
    int n;
    struct Number *right;
};

typedef struct Number Node;

void addNode(Node **list,int x)   // Using pointer to pointer cause we needed to change the actual value in head hence call by reference to a pointer.
{
    if(*list==NULL)
    {
        *list=(Node *)malloc(sizeof(Node));
        (*list)->left=NULL;
        (*list)->n=x;
        (*list)->right=NULL;
    }
    else
    {
        if(x<((*list)->n))
        {
            addNode(&((*list)->left),x);
        }

        else
        {
            addNode(&((*list)->right),x);
        }
    }
}

void inOrder(Node *list)  //Because we dont want any conversions to take plave in original, hence we use a single pointer (call by value types)(but not actually)
{
    if(list!=NULL)
    {
        inOrder(list->left);
        printf("%d\t",list->n);
        inOrder(list->right);
    }
}

void preOrder(Node *list)  //Because we dont want any conversions to take plave in original, hence we use a single pointer (call by value types)(but not actually)
{
    if(list!=NULL)
    {
        printf("%d\t",list->n);
        preOrder(list->left);
        preOrder(list->right);
    }
}

void postOrder(Node *list)  //Because we dont want any conversions to take plave in original, hence we use a single pointer (call by value types)(but not actually)
{
    if(list!=NULL)
    {
        postOrder(list->left);
        postOrder(list->right);
        printf("%d\t",list->n);
    }
}

int count(Node *list)
{
    if(list!=NULL)
    {
        return (1+count(list->left)+count(list->right));
    }
    else
    {
        return 0;
    }
}

int extCount(Node *list)
{
    if(list!=NULL)
    {
        if(list->left!=NULL||list->right!=NULL)
        {
            return (0+extCount(list->left)+extCount(list->right));
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int inCount(Node *list)
{
    if(list!=NULL)
    {
        if(list->left!=NULL||list->right!=NULL)
        {
            return (1+inCount(list->left)+inCount(list->right));
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void dispLeave(Node *list)
{
    if(list!=NULL)
    {
        if(list->left==NULL&&list->right==NULL)
        {
            printf("%d\t",list->n);
        }
        else
        {
            dispLeave(list->left);
            dispLeave(list->right);
        }
    }
}

int isBal(Node *list)
{
    if(list!=NULL)
    {
        if((list->left==NULL&&list->right==NULL)||(list->left!=NULL&&list->right!=NULL))
        {
            return (0+isBal(list->left)+isBal(list->right));
        }
        else
        {
            return 1;
        }
    }
}

int search(Node *list,int x)
{
    if(list!=NULL)
    {
        if(list->n==x)
        {
            return 1;
        }
        else if(x>=list->n)
        {
            return (0+search(list->right,x));
        }
        else
        {
            return 0+search(list->left,x);
        }
    }

    else
    {
        return 0;
    }
}

int height(Node *list)
{
    int lst,rst;        // left side tree, rs tree
    if(list!=NULL)
    {
        lst=height(list->left);
        rst=height(list->right);

        if(lst>rst)
            return ++lst;
        else
            return ++rst;
    }
    else
        return 0;
}


int level(Node *list,int x)
{
    if(list!=NULL)
    {
        if(list->n==x)
            return 1;
        else if(x>=list->n)
            return (1+level(list->right,x));
        else
            return 1+level(list->left,x);
    }
    else
        return 0;
}

int big(Node *list)
{
    if(list!=NULL)
    {
        if(list->right==NULL)
            return list->n;
        else
            return big(list->right);
    }
}

int small(Node *list)
{
    if(list!=NULL)
    {
        if(list->left==NULL)
            return list->n;
        else
            return small(list->left);
    }
}

void mirror(Node **list)
{

    if((*list)!=NULL)
    {
        Node *ptr;
        mirror(&((*list)->left));  //reaches last element in left ...
        mirror(&((*list)->right)); // goes right until theres a "left" turn;

        ptr=(*list)->right;
        (*list)->right=(*list)->left;
        (*list)->left=ptr;
    }
}

void dupli(Node *list1,Node **list2)
{
    if(list1!=NULL)
    {
        (*list2)=(Node *)malloc(sizeof(Node));
        (*list2)->n=(list1)->n;
        (*list2)->left=NULL;
        (*list2)->right=NULL;
        dupli(((list1)->left),&((*list2)->left));
        dupli(((list1)->right),&((*list2)->right));
    }
}
/*
void printActualTree(Node *list, int height)
{
    for(int i=0;i<=2*height;i++)
        printf("\t");
    printf("\n");

}
*/


void delEle(Node **list,int x)  //not by rec.
{
    Node *parent=NULL,*node,*succ;
    int found=0;
    if(*list==NULL)
        printf("tree empty\n");
    else
    {
        searchEleForDel(list,&parent,&node,x,&found); //sending addresses to have changes here too...       *list is used cause down q needs *list.. and no actual change to be made to the list in that func
        if(found==0)
            printf("ele not found\n");
        else
        {
            if(node->left!=NULL && node->right!=NULL)
            {
                parent=node;
                succ=node->right;
                while(succ->left!=NULL)
                {
                    parent=succ;
                    succ=succ->left;
                }
                printf("deleting %d\n",node->n); ADD CONDITIONS FOR IF ROOT IS THE ONE TO BE DEL LIKE IF PARENT==NULL.
                node->n=succ->n;
                node=succ;

                if(node->right!=NULL)
                    parent->left=node->right;

                node=NULL;// free(node);
            }       //no else if cause its(code) just repeating...

            if(node->left!=NULL && node->right==NULL)
            {
                if(parent->left==node)
                    parent->left=node->right;
                else
                    parent->right=node->right;
                node=NULL;//free(node);
            }
            if(node->left==NULL && node->right!=NULL)
            {
                if(parent->left==node)
                    parent->left=node->right;
                else
                    parent->right=node->right;
                node=NULL;//free(node);
            }

            if(node->right==NULL && node->left==NULL)
            {
                if(parent->left==node)
                    parent->left=NULL;
                else
                    parent->right=NULL;
                node=NULL;
            }
        }
    }
}
/*
void searchEleForDel(Node *q,Node **parent,Node **node,int x,int *f)
{
    printf("%d",(q->n));
    if(q!=NULL)
    {
        if(q->n==x)
        {
            printf("%d",(q->n));
            *f=1;
            printf("%d",(q->n));
            *node=q;
            printf("%d",(q->n));

        }
        else if(x<(q)->n)
        {
            *parent=q;
            searchEleForDel(((q)->left),&(*parent),&(*node),x,&(*f));
        }
        else
        {
            printf("%d",(q->n));
            *parent=q;
            searchEleForDel(((q)->right),&(*parent),&(*node),x,*f);
            printf("%d",(q->n));
        }
    }
    else
        return;
}
*/
void searchEleForDel(Node **list,Node **parent,Node **node,int x,int *f)
{
    Node *q;
    q=*list;
    *f=0;
    *parent=NULL;
    while(q!=NULL)
    {
        if(q->n==x)
        {
            *f=1;
            *node=q;
            return;

        }
        else if(x<q->n)
        {
            *parent=q;
            q=q->left;
        }
        else
        {

            *parent=q;
            q=q->right;

        }
    }
}



void main()
{
    Node *head =NULL;
    Node *head2=NULL;
    int c,a,t;
    do
    {

        printf("\n\nTree\n\n Menu\n\n1:Add Node \n2:Inorder \n3:Preorder \n4:Postorder \n5:Count All Nodes\n6:Count External Nodes \n7:Count Internal Nodes\n8:Display Leaves \n9:Is It Balanced Binary Tree  \n10:Search \n11:Height \n12:Find Level \n13:Find Big \n14:Find Small \n15:Mirror\n16:Duplicate\n17:Delete Node\n18:Exit\nEnter Choice ");
    scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter a Number ");
                scanf("%d",&a);
                addNode(&head,a);
                break;

            case 2:
                printf("main tree:- ");
                inOrder(head);
                printf("\n");
                if(head2!=NULL)
                {
                    printf("dupli tree:- ");
                    inOrder(head2);
                }
                break;

            case 3:
                printf("main tree:- ");
                preOrder(head);
                printf("\n");
                if(head2!=NULL)
                {
                    printf("dupli tree:- ");
                    preOrder(head2);
                }
                break;

            case 4:
                printf("main tree:- ");
                postOrder(head);
                printf("\n");
                if(head2!=NULL)
                {
                    printf("dupli tree:- ");
                    postOrder(head2);
                }
                break;

            case 5:
                printf("%d",count(head));
                break;

            case 6:
                printf("%d",extCount(head));
                break;
            case 7:
                printf("%d",inCount(head));
                break;
            case 8:
                dispLeave(head);
                break;
            case 9:
                if(isBal(head)==0)
                    printf("Balanced");
                else
                    printf("Not Balanced");
                break;
            case 10:
                printf("Enter a Number to be Searched ");
                scanf("%d",&a);
                t=search(head,a);
                if(t==1)
                {
                    printf("found");
                }
                else
                    printf("not found");
                break;
            case 11:
                printf("height = %d",height(head));
                break;
            case 12:
                printf("Enter a Number to know its level ");
                scanf("%d",&a);
                t=search(head,a);
                if(t==1)
                {
                    printf("found ");
                    printf("at level %d",(level(head,a)-1));
                }
                else
                    printf("not found");
                break;
            case 13:
                printf("biggest element is %d",big(head));
                break;
            case 14:
                printf("smallest element is %d",small(head));
                break;
            case 15:
                mirror(&head);   // cause we want actual changes hence call by ref.
                break;
            case 16:
                if(head2!=NULL)
                    printf("already duplicated sorry");
                else
                    dupli(head,&head2);
                break;
            case 17:
                printf("Enter a Number ");
                scanf("%d",&a);
                delEle(&head,a);
                break;
            case 18:
                printf("Bye\n Thank you :)\n");
                break;
            default:
                printf("invalid");


        }
    }while(c!=18);
}












