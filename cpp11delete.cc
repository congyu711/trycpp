#include<bits/stdc++.h>
using namespace std;

class A
{
    int a;
public:
    A(const A &a)=delete;
    A(A &&a)=delete;
    A(int i):a(i){}
};

int main()
{
    A a=A(5);
    A b(5);
    a=b;
}