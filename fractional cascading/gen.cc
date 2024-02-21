#include<bits/stdc++.h>
#include<ranges>
using namespace std;

int main()
{
    const int n=10;
    const int k=10;
    mt19937 gen;
    cout<<n<<' '<<k<<'\n';
    vector<vector<int>> vec(k,vector<int>(n));
    for(auto &e:vec)
    {
        for(auto &ee:e) ee=gen()%5000;
        ranges::sort(e);
    }
    for(auto e:vec)
    {
        for(auto ee:e)  cout<<ee<<' ';
        cout<<'\n';
    }
    const int q=5;
    cout<<q<<'\n';
    for(int i=0;i<q;i++)
        cout<<gen()%5000<<' ';
}