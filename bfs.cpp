/* 青蛙跳杯子

题目描述
X
X 星球的流行宠物是青蛙，一般有两种颜色：白色和黑色。

X
X 星球的居民喜欢把它们放在一排茶杯里，这样可以观察它们跳来跳去。

如下图，有一排杯子，左边的一个是空着的，右边的杯子，每个里边有一只青蛙。

∗
W
W
W
B
B
B
∗WWWBBB

其中，
W
W 字母表示白色青蛙，
B
B 表示黑色青蛙，
∗
∗ 表示空杯子。

X
X 星的青蛙很有些癖好，它们只做 3 个动作之一：

跳到相邻的空杯子里。

隔着 1 只其它的青蛙（随便什么颜色）跳到空杯子里。

隔着 2 只其它的青蛙（随便什么颜色）跳到空杯子里。

对于上图的局面，只要 1 步，就可跳成下图局面：

W
W
W
∗
B
B
B
WWW∗BBB

本题的任务就是已知初始局面，询问至少需要几步，才能跳成另一个目标局面。

输入描述
输入为 2 行，2 个串，表示初始局面和目标局面。我们约定，输入的串的长度不超过 15。
 */
/* 输出描述
输出要求为一个整数，表示至少需要多少步的青蛙跳。

输入输出样例
示例
输入

*WWBB
WWBB*
copy
输出

2 */



#include <bits/stdc++.h>
using namespace std;
string start,end_start;
map<string,int>mp;
int vis[6]={-1,-2,-3,1,2,3};
int bfs()
{
  mp[start]=0;
  queue<string>q;
  q.push(start);
  while(!q.empty())
  {
    string s=q.front();
    q.pop();
    int cnt=mp[s];
    int pos=s.find('*');
    for(int i=0;i<6;i++)
    {
      int x=pos+vis[i];
      if(x>=0&&x<start.size())
      {
        swap(s[x],s[pos]);
        if(!mp.count(s))
        {
          mp[s]=cnt+1;
          if(s==end_start)
          {
            return mp[s];
          }
          q.push(s);
        }
        
        swap(s[x],s[pos]);
      }
    }
  }
}
int main()
{
  cin>>start;
  cin>>end_start;
  cout<<bfs()<<endl;
  return 0;
}