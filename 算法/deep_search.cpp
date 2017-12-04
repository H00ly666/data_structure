/*************************************************************************
	> File Name: deep_search.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月03日 星期日 19时20分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

int  book[101]={0},sum=0,n=0,e[101][101]={0};
void dfs(int cur)
{
    int  i;
    cout << cur;
    sum++;//每访问一个顶点,sum 就加一
    if(sum == n)    return ; //访问完了，就直接退出

    for(i=1;i<=n;i++)
    {
        //判断当前定点cur到顶点i是否有路，并判断是否访问过
        if(e[cur][i]==1 && book[i]==0 ){ 
            book[i] =1;
            dfs(i);
        }
    }
    return ;
}

int main()
{
    int  i,j,m,a,b;
    cin >> n >> m;
    //初始化二维矩阵
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j) e[i][j]=0; // 对角线置为0
            else  e[i][j]=99999999;  //没有路为
    //读入顶点之间的边
    for(i=1;i<=m;i++)
    {
        cin >> a >> b;
        e[a][b]=1;
        e[b][a]=1;
    }
    book[1]=1;
    dfs(1) ;

    getchar();

}
