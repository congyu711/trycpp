#include <cstddef>
#include <set>
#include <print>
#include <vector>

template<typename T>
struct node
{
    size_t l,r;
    T v;
    node(){}
    node(int l,int r=-1, T v=0):l(l),r(r),v(v){}
    bool operator<(const node& rop) const{
        return l< rop.l;
    }
};

template<typename T>
using chtholly_tree=std::set<node<T>>;

template<typename T>
inline chtholly_tree<T>::iterator split(chtholly_tree<T> &ct, size_t p){
    auto it = ct.lower_bound(node<T>(p));
    if(it != ct.end() && it->l == p) return it; // 情况一
    --it;                                      // 找到p所在区间
    if(it->r < p) return ct.end();              // 不需要拆分
    size_t L = it->l, R=it->r;                    // 记录信息
    auto v = it->v;
    ct.erase(it);
    ct.insert(Node(L, p - 1, v));               // 插入新区间
    return ct.insert(Node(p, R, v)).first;
}

template<typename T>
inline void modify(chtholly_tree<T> &ct,size_t l,size_t r,T v) {
    auto R=split(ct,r+1), L = split(ct,l);
    ct.erase(L, R);
    ct.insert(node(l, r, v));
    return;
}

template<typename T>
inline void add(chtholly_tree<T> &ct, size_t l, size_t r, T v) {
    auto R = split(ct,r+1), L=split(ct,l);
    while(L != R) {
       L->v += v;
       ++L;
    }
    return;
}
template<typename T>
inline T kth(chtholly_tree<T> &ct, size_t l, size_t r, size_t k) {
    auto R = split(ct,r+1), L = split(ct,l);
    using pairtype=std::pair<size_t,size_t>;
    std::vector<pairtype> vec;
    while(L != R) {
        vec.push_back(make_pair(L->v, L->r - L->l + 1));
        ++L;
    }
    sort(vec.begin(), vec.end(), [=](pairtype a, pairtype b) -> bool {
        return a.first < b.first;
    });
    for(auto i: vec) {
        k -= i.second;
        if(k <= 0) return i.first;
    }
    return -1;
}

int main()
{

}