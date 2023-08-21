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
pair<A,A> func2()
{
    A a,b;
    int sum=0;
    for(int i=0;i<100;i++)
    {
        sum+=i;
    }
    pair<A,A> tmp{a,b};
    return tmp;
}

int main()
{
    vector<A> arr;
    A tmp;
    arr.reserve(20);
    // arr.emplace_back(tmp);
    // arr.emplace_back(func());
    arr.emplace_back(std::move(func2().second));
}