// https://zhuanlan.zhihu.com/p/625918675

#include <iostream>

struct X {
    ~X() { puts("~X()"); }
};
X f() { return {}; }

int main() {
    X&& x = f();
    puts("~~~");
}