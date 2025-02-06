#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
  int vec1,vec2;
  int weight;
  bool operator<(const node & b)const{
    return weight<b.weight;
  }
}vec[N];
int record[N];
int find(int num)
{
  if(num!=record[num])
  {
    record[num]=find(record[num]);
  }
  return record[num];
}
int main()
{
  int n,m;
  cin>>n>>m;
  
  for(int i=1;i<=n;i++)
  {
    record[i]=i;
  }
  for(int i=1;i<=m;i++)
  {
    cin>>vec[i].vec1>>vec[i].vec2>>vec[i].weight;
  }
  sort(vec+1,vec+1+m);
  
  long long wec=0;
  int cnt=0;
  for(int i=1;i<=m;i++)
  {
    int u=find(vec[i].vec1);
    int v=find(vec[i].vec2);
    if(u!=v)
    {
      wec+=vec[i].weight;
    
      record[v]=u;
      
      cnt++;
    }
  }
  if(cnt==n-1)
  {
    cout<<wec<<'\n';
  }
  else
  {
    cout<<"impossible"<<'\n';
  }
  return 0;
}