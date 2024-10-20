// https://zhuanlan.zhihu.com/p/667019129

#include <string_view>

// 从字符串转换到T的具体实现，可以通过特化来扩展支持的类型
template <class T, class = void>
struct from_string_impl
{
};

// has_from_string<T>检查是否可以将字符串转换到某个类型T，即检查是否提供了from_string_impl的特化
// 它被用来产生更好的编译错误信息
namespace detail // hide impl detail
{
    template <class T>
    auto has_from_string(int) -> decltype(from_string_impl<T>::from_string(std::declval<std::string_view>()),
                                          std::true_type{});

    template <class T>
    std::false_type has_from_string(char);
}
template <class T>
constexpr bool has_from_string = decltype(detail::has_from_string<T>(0))::value;

// 基于返回值的重载机制的核心类型
// 它将类型转换操作符的类型信息传递到类模版中，内部调用用户自定义的from_string_impl特化来进行转化
struct from_string_t
{
    std::string_view s;
    // 为了避免dangling reference，只允许右值引用进行转换
    // 这样就可以避免如下错误用法:
    //    auto j = from_string(std::string("10"));
    //    int k = j; // dangling reference错误
    template <class T>
    operator T() const && { return from_string_impl<T>::from_string(s); }
    template <class T>
    operator T() const &
    {
        static_assert([]()
                      { return false; }, "must not be stored (for lifetime reasons)");
    }
};

// from_string_t的简单wrapper
from_string_t from_string(std::string_view s) { return from_string_t{s}; }

// 通过特化from_string_impl类模版来扩展from_string函数
template <>
struct from_string_impl<int>
{
    static int from_string(std::string_view s); // 自定义字符串到int的实现
};

template <>
struct from_string_impl<bool>
{
    static bool from_string(std::string_view s); // 自定义字符串到bool的实现
};

template <class T>
struct my_range
{ /* ... */
};

template <class T>
struct from_string_impl<my_range<T>, std::enable_if_t<has_from_string<T>>>
{
    static my_range<T> from_string(std::string_view s); // 自定义字符串到my_range<T>的实现
};

static_assert(has_from_string<int>);
static_assert(!has_from_string<char>);
static_assert(has_from_string<my_range<int>>);
static_assert(!has_from_string<my_range<float>>);

void test()
{
    int i = from_string("7");
    bool b = from_string("true");
    my_range<int> r = from_string("[0, 1, 2]");

    // 下面的使用方法存在dangling reference的问题
    // 幸运的是它会产生编译错误  "must not be stored (for lifetime reasons)");
    // auto j = from_string("10");
    // int k = j;
}