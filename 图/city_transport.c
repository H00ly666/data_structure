/*************************************************************************
	> File Name: city_transport.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月27日 星期一 08时54分03秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define  MAXVEX  20
#define  INFINITY 32768
typedef struct  {
    int num;
    int  name[20];
}Vextype;
typedef struct {
    int  arcs[MAXVEX][MAXVEX];
    Vextype vex[MAXVEX];
    int  vexnum;
    int  arcnum;   
}AdiMatrix;
int create(AdiMatrix *G)
{
    int  i,j,k,weight;
    char city[20];
    printf("请输入交通图的城市数目和路线数目(citynum,cutnum):\n");
    scanf("%d,%d",&G->vexnum,&G->arcnum);
    for(i=1;i<=G->vexnum;i++)
        for(j=1;j<=G->vexnum;j++)
            G->arcs[i][j] = INFINITY;

}


int  main()
{
    
}
