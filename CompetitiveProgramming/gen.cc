// generate instances

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    mt19937 gen(atoi(argv[1]));
    const int n=100;
    cout<<n<<'\n';
    for(int i=0;i<n;i++)
    {
        cout<<gen()%200<<' '<<gen()%200<<'\n';
    }
}