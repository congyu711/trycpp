#include <string>
#include <variant>
#include <print>
#include <iostream>
using Settings = std::variant<int, bool, std::string>;

template<typename ...Ts>
struct Overload : Ts... { using Ts::operator()...; };

template<typename ...Ts>
Overload(Ts...) -> Overload<Ts...>;



int main()
{
    Settings s = 1;
    s = true;
    s = std::string("hello");
    // std::println("s = {}", std::get<0>(s));
    // std::println("s = {}", std::get<1>(s));
    std::println("s = {}", std::get<2>(s));
    std::println("s.idx = {}", s.index());

    auto callback = [](auto &&value)
    { std::cout << value << std::endl; };
    std::visit(callback, s); // => hello
    s = 1;
    std::visit(callback, s); // => 1


    // template hack -> pattern matching 
    Overload overloads{
        [](int x) { std::cout << "Int: " << x << std::endl; },
        [](bool x) { std::cout << "Bool: " << std::boolalpha << x << std::endl; },
        [](std::string x) { std::cout << "String: " << x << std::endl; },
    };
    Settings settings = 1;
    std::visit(overloads, settings);
}
