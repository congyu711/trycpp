#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    A() = default;
    A(const A & rhs){
        cout << "copy constructor" << endl;
    }
    A(A && rhs){
        cout << "move constructor" << endl;
    }
};
auto func()
{
    A a;
    int sum=0;
    for(int i=0;i<100;i++)
    {
        sum+=i;
    }
    return a;
}

int main()
{
    vector<A> arr;
    A tmp;
    arr.reserve(20);
    arr.emplace_back(tmp);
    arr.emplace_back(func());
}