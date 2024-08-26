#include<optional>
#include<print>
#include<variant>

std::optional<int> foo(int a)
{
    if(a>0)
        return a;
    else
        return {};
}
std::variant<int, std::string> bar(int a)
{
    if(a>0)
        return a;
    else
        return "error";
}

int main()
{
    std::println("{}", foo(2).value());
    std::println("{}", std::get<std::string>(bar(2)));
}