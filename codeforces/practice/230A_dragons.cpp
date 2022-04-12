#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void see(T&... args) { ((cin >> args), ...); }
template<typename... T>
void put(T&&... args) { ((cout << args), ...);}
template<typename... T>
void puts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
typedef unordered_map<ll, ll> umll;
#define vc vector
#define um unordered_map
#define us unordered_set
#define fr(i, a, b, v) for (int i = a; i < b; i += v)
#define all(x) x.begin(), x.end()
#define setpr(x) cout << setprecision(x) << fixed
const ll LLMAX = LONG_LONG_MAX / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://codeforces.com/problemset/problem/230/A
*/

int comp(pll p1, pll p2) {
    if (p1.first == p2.first) {
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll s, n; see(s, n);
    vc<pll> vec;
    ll t1, t2;
    fr(i, 0, n, 1) {
        see(t1, t2);
        vec.push_back({ t1, t2 });
    }
    sort(vec.begin(), vec.end(), comp);
    for (auto p = vec.begin(); p != vec.end(); p++) {
        if (s <= p->first) {
            putl("NO");
            return 0;
        } else {
            s += p->second;
        }
    }    
    putl("YES");
    return 0;
}