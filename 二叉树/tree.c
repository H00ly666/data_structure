/*************************************************************************
	> File Name: tree.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月25日 星期三 23时18分50秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef  struct  tree{
    char  c;
    struct tree  *Lchild;
    struct tree  *Rchild;
}Tnode;
void  Create_tree(Tnode  **root)
{
    char a;
    printf("请输入　\n");
    scanf("%c",&a );
    getchar();
    if(a == '0')
       *root = NULL; 
    else{
        *root = (Tnode *) malloc (sizeof (Tnode));
        (*root)->c = a;
        Create_tree(&( (*root)->Lchild) );
        Create_tree(&( (*root)->Rchild) );    
    }

}
void visit_first(Tnode *root)
{
    if (root){
        printf("%c ",root->c);
        visit_first(root->Lchild);
        visit_first(root->Rchild);
    }

}

void visit_middle(Tnode *root)
{
    if(root){

        visit_first(root->Lchild);
        printf("%c ",root->c);
        visit_first(root->Rchild);
    }
}
void visit_end(Tnode *root)
{
    if(root){
        visit_end(root->Lchild);
        visit_end(root->Rchild);
        printf("%c ",root->c);
    }
}

int main ()
{
    Tnode *root;
    Create_tree(&root);
    visit_first(root);
    printf("\n");
    visit_middle(root);
    printf("\n");
    visit_end(root);
    return  0;
    
}
