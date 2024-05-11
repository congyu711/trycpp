#include <generator>
#include <iostream>
#include <ranges>

template <typename T>
struct Tree
{
    T value;
    Tree *left{},*right{};
    std::generator<const T&> inorder() const
    {
        if(left)
            co_yield std::ranges::elements_of(left->inorder());
        co_yield value;
        if(right)
            co_yield std::ranges::elements_of(right->inorder());
    }
};

int main()
{
    Tree<char> tree[]
    {
                                    {'D', tree + 1, tree + 2},
        //                            │
        //            ┌───────────────┴────────────────┐
        //            │                                │
                    {'B', tree + 3, tree + 4},       {'F', tree + 5, tree + 6},
        //            │                                │
        //  ┌─────────┴─────────────┐      ┌───────────┴─────────────┐
        //  │                       │      │                         │
          {'A'},                  {'C'}, {'E'},                    {'G'}
    };
 
    for (char x : tree->inorder())
        std::cout << x << ' ';
    std::cout << '\n';
}