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
#define rep(i, a, b, v) for (int i = a; i < b; i += v)
#define all(x) x.begin(), x.end()
#define setpr(x) cout << setprecision(x) << fixed
const ll LLMAX = LONG_LONG_MAX / 2, LLMIN = LONG_LONG_MIN / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/2431
*/

// gaps: 10 180 2700 36000 450000
// index: 10 190 2890 38890 488890

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll q; see(q);
    rep(_, 0, q, 1) {
        ll k; see(k);
        ll sum = 0, i = 1;
        ll ct = k;
        while (true) {
            ll next = 9 * i * pow(10, i - 1) + (i == 1 ? 1 : 0);
            if (ct >= next) {
                ct -= next;
                sum += next;
                i++;
            } else break;
        }
        ll numDigits = i;
        ll curr = numDigits == 1 ? 0 : pow(10, numDigits - 1);
        string num = to_string(curr + (k - sum) / numDigits);
        putl(num[(k - sum) % numDigits]);
    }
    return 0;
}