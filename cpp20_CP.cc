// https://zhuanlan.zhihu.com/p/600061993

#include<bits/stdc++.h>
#include<ranges>
using namespace std;
using namespace ranges;



int main()
{
    auto dfs=[](auto &&dfs, int x) -> void
    {
        if(x>=20)   return;
        cout<<x<<'\n';
        dfs(dfs, x+1);
    };
    dfs(dfs,10);
}