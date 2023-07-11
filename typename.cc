#include<bits/stdc++.h>
using namespace std;

template<typename T>
class base
{
public:
    using pTT=pair<T,T>;
};

template<typename T>
class derived: public base<T>::pTT
{
public:
    derived(int x,int y): base<T>::pTT(x,y)
    {

    }
    void print()
    {
        cout<<"derived\n";
    }
};
int main()
{
    derived<int> a(1,1);
    a.print();
}