#include<bits/stdc++.h>


// https://stackoverflow.com/questions/17178499/how-does-stdget-work-with-stdtuple

template<int...> struct seq {};
template<int max, int... s> struct make_seq:make_seq< max-1, max-1, s... > {};
template<int... s> struct make_seq<0, s...> {
  typedef seq<s...> type;
};
template<int max> using MakeSeq = typename make_seq<max>::type;

int main()
{
    auto sequence=MakeSeq<10>{};
}