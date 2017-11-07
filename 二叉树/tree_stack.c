/*************************************************************************
	> File Name: tree_stack.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月26日 星期四 10时58分22秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

#define   TRUE  1
#define   FALSE 0

typedef  struct  tree{
    int  num;
    struct tree  *Lchild;
    struct tree  *Rchild;
}Tnode;
//栈的结构
typedef struct node{
    Tnode *tree_node ;
    struct node  *next;
}stacktype;

void  create_tree(Tnode **root);
void  visit_tree_stack(Tnode *root);


void  create_tree(Tnode **root)
{
    int num;
    printf("请输入　0结束\n");
    scanf("%d",&num);
    if (num == 0)
        *root = NULL;
    else {
        *root = (Tnode *) malloc (sizeof(Tnode));
        (*root)->num = num;
        create_tree(& ( (*root)->Lchild ));
        create_tree(& ( (*root)->Rchild ));
    }


}
stacktype * Init_stack()
{
    stacktype *top;
    top = (stacktype *) malloc (sizeof(stacktype));
    top->next = NULL;
    return top;
}
int  pushLstack(stacktype *top,Tnode *tree)
{
    stacktype *p;
    if((p = (stacktype *) malloc (sizeof (stacktype)) ) == NULL ) return FALSE;
    //申请一个节点
    p->tree_node = tree ; 
    p->next = top->next;
    top->next = p;
    return TRUE;
}
Tnode * popLstack(stacktype *top)
{
    stacktype *del;
    if  ( (top->next) != NULL ){
        del = top->next;
        top->next = del->next;
           // free(del);
        }
    return del->tree_node;
}
/*
void visit_tree_stack(Tnode  *head)
{
    stacktype *stack;
    Tnode *root = head,* temp;
    stack = Init_stack();
    pushLstack(stack, root);
    while ( (stack->next) != NULL ){
        temp = popLstack(stack);
        
        while(temp ){   //一直向左　并将沿途的节点全部压入堆栈
            pushLstack(stack, temp);
            temp = temp->Lchild;
        }
        if( (stack->next) !=  NULL){
            
            temp = popLstack(stack) ;
            printf("num = %d \n",temp->num );   //打印节点
            pushLstack(stack, temp->Rchild);
        }
    }
}
*/
void  visit_tree_stack( Tnode *BT  )
{
    stacktype   *stack;
    stack = Init_stack();
    Tnode *T = BT;
    while (T || stack->next != NULL ){
        while (T){
            pushLstack(stack,T);
            T = T->Lchild;
        }
        if(stack->next != NULL){
            T =  popLstack(stack);
            printf("num = %d",T->num);
            T = T->Rchild;
        }

    }
}
/*
void  visit_tree_stack(Tnode  *BT  )
{
    stacktype *stack;
    stack = Init_stack();
    Tndoe *T = BT;
    while(T || stack->next != NULL){
        while(){
            pushLstack(stack, T);
            T = T->Lchild;
        }
        if(stack->next != NULL){
            popLstack
        }
    } 
}*/
//　求叶子个数　
int  leaf(Tnode *root)
{
    int  ln,rn;
    if (root == NULL)
        return 0;
    if (root->Lchild != NULL ||  root->Lchild != NULL && root->Lchild != NULL || root->Lchild != NULL)
        return 1;
    if (root->Lchild != NULL && root->Rchild != NULL) 
        return ln+rn;
}
//左右交换二叉树
/*
void exchange_tree(Tnode **root)
{
    Tnode  ** temp;
        printf("怎么回事\n");
    if(*root){
        if ( (*root)->Lchild !=NULL || (*root)->Rchild != NULL ){
        *temp = (*root)->Lchild ;
        (*root)->Lchild = (*root)->Rchild;
        (*root)->Rchild = *temp;
        exchange_tree( & ( (*root)->Lchild ));
        exchange_tree( & ( (*root)->Rchild ));
        }

    }
}*/
//逆中序遍历并打印树状结

void exchange_tree(Tnode *root){
        Tnode *t;
    if(root){
        t = root->Lchild;
        root->Lchild = root->Rchild;
        root->Rchild = t;
        exchange_tree(root->Lchild);
        exchange_tree(root->Rchild);
        
    }
}



void  output_tree(Tnode  *root, int  level)
{
    if(root){
        output_tree(root->Rchild , level+1);
        for(int i =0; i<level;i++ )
            printf("   ");
        printf("%d\n",root->num ); 
        output_tree(root->Lchild , level+1);
            

    }
    

}
int main()
{
    Tnode *root;
    create_tree(&root);
  //  visit_tree_stack(root);
    output_tree (root , 1);
    exchange_tree;
    output_tree(root,1);


}
