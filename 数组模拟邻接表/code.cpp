#include<iostream>
using namespace std;
//注意:用数组模拟邻接表开的数组大小应该是结点数的两倍!
const int n=1e6+10;
int h[n]={-1};//表示竖着的那个邻接表的头,就像单链表的头
int value[n];//表示插入的结点值
int index;//表示索引
int pointer[n];//指向下一个结点
void add(int a,int b)
{
    value[index]=b;
    pointer[index]=h[a];//相当于头插
    h[a]=index;
    index++;
}
//建立无向表的邻接表
signed main()
{
    int N;
    cin>>N;
    
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
}