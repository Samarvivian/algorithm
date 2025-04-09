ll cacl()
{
  ll num=n;
  ll x=2;
  while(x*x<=n)
  {
    if(n%x==0)
    {
      num-=num/x;
      while(n%x==0)
      {
        n/=x;
      }
    }
    x++;
  }
  //这一步并不是因为n原本是一个质数,而是因为经过上述循环之后
  //即使n不是质数,也变成了质数
  //所以需要num-=num/n
  if(n>1)
  {
    num-=num/n;
  }
  return num;
}
