#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec={1,2,3,4,5};
    for(auto e:vec) cout<<e<<' ';   cout<<endl;
    for(auto e:vec|views::reverse) cout<<e<<' ';    cout<<endl;
}