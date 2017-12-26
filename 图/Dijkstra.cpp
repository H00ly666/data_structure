/*************************************************************************
	> File Name: Dijkstra.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2017年12月26日 星期二 21时12分06秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int  e[10][10],dis[10],book[10],i,j,n,m,t1,t2,t3,u,v,min;
    int  inf= 99999999;  //目前没有解决负权环的问题
    cin >> n>>m;
    //图的初始化
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            if(i==j) e[i][j]=0;
            else e[i][j] = inf;
    }
    //初始化dis数组 这里是1号顶点到其余各个顶点的初始路程
    for(i=1;i<=n;i++)
        dis[i]=e[1][i];

    //book数组的初始化
    for(i=1;i<=n;i++)
        book[i] = 0;
    book[1] = 1;
    //dijkstra 算法核心语句
    for(i=1;i<=n;i++){
        //找到离一号最近的顶点
        min = inf;
        for(j =1; j<=n;j++){
            if(book[j]==0&&dis[j]<min){
                min = dis[j];
                u = j;
            }
        }
        book[u]=1;
        for(v=1;v<=n;v++){
            if(e[u][v]<inf){
            /    if(dis3[v]>dis[u]+e[u][v])
                    dis[v]=dis[u]+e[u][v];
            }
        }
    }
    for(i=1;i<=n;i++){
        cout << dis[i];
    }





}


