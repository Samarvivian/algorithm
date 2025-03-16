#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
// ��x, y��ʹ��ax + by = gcd(a, b)
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1; y = 0;
        return a;   //����ݹ�߽翪ʼ����һ�㷵��
    }
    int d = exgcd(b, a % b, x, y);
    int temp=y;    //�Ƴ���һ���x��y
    y=x-(a/b)*y;
    x=temp;
    return d;
}
int main()
{
	int a,b,x,y;
	cin>>a>>b;
	int d=exgcd(a,b,x,y);
	printf("%d*%d+%d*%d=%d",a,x,b,y,d);
	return 0;
}
