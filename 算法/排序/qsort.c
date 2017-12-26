/*************************************************************************
	> File Name: qsort.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月13日 星期一 21时36分17秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define num 5
int  mycompara(const void  *elem1,const  void *elem2)
{
    unsigned int  *p1,*p2;
    p1 = (unsigned int *) elem1;
    p2 = (unsigned int *) elem2;
 //   return (*p1%10)-(*p2%10);
    return  *p1-*p2;
    //返回值大于０，２在前
    //　　　小于零，１在前
    //等于零　　原样输

}
int main()
{
    unsigned int an[num] = {8,123,11,12,4};
    qsort(an,num,sizeof(unsigned int ), mycompara);
    for(int i= 0 ; i<num ; i++){
        printf("%d ",an[i]);
   }
    return 0;
}
