//现在手头上有面值分别为x,y,z的硬币,输入一个数值n,请问有多少种凑成x的方式
#include<iostream>
#include<vector>
using namespace std;
int x,y,z,n;
signed main()
{
    cin>>x>>y>>z>>n;
    vector<int>dp(n+1);//创建一个dp数组,dp[i]表示能凑出i面值的方法数
    dp[0]=1;//表示能凑出0面值只有一种方法:不用任何硬币
    for(auto num :{x,y,z})
    {
        for(int j=num;j<=n;j++)
        {
            dp[j]=dp[j]+dp[num-j];
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}