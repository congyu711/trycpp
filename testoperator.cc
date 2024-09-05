#include<bits/stdc++.h>

struct always_functor { constexpr void operator()(); };

struct never_functor{};

template<typename T>
struct is_functor_impl : always_functor, std::conditional_t<std::is_class_v<T>, T, never_functor> {};

template<typename T>
concept is_functor_v = !requires{ &is_functor_impl<T>::operator(); };

int main()
{
	std::cout << std::boolalpha;
	std::cout << is_functor_v<int> << std::endl;
	std::cout << is_functor_v<std::vector<int>> << std::endl;
	std::cout << is_functor_v<std::function<void()>> << std::endl;
	std::cout << is_functor_v<decltype([](auto&&...) {})> << std::endl;
        return 0;
}