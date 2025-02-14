#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2010;
ll dist[N];
vector<pair<int,int>>num[N];
queue<int>q;
int n,m,a,b,c;
bool visit[N];
int h[N]={-1};
int pointer[N],value[N];
int cnt[N];
int idx;
/* void add()
{
  value[idx]=b;
  pointer[idx]=h[a];
  h[a]=idx;
  idx++;
} */
bool spfa()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    visit[i]=1;
    q.push(i);
  }
  while(m--)
  {
    cin>>a>>b>>c;
    num[a].push_back({b,c});
    //add();
  }
  
  while(!q.empty())
  {
    int i=q.front();
    visit[i]=0;
    q.pop();
    for(auto[x,y]:num[i])
    {
      if(dist[x]>dist[i]+y)
      {
        dist[x]=dist[i]+y;
        if(visit[x])
        {
          continue;
        }
        cnt[x]=cnt[i]+1;
        if(cnt[x]>=n)//当一个点被修改超过n次,说明存在负环使环值不断减小
        {
          return true;
        }
        visit[x]=1;
        q.push(x);
      }
    }
  }
  return false;
}
void solve()
{
  if(spfa())
  {
    cout<<"Yes"<<endl;
  }
  else
  {
    cout<<"No"<<endl;
  }
}
signed main()
{
  int t=1;
  while(t--)
  {
    solve();
  }
  return 0;
}