#include<iostream>
using namespace std;
int n;
int num[20];
signed main()
{
    cin>>n;
    num[1]=1;
    num[2]=2;
    for(int i=3;i<=n;i++)
    {
        num[i]=num[i-1]+num[i-2];
    }
    cout<<num[n]<<endl;
    return 0;
}