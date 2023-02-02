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
int charToDigit(char c) { return c - 48; }


/*
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/pw3vjn/problems/fruitbaskets
*/
vector<int> nums;

int rec(int ct, int currSum, int idx) {
    if (idx > nums.size() - 1 || ct == 4) {
        if (currSum < 200) {
            return currSum;
        } else return 0;
    }
    return rec(ct, currSum, idx + 1) + rec(ct + 1, currSum + nums[idx], idx + 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; see(n);
    nums.resize(n);
    int sm = 0;
    rep(i, 0, n, 1) {
        see(nums[i]);
        sm += nums[i];
    }
    sort(nums.begin(), nums.end());
    ll smAll = pow(2, n - 1) * sm;
    ll smBad = rec(0, 0, 0);
    putl(smAll - smBad);
    return 0;
}