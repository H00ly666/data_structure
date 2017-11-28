#include<stdio.h>
#include<stdlib.h>
typedef struct tree {
    char num;
    struct  tree *Lchild;
    struct  tree *Rchild;
}Tnode;

typedef struct n{
    Tnode * Root;
    struct n* next;
}Qlist;

Tnode * Create_tree()
{
    Tnode *Root;

    char  num;
    num = getchar();
    if(num == '#' )
    	Root = NULL;
    else {
        Root = (Tnode*) malloc  (sizeof(Tnode));
        Root->num = num;
        Root->Lchild = Create_tree();
        Root->Rchild = Create_tree();
    }
    return Root;
}

//添加入队列的尾部
void enqueue(Qlist * Q,Tnode *root  )
{
    if(root == NULL)
    return;
    Qlist *temp=Q,*ptr;
    ptr = (Qlist*) malloc (sizeof(Qlist));
    ptr->Root = root;
    ptr->next = NULL;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
}
//出队
Tnode * dequeue(Qlist *Q)
{
    Qlist *del;
    del = Q->next;
    Q->next = del->next ;
    //free
    return del->Root;
}


void count_tree(Tnode *root,int level)
{
    int  curcount=1,nextcount=0,count=1;
    Qlist *Q;
    Tnode *temp;
    Q = (Qlist *) malloc (sizeof(Qlist));
    Q->next = NULL;
    enqueue(Q,root);
    while(Q->next!= NULL){

        temp = dequeue(Q);
        curcount--;

        if(temp->Lchild != NULL){
            enqueue(Q,temp->Lchild);
            nextcount++;
        }
        if(temp->Rchild != NULL){
            enqueue(Q,temp->Rchild);
            nextcount++;
        }
        if(curcount == 0){
            count++;
            if(level == count)
            printf("%d",nextcount);
            curcount = nextcount;
	    nextcount = 0;
        }
    }
}

int COUNT(Tnode *who, int depth, int k, int *number) {
    if (who == NULL)
        return 0;
    if (who->Lchild == NULL && who->Rchild == NULL && depth == k) {
        (*number)++;
    }

    COUNT(who->Lchild, depth + 1, k, number);
    COUNT(who->Rchild, depth + 1, k, number);
    return *number;
}

void Path(Tnode *who, char store[], int now) {
    if (who == NULL) {
        return;
    }

    if (who->Lchild == NULL && who->Rchild == NULL) {
        printf("%c:%s\n", who->num, store);
    } else {
        store[now] = who->num;
        store[now + 1] = '\0';
    }

    Path(who->Lchild, store, now + 1);
    Path(who->Rchild, store, now + 1);
}

int main ()
{
    Tnode *Root;
    int level;
    Root =  Create_tree();
    //scanf("%d",&level);
    //count_tree(Root,level);
    //int ret=0;
    //COUNT(Root, 1, level, &ret);
    //printf("%d\n", ret);
    char store[100] = {0};
    Path(Root, store, 0);
    return 0; 
}
