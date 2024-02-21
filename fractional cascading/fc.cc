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

struct fc
{
    vector<vector<int>> fcarr,fcl,fcr,flags;    // flag: 0 -- l_i; 1-- l_{i+1}'
    fc(const vector<vector<int>>& arr)
    {
        fcarr.push_back(arr[0]);
        fcl.push_back(vector<int>(arr[0].size(),0));
        fcr.push_back(vector<int>(arr[0].size(),0));
        flags.push_back(vector<int>(arr[0].size(),0));

        for(int i=1;i<arr.size();i++)
        {
            // merge lists
            vector<int> tmp;
            for(int _=0;_<fcarr.back().size();_+=2)
                tmp.push_back(fcarr.back()[_]);
            vector<int> res;
            res.resize(tmp.size()+arr[i].size());
            ranges::merge(tmp,arr[i],res.begin());
            // maintain pointers to left and right for different types...
            
        }
    }
    vector<int> search(int x)
    {
        // ...
    }
};

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
    // build fc

    while (q--)
    {
        int x;
        cin>>x;
        

    }
    ct::set_ed();
    cout<<ct::elapse_ms();
}