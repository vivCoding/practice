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
 * Problem: https://leetcode.com/problems/beautiful-array/
 * UNSOLVED, need to understand
*/

bool checkSolution(int nums[], int n) {
    rep(i, 0, n, 1) {
        rep(j, i + 1, n, 1) {
            int sum = nums[i] + nums[j];
            if (sum % 2 == 1) continue;
            rep(k, i + 1, j, 1) {
                if (2 * nums[k] == sum) {
                    putl("BAD", i, j, k, nums[i], nums[j], nums[k]);
                    return false;
                }
            }
        }
    }
    putl("GOOD");
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; see(n);
    int nums[n] = {0}; nums[0] = 1;
    checkSolution(nums, n);
    return 0;
}
// 1 5 2 4 3
// 1 9 5 7 3 6 4 8 2