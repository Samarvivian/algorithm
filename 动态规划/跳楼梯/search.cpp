#include<iostream>
using namespace std;
int n;
int mem[20];
int dfs(int num)
{
    
    if(mem[num])  return mem[num];
    int sum=0;
    if(num==1)  sum=1;
    else if(num==2)  sum=2;
    else sum=dfs(num-1)+dfs(num-2);
    mem[num]=sum;
    return sum;
}
signed main()
{
    cin>>n;
    cout<<dfs(n)<<endl;
    return 0;
}