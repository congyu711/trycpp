// https://www.zhihu.com/question/307786707
// magic::IsConstructible<A, "para types">{}
// type traits deciding whether A has a constructor with para types
#include <bits/stdc++.h>
namespace detail
{
    template <class T, class... Args>
    auto IsConstructibleImpl(int)
        -> decltype(T(std::declval<Args>()...), std::true_type{}); // (1)

    template <class T, class...>
    auto IsConstructibleImpl(...) -> std::false_type; // (2)

} // namespace detail

namespace magic
{
    template <class T, class... Args>
    struct IsConstructible
        : public std::integral_constant<
              bool, decltype(detail::IsConstructibleImpl<T, Args...>(0))::value>
    {
    };
}
/*
odr-used 是什么？为什么会存在这样的概念 https://www.zhihu.com/question/307786707/answer/2292443914
/// truth's comment ///
我参考了标准ISO/IEC 14882:2011，感觉IsConstructible可以直接写为
template <class T, class... Args>
struct IsConstructible: decltype(detail::IsConstructibleImpl<T, Args...>(0)){};
个人认为这样可能更加直观
因为根据[class.derived]/1
A list of base classes can be specified in a class definition using the notation:
[...]
class-or-decltype:
nested-name-specifieropt class-name
decltype-specifier
base-type-specifier:
class-or-decltype
[...]
所以我们可以直接用decltype的结果做基类
根据 [class.access.base]/2
In the absence of an access-specifier for a base class, public is assumed when the derived class is defined with
the class-key struct and private is assumed when the class is defined with the class-key class.
所以我们可以不写public
我这样做是正确的吗？是好的做法吗？
*/

int main()
{
    struct A
    {
        A(int a = 0, std::string b = "", std::vector<int> c = {}) {}
        A(A &) {}
    };

    static_assert(magic::IsConstructible<A>{}, "");                                     // OK
    static_assert(magic::IsConstructible<A, int>{}, "");                                // OK
    static_assert(magic::IsConstructible<A, double>{}, "");                             // OK
    static_assert(magic::IsConstructible<A, int, std::string>{}, "");                   // OK
    static_assert(magic::IsConstructible<A, int, std::string, std::vector<int>>{}, ""); // OK
    static_assert(magic::IsConstructible<A, A>{}, "");                                  // OK if the copy constructor of A is const A &
}