#include<iostream>
using namespace std;

// function template partial specialization is not allowed

template<typename RT, typename T1, typename T2>
RT max(T1 const &x, T2 const &y)
{
    return x>y?x:y;
}


int main()
{
    // but you can do this.
    cout<<::max<int>(3.1,4.2)<<endl;
}