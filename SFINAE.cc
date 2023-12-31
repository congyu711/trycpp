#include<iostream>
typedef char (&yes)[1];
typedef char (&no)[2];

template <typename B, typename D>
struct Host
{
    operator B *() const;
    operator D *();
};

template <typename B, typename D>
struct is_base_of
{
    template <typename T>
    static yes check(D *, T);
    static no check(B *, int);

    static const bool value = sizeof(check(Host<B, D>(), int())) == sizeof(yes);
};

// Test sample
class Base
{
};
class Derived : private Base
{
};
int main()
{
    std::cout<<is_base_of<Base,Derived>::value;
}