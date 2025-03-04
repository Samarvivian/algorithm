# 问题
把 1∼n
 这 n
 个整数排成一行后随机打乱顺序，输出所有可能的次序。

输入格式
一个整数 n
。

输出格式
按照从小到大的顺序输出所有方案，每行 1
 个。

首先，同一行相邻两个数用一个空格隔开。

其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面。

数据范围
1≤n≤9

输入样例：
3
输出样例：
1 2 3
# 代码
```#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n;
int res[20];
vector<int>vec;
void cacl(int cnt)
{
    if(cnt>n)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ",vec[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
       if(res[i])
       {
           continue;
       }
       vec.push_back(i);
       res[i]=i;
       cacl(cnt+1);
       vec.pop_back();
       res[i]=0;
    }
}
int main()
{
    cin>>n;
    cacl(1);
    return 0;
}

```
# 计算时间复杂度
第一层循环是n   
第二层循环是n*n   
第三层循环是n*(n-1)*n  
第四层循环是n*(n-1)*(n-2)*n
依次类推
总和为n*(1+n+n*(n-1)+n*(n-1)*(n-2)+~+n!)  
通过放缩,可以得到时间复杂度为(n*n!)