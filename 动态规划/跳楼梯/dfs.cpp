#include<iostream>
using namespace std;
int n;
int dfs(int num)
{
    if(num==1)  return 1;
    if(num==2)  return 2;
    else return dfs(num-1)+dfs(num-2);
}
signed main()
{
    cin>>n;
    cout<<dfs(n)<<endl;
    return 0;
}