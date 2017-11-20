/*************************************************************************
	> File Name: huffman.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月20日 星期一 11时07分36秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;

#define  Nchar 8
#define  Nsymbols 1<<Nchar
typedef vector<bool> Huff_code;
map<char, Huff_code> Huff_Dic;

class HTree
{
    public:
        HTree* left;
        HTree* right;
        char ch;
        int  weight;

        HTree(){left = right = NULL; weight = 0;ch  = '\0'; }
        HTree(HTree *l,HTree *r,int w,char c){left = l; right = r; weight = w; ch = c; }
        ~HTree(){delete left; delete  right;}
        
        bool Isleaf()  { return !left && !right; }
};
class Compare_tree
{
    public :
        bool operator() (HTree* t1,HTree* t2)
        {
            return t1->weight > t2->weight;
        }
};

HTree *BuildTree (int  *frequency)
{
    priority_queue<HTree*,vector<HTree*>,Compare_tree> QTree;
    
    //1st level add  character;
    for (int i=0;i<Nsymbols;i++)
    {
        if(frequency[i])
            QTree.push(new HTree(NULL, NULL,frequency[i] ,(char) i  ));
    }

    //build 
    while(QTree.size() >1)
    {
        HTree* lc = QTree.top();
        QTree.pop();
        HTree *rc = QTree.top();
        QTree.pop();

        HTree*parent = new  HTree(lc,rc,lc->weight +rc->weight,(char)256 );
        QTree.push(parent);
    }
    return QTree.top();
}
int  main()
{
    int freq[Nsymbols] = {0};
    char *str = "this is the string  need to be  compressed";

    //static  character  frequency
    while(*str != '\0')
        freq[*str++]++;

    //build  tree
    HTree *r  = BuildTree(freq);
    Hudd_code  nullcode;
    nullcode.clear();
    Huffman_coding(r, nullcode);

    for(map<char,Huff_code >::iterator it  = Huff_Dic.begin(); it != Huff_Dic.end(); it++)
    {
        cout<<(*it).first<<'\t';
        std::copy(it->second() ,it->second.end(),std::ostream_iterator<bool>(cout));
        cout<<endl;
    }
}
















