/*************************************************************************
	> File Name: Floyd_warshall.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月14日 星期四 20时03分07秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int  e[10][10];
    int t1,t2,t3;
    int n,m,i,j,k;
    int inf = 999999; //代表正无穷 不能设成2147483647
    cin >> n >> m;   // n 顶点　m 边数
    for(int  i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            if(i==j) e[i][j] = 0;
            else     e[i][j] = inf;
    //读入边
    for(i=1;i<=m ;i++){
        cin >> t1 >> t2 >> t3;
        e[t1][t2] = t3;
    }
    //核心算法
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            cout<<e[i][j]<<" ";
        cout<< endl;
    }
    for(k = 1; k<=n ;k++){
        for(i=1; i<=n;i++)
            for(j=1; j<=n;j++)
                if(e[i][j] > e[i][k]+ e[k][j])
                    e[i][j] = e[i][k]+e[k][j];                    
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            cout<<e[i][j]<<" ";
        cout<< endl;
            
    }
        cout<<endl;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            cout<<e[i][j]<<" ";
        cout<< endl;
    }
}
