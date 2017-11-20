/*************************************************************************
	> File Name: huff.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月20日 星期一 21时11分48秒
 ************************************************************************/

#include<stdio.h>
#include<stdio.h>
#define  N 30
#define  M 2*N-1
typedef  struct{
    int  weight;
    int parent,Lchild,Rchild;
}HTnode, HuffmanTree[M+1];



void  create_tree(Huff ht, int  w,int  n)
{
    m = 2*n-1;
    for (i=1;i<=n;i++) ht[i] = {w[i],0,0,0 };
    for (i=n+1;i<=m;i++)  ht[i] = {0,0,0,0};
    for(i =n+1; i<=m;i++)
    {
        select(ht,i-1,&s1,&s2);
        ht[i].weight = ht[s1].weight +ht[s2].weight;
        ht[i].Lchild = s1; ht[i].Rchild = s2;
        ht[s1].parten = i; ht[s2].parten = i;
    }
}
int main ()
{



}
