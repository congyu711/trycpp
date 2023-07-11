// print enum with __PRETTY_FUNCTION__

#include <map>
#include <string>
#include <utility>
#include <stdio.h>

struct DummyFlag {};
template<typename Enum, typename T, Enum enumValue>
inline int get_enum_value(std::map<int, std::string> &values) {
#if defined _MSC_VER && !defined __clang__
    std::string func(__FUNCSIG__);
    std::string mark = "DummyFlag";
    auto pos = func.find(mark) + mark.size();
    std::string enumStr = func.substr(pos);

    auto start = enumStr.find_first_not_of(", ");
    auto end = enumStr.find('>');
    if (start != enumStr.npos
        && end != enumStr.npos
        && enumStr[start] != '(') {
        enumStr = enumStr.substr(start, end - start);
        values.insert({ (int)enumValue, enumStr });
    }

#else // gcc, clang
    std::string func(__PRETTY_FUNCTION__);
    std::string mark = "enumValue = ";
    auto pos = func.find(mark) + mark.size();
    std::string enumStr = func.substr(pos, func.size() - pos - 1);
    char ch = enumStr[0];
    if(!(ch >= '0' && ch <= '9') && ch != '(')
        values.insert({(int)enumValue, enumStr});
#endif
    return 0;
}

template <typename Enum, int min_value, int... ints>
void guess_enum_range(std::map<int, std::string> &values, const std::integer_sequence<int, ints...> &) {
    auto dummy = { get_enum_value<Enum, DummyFlag, (Enum)(ints + min_value)>(values)... };
}

template <typename Enum, int... ints>
void guess_enum_bit_range(std::map<int, std::string> &values, const std::integer_sequence<int, ints...> &) {
    auto dummy = {
        get_enum_value<Enum, DummyFlag, (Enum)0>(values),
        get_enum_value<Enum, DummyFlag, (Enum)(1 << (int)ints)>(values)...
    };
}

template<typename Enum, int min_value = -64, int max_value = 64>
void print() {
    std::map<int, std::string> values;
    guess_enum_range<Enum, min_value>(values, std::make_integer_sequence<int, max_value - min_value>());
    guess_enum_bit_range<Enum>(values, std::make_integer_sequence<int, 32>());
    
    for(const auto &value: values) {
        printf("%s = %d\n", value.second.c_str(), value.first);
    }
}

enum MyEnum {
    kRed = 0,
    kGreen = 1,
    kBlue = 15,
};

enum MyBitEnum {
    kTom = 0x01,
    kJerry = 0x02,
    kZhangSan = 0x400,
    kXiaoMing = 0x800,
};

int main() {
    print<MyEnum>();   
    print<MyBitEnum>();
}