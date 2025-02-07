typedef long long ll;
ll cacl(ll a,ll b,ll c)
{
    ll ans=1;
    a%=c;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%c;
        }
        b/=2;
        a=a*a%c;
    }
    return ans;
}