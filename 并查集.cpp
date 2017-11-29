/*************************************************************************
	> File Name: 并查集.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月19日 星期日 22时31分46秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>


using namespace std;

int  pre[1010];  //全是掌门　
int  unionsearch(int  root)
{
    int  son,tmp;
    son = root;
    while (root != pre[root]) //寻找掌门ing
        root = pre[root];
    
    while (son != root)
    {
        tmp = pre[root];
        pre[son] = root; //将所有人的上级设成掌门
        son = tmp;
    }
    return root;  //掌门驾到~
}
void join(int root1, int  root2)
{
    int x,y;
    x = unionsearch(root1);
    y = unionsearch(root2);
    if(x != y){
        pre[x] = y;   //此处感觉这种路径压缩方式　需要面对具体问题进行调整呢
    } 
}


int main ()
{
    int num,road,total,i ,start,end,root1,root2;
    while(scanf("%d%d",&num,&road )  && num ){
        
        total = num-1;    //共 num-1 个门派
        for(i=1 ; i <=num ; i++){
            pre[i] = i;
        }
        while(road--){
            scanf("%d%d",&start,&end ); //他俩要结结拜
            root1 = unionsearch(start);
            root2 = unionsearch(end);
            if(root1 != root2)    //掌门不同要结拜
            {
                pre[root1] = root2;
                total--;       //门派少一个，敌人要建立的路就要少一个
            }
        
        }
        printf("%d\n",total); //天下局势　，还剩几个门派

    }
    return 0;

}
