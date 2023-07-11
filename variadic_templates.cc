// Variadic templates in C++
// https://eli.thegreenplace.net/2014/variadic-templates-in-c/

#include<bits/stdc++.h>
using namespace std;



int adder(int&& v) {
  return v;
}

template<typename... Args>
int adder(int&& first, Args&&... args) {
  return first + adder(std::forward<Args>(args)...);
}

int main()
{
    cout<< adder(1,2,3,4)<<endl;
}