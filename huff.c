/*************************************************************************
> File Name: huff.c
> Author: 刘嘉辉
> Mail: 
> Created Time: 2017年11月20日 星期一 21时11分48秒
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef  struct node {
    char a;
    int  weight;
    struct node  *left;
    struct node  *right;

}Htree;
typedef struct ch{
    char c;
    int  *pp;
}Node;
//创建哈弗曼树
Htree * create_tree(int A[]  ,int  n)
{
    Htree *q;
    Htree **B; //存放叶子节点的数组

    int  min=-1,next_min;

    //将数据存储在空间里
    int i ,j;
    B = (Htree **) malloc(n*sizeof(Htree *));
    for (  i=0 ;i<n;i++){
        B[i] = (Htree *)malloc(sizeof(Htree) ) ;
        B[i]->weight = A[i];
        B[i]->left = B[i]->right = NULL;
        
    }
    //循环n-1次进行建立哈弗曼树

    for(i=1; i<n ; i++){
       min=-1;
//        next_min;
        //对最小　次小进行初始化
        for(j=0;j<n;j++){
            if(B[j]!= NULL && min == -1  )  //特别要注意条件的设置
            {
                min = j;
                continue;
            }
            if(B[j]!=NULL)
            {
                next_min = j;
                break;
            }
        }
        //遍历整个数组找出最小和次最小 以下有两种方式
        /*  
        int temp;
        if (B[min]->weight > B[next_min]->weight) {
            temp=min;min=next_min;next_min=temp;
        }
        //printf("min=%d next_min=%d\n",min,next_min );
        for(j=0;j<n;j++)
        {
            if(B[j] != NULL ){
                if( B[j]->weight < B[min]->weight )
                {
                    next_min=min;
                    min=j;
                } else if (B[j]->weight<B[next_min]->weight && j!=min) {
                    next_min=j;
                }
            
            }
        }
        */
        for  (j = next_min ; j<n; j++)
        {
            if(B[j] != NULL )
            {
                if(B[j]->weight < B[min]->weight )
                {
                    next_min = min;
                    min = j;    //首次时相当于min和 next_min发生了交换　非常精简
                    
                }    
                else if(B[j]->weight < B[next_min]->weight )
                    next_min = j;
            }
        }


        //生成新节点进行赋值
        q = (Htree *) malloc (sizeof(Htree));
        q->weight = B[min]->weight + B[next_min]->weight;
        q->left = B[min];
        q->right = B[next_min];

        B[min] = q;
        B[next_min] = NULL;

        for(int  k =0;k<n;k++)
        {
            if(B[k])
                printf("%d ",B[k]->weight);
            else
                printf("NULL ");
        }

        printf("\n");

    }
    free(B);
    return q;
}
void visit_Htree(Htree *TT)
{
    if(TT != NULL)
    {
        printf("%d ",TT->weight );
        visit_Htree(TT->left);
        visit_Htree(TT->right);

    }

}
//哈弗曼编码
void Huffmancoding(Htree *TT,int  len)
{
    static int code[10];
    if(TT != NULL)
    {
        if(TT->left == NULL && TT->right ==NULL)
        {
            printf("%d 处的哈弗曼编码为:",TT->weight);
            int  j=0;
            for ( j= 0;j<len;j++)
                printf("%d", code[j]);
            printf("\n");
        

        }
        else  //进入节点之后　进左右之前分别存储０或１
        {
            code[len] = 0;
            Huffmancoding(TT->left, len+1);
            code[len] = 1;
            Huffmancoding(TT->right, len+1);
        }

    }
}

int main ()
{
    Htree *TT;
    //申请存放权值的空间
    int *A;
    int n;
    while (1){
        scanf("%d",&n);
        if(n  > 1)
        break;
    }
    A = (int *) malloc(sizeof(int) * n);
    for (int i=0; i<n ; i++){
        scanf("%d",& A[i]);
    }
    
    
    
    //创建哈弗曼树  还需加一条字符数组进行辨认
    TT = create_tree(A,n);
    visit_Htree(TT);
    printf("\n");
    //哈弗曼编码
    Huffmancoding(TT,0);

}
