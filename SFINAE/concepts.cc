#include <bits/stdc++.h>

namespace memcheck
{
    template <class T>
    concept has_reset = requires(T t) { t.reset(); };
}

template <memcheck::has_reset T>
void call(T &&t)
{
    t.reset();
    std::cout << "has" << std::endl;
}

template <class T>
void call(T &&t)
{
    std::cout << "no" << std::endl;
}

struct withreset
{
    void reset()
    {
    }
};
struct withoutreset
{
};
int main()
{
    withreset a;
    withoutreset b;
    call(a);
    call(b);
}