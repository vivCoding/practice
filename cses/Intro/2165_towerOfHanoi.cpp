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
#define rrep(i, a, b, v) for (int i = a; i >= b; i -= v)
#define all(x) x.begin(), x.end()
#define setpr(x) cout << setprecision(x) << fixed
const ll LLMAX = LONG_LONG_MAX / 2, LLMIN = LONG_LONG_MIN / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/2165
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; see(n);
    ll k = pow(2, n) - 1;
    putl(k);
    stack<ll> stacks[3] = {stack<ll>(), stack<ll>(), stack<ll>()};
    rrep(i, n, 1, 1) {
        stacks[0].push(i);
    }
    int tracker = 0, nxt;
    int direction = n % 2 == 0 ? 1 : -1;
    if (n % 2 == 0) {
        stacks[1].push(stacks[0].top());
        stacks[0].pop();
        tracker = 1;
        putl("1 2");
    } else {
        stacks[2].push(stacks[0].top());
        stacks[0].pop();
        tracker = 2;
        putl("1 3");
    }
    bool moveSmallest = false;
    while (stacks[2].size() != n) {
        if (moveSmallest) {
            nxt = direction == -1 ? tracker == 0 ? 2 : tracker - 1 : tracker == 2 ? 0 : tracker + 1;
            stacks[nxt].push(stacks[tracker].top());
            stacks[tracker].pop();
            putl(tracker + 1, nxt + 1);
            tracker = nxt;
        } else {
            int mni = 0, mn = 999;
            rep(i, 0, 3, 1) {
                if (i == tracker) continue;
                if (!stacks[i].empty() && stacks[i].top() < mn) {
                    mni = i;
                    mn = stacks[i].top();
                }
            }
            int other = 0;
            rep(i, 0, 3, 1) {
                if (i == tracker || i == mni) continue;
                other = i;
            }
            stacks[other].push(stacks[mni].top());
            stacks[mni].pop();
            putl(mni + 1, other + 1);
        }
        moveSmallest = !moveSmallest;
    }
    return 0;
}