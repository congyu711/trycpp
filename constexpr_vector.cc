#include <bits/stdc++.h>


template <auto val>
constexpr void static_print()
{
#if !defined(__GNUC__) || defined(__clang__)
    int static_print_is_implemented_only_for_gcc = 0;
#else
    int unused = 0;
#endif
};

constexpr int testVector(int n)
{
    std::vector<int> vec(n, 0);
    int j = 0;
    for (auto &e : vec | std::views::reverse)
    {
        e += ++j;
    }
    std::ranges::sort(vec);
    
    int sum = 0;

    for (auto &elem : vec)
        sum += elem;

    return sum;
}

int main()
{
    // static_assert(testVector(10));
    static_print<testVector(1000)>();
    // std::cout<<__PRETTY_FUNCTION__<<'\n';
    std::cout << "good\n";
}