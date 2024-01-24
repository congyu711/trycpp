// https://catcheroftime.github.io/blog/2020-10/%E5%AE%89%E5%85%A8%E7%9A%84%E5%B8%83%E5%B0%94%E7%B1%BB%E5%9E%8B%E8%BD%AC%E5%8C%96/
// https://www.zhihu.com/question/556235823/answer/2694454762

// well i think the complicated nested class method in the first link above is not really necessary anymore... we already have explicit operator bool after c++11

#include<iostream>
using namespace std;

struct safebool
{
    operator bool() const
    {
        return true;
    }
    const safebool& operator<< (int x) const
    {
        cout<<"fake operator<<"<<endl;
        return *this;
    }

    friend ostream& operator<<(ostream& x,const safebool &sb)
    {
        x<<"real operator<<"<<endl;
        return x;
    }
};

const safebool sb;
int main()
{
    auto c=sb>>1;
    cout<<(sb<<1)<<endl;
}