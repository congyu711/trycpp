// main
#include <bits/stdc++.h>
#include <ranges>
using namespace std;

using ll = long long;

void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}