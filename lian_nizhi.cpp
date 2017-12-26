/*************************************************************************
	> File Name: lian_nizhi.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2017年12月19日 星期二 17时18分20秒
 ************************************************************************/

#include<iostream>
#include<netinet/in.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<assert.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef struct str
{
    int  num;
    struct str *next;
}Node;
Node *create(Node *Head)
{
    Node *ptr,*end = Head;
    ptr = new Node;
    while (cin >> ptr->num && ptr->num !=0 ){
        end->next = ptr;
        end = ptr;
        ptr = new Node;
    }        
    end->next = NULL;
    return  Head;
}
void print(Node *Head) 
{
    Node *temp = Head->next;
    while(temp != NULL){
        cout << temp->num << " "  ;
        temp = temp->next;
    }
}
Node *nizhi(Node *Head,int k)
{
    int cnt=0;
    Node *new1 = Head->next,*old,*tmp;
    Node *ppp = Head->next;        
    while(cnt < k){
        tmp = old->next;
        old->next = new1;
        new1 = old;
        old = tmp;
        cnt++;
    }
    Head->next = new1;
    ppp->next = old;

    return  Head;
}
int main()
{
    Node *Head;
    Head = new Node;
    create(Head);
   // print(Head);
    nizhi(Head,6);
    print(Head);
}
