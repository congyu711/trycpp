#include<iostream>
#include<ranges>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    vector<int> vec(10); int cnt=0;
    for(auto &e:vec)    e=cnt++;
    sort(vec.begin(),vec.end());
    for(auto e:vec) cout<<e<<' ';cout<<"\n";
    ranges::sort(views::reverse(vec));
    for(auto e:vec) cout<<e<<' ';cout<<"\n";
    auto u=views::reverse(vec);
    for(auto e:u) cout<<e<<' ';cout<<"\n";
    auto v = vec | views::filter([](auto const i){return i%5==0;})| views::transform([](auto const i){return i*i;});
    for(auto e:v)   cout<<e<<' ';puts("");
    *u.begin() = 42;
    for(auto e:u)   cout<<e<<' ';puts("");

}