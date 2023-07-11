// https://www.bilibili.com/video/BV1Zo4y1c7bY

#include<bits/stdc++.h>
using namespace std;

bool flag=0;
void* operator new(size_t sz)
{
    if(flag)    cout<<"aaaaa"<<sz<<'\n';
    return malloc(sz);
}

int main()
{
    map<string, int> mp{{"llllllllllllllong string",1}};
    flag=1;
    if(mp.find("llllllllllllllong string")!=mp.end())
        cout<<"found\n";
}