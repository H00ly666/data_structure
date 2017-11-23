/*************************************************************************
	> File Name: Inthread_tree.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 11时55分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct node{

    struct node *Lchild;
    int  Ltag;
    int  num;
    int  Rtag;
    struct node *Rchild;
}Node;

Node * create_Bitree()
{
    int num;
    Node *root;
    printf("请输入　０结束\n");
    scanf("%d",&num);
    
    if( num == 0 ){   
        root = NULL;
    }

    else{
        root = (Node *)malloc(sizeof (Node));
        root->num = num;
        root->Lchild = create_Bitree();
        root->Rchild = create_Bitree();
    }
    return root;
}
void  Inthread_Bitree()
{

}
void print_Bitree(Node *root)
{
    if(root){
        printf("%d ",root->num);
        print_Bitree(root->Lchild);
        print_Bitree(root->Rchild);
    }   

}

int main ()
{
    Node * root;
    root = create_Bitree();
    print_Bitree(root);

}
