/*************************************************************************
	> File Name: creat_tree.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月25日 星期三 16时45分48秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct tree {
    int num;
    struct  tree *Lchild;
    struct  tree *Rchild;
}Tnode;
/*
void Create_tree(Tnode **Root) //指针本身会保存在一片空间里　而其中的值是不定的　malloc正好会改变其中的值那么如果我们不把这个指针的地址存起来　自然日后就会丢失不见
{
    int  num;
    printf("请输入数据　０结束\n");
    scanf ("%d" ,&num);
    if  (num == 0)
        *Root = NULL;    
    else {
        *Root = (Tnode *) malloc (sizeof (Tnode));
        (*Root)-> num = num;
        Create_tree (&( (*Root)->Lchild)) ;
        Create_tree (&( (*Root)->Rchild)) ;

    }
}*/
Tnode * Create_tree()
{
    Tnode *Root;
    int  num;
    scanf("%d", &num);
    if(num == 0 )
        Root = NULL;
    else {
        Root = (Tnode*) malloc  (sizeof(Tnode));
        Root->num = num;
        Root->Lchild = Create_tree();
        Root->Rchild = Create_tree();
    }
    return Root;
}



void Visit_tree(Tnode * Root)
{
    if (Root){
        printf("%d",Root->num);
        Visit_tree(Root->Lchild);
        Visit_tree(Root->Rchild);
    }
}
int main ()
{
    Tnode *Root;
    Root =  Create_tree();
    Visit_tree(Root); 
    return 0; 

