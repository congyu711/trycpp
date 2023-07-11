#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> values{1,2,3,4,5};
    auto it=find(values.begin(),values.end(),3);
    values.insert(it, 100);
    for(auto e:values)  cout<<e<<' ';cout<<'\n';
}