#include<bits/stdc++.h>
#include<chrono>
#include<ranges>
#include<functional>
using namespace std;
namespace ct    // count time
{
    using namespace chrono;
    auto st = system_clock::now();
    auto ed = system_clock::now();
    auto set_st()
    {
        st = system_clock::now();
    }
    auto set_ed()
    {
        ed = system_clock::now();
    }
    auto elapse_s(){
        return duration_cast<seconds>(ed-st);
    }
    auto elapse_ms()
    {
        return duration_cast<milliseconds>(ed-st);
    }
}


int main()
{
    int n,k,q;
    cin>>n>>k;
    vector<vector<int>> vec(k,vector<int>(n));
    for(auto &e:vec)
    {
        for(auto &ee:e) cin>>ee;
    }
    cin>>q;
    cout<<q<<endl;
    ct::set_st();
    while (q--)
    {
        int x;
        cin>>x;
        for(auto &e:vec)
        {
            auto p=ranges::lower_bound(e,x);
            cout<<(p-e.begin())<<' ';
        }
        cout<<'\n';
    }
    ct::set_ed();
    cout<<ct::elapse_ms();
}