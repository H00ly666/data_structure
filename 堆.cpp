/*************************************************************************
	> File Name: 堆.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月30日 星期四 22时21分19秒
 ************************************************************************/

#include<iostream>
using namespace std;
int  h[101]; //用数组来存放堆
int  n; //堆的大小

void  swap(int x, int  y)
{
    int  t;
    t=h[x];
    h[x] = h[y];
    h[y] = t;
    return;
}
//
void  siftdown(int  i)
{
    int t,flag=0;  //flag用来标记是否需要继续向下调整
    //当i 节点有儿子（至少为左儿子）
    while(i*2 <=n && flag ==0 )
    {
        //首先判断它与左儿子的关系并用t记录值较小的节点编号
        if(h[i] > h[i*2])
            t=i*2;
        else
            t=i;
        //如果他有右儿子
        if(i*2+1 <=n )
        {
            //如果右儿子的值更小,更新较小节点的标号
            if(h[t]>h[i*2+1] )
                t= i*2+1;
        }
        //如果发现最小的节点编号不是自己,说明子节点中有比父节点更小的
        if(t!=i)
        {
            swap(t,i);
            i=t;//更新i为刚才与它交换的儿子节点的编号,便于接下来继续向下调整
        }
        else
            flag =1;
    }
    return;

}
//建立堆的函数
void creat()
{
    int  i;
    for (i=n/2 ; i>=1;i--)
    {
        siftdown(i);
    }
    return;
}
//删除最大的元素
int deletemax()
{
    int  t;
    t = h[1];
    h[1] = h[n];
    n--;
    siftdown(1);
    return t;
}



int main ()
{
    int  i,num;
    cin >> num;
    for (i=1;i<=num;i++)
        cin >> h[i];
    n = num;

    creat();

    for(i=1;i<=num;i++)
        cout << deletemax() << " ";
    cout << endl;



}
