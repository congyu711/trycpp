#include <concepts>
#include <iterator>
#include <type_traits>
#include <queue>

// for tests
#include <print>
#include <vector>
#include <set>


template <class c_t>
concept pushback_c_t = requires(c_t c, typename c_t::value_type v) {
    { c.begin() } -> std::input_or_output_iterator;
    { c.end() } -> std::input_or_output_iterator;
    c.push_back(v);
};

template <class c_t>
concept insert_c_t = requires(c_t c, typename c_t::value_type v) {
    { c.begin() } -> std::input_or_output_iterator;
    { c.end() } -> std::input_or_output_iterator;
    c.insert(v);
};

template <class c_t>
concept push_c_t = requires(c_t c, typename c_t::value_type v) {
    { c.begin() } -> std::input_or_output_iterator;
    { c.end() } -> std::input_or_output_iterator;
    c.push(v);
};

template <class f_t,pushback_c_t c_t>
auto fmap(f_t f, c_t c)
{
    using value_type = std::invoke_result_t<f_t,typename c_t::value_type>;
    c_t result;
    for (auto it = c.begin(); it != c.end(); ++it)
    {
        result.push_back(f(*it));       // push_back only works for vectors...
    }
    return result;  
}

template <class f_t,insert_c_t c_t>
auto fmap(f_t f, c_t c)
{
    using value_type = std::invoke_result_t<f_t,typename c_t::value_type>;
    c_t result;
    for (auto it = c.begin(); it != c.end(); ++it)
    {
        result.insert(f(*it));       // BRUTE FORCE!!!
    }
    return result;  
}

template <class f_t,push_c_t c_t>
auto fmap(f_t f, c_t c)
{
    using value_type = std::invoke_result_t<f_t,typename c_t::value_type>;
    c_t result;
    for (auto it = c.begin(); it != c.end(); ++it)
    {
        result.push(f(*it));       // BRUTE FORCE!!!
    }
    return result;  
}


int main()
{
    std::vector<int> vec{1,2,3,4,5};
    auto f = [](int x) { return x+3; };
    auto res = fmap(f,vec);
    for(auto e:res) std::print("{} ", e);
    std::println("");
    std::set<int> st{10,12,13,14};
    auto resst = fmap(f,st);
    for(auto e:resst) std::print("{} ", e);
    std::println("");
    std::deque<int> q{101,102,103};
    auto resq = fmap(f,q);
    for(auto e:resq) std::print("{} ", e);
    std::println("");
}