#include<bits/stdc++.h>
#include<ranges>

using namespace std;


int main()
{
    mt19937 gen;
    int n=1e8;
    #pragma omp parallel for
    for(int i=0;i<7;i++)
    {vector<int> arr(n);
    for(auto &e:arr)    e=gen();
    ranges::sort(arr);}
    
}

