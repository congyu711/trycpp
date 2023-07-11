#include <bits/stdc++.h>
#include <utility>

struct A
{
    A() /*noexcept*/ {
        std::string str;
        str.resize(0);
    }
};

template <typename T>
struct Holder
{
    T value;

    template <typename... Args>
    Holder(Args &&...args) noexcept(noexcept(T(std::forward<Args>(args)...))): value(std::forward<Args>(args)...) {}
};

template <typename U>
Holder(U &&)->Holder<std::remove_reference_t<U>>;

int main()
{
    std::cout<<noexcept(A())<<std::endl;
    std::cout<<noexcept(Holder<A>())<<std::endl;
    std::cout<<noexcept(Holder(64))<<std::endl;
}