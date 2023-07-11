
// https://www.bilibili.com/video/BV1et4y1D796/?spm_id_from=333.999.0.0&vd_source=c89a52f2b49ba922342893d20c245ddd
// problem 3. strange!!!!
#include<bits/stdc++.h>
using namespace std;

void print(int num)
{
    cout<<"this\n";
    cout<<num;
}
template<class T>
void use(T t)
{
    cout<<"sdf "<<t<<endl;
    print(t);
}
void print(double num)
{
    cout<<"that\n";
    cout<<num;
}

int main()
{
    use(10.5);

}