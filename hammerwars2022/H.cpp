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
 * Problem: https://codeforces.com/group/5HZlfh4ol7/contest/378015/problem/H
*/

class UF {
public:
    int *id, *sz, cnt;
    unordered_set<int> components;

    // Create an empty union find data structure with N isolated sets. O(n)
    UF(int n) {
        cnt = n; id = new int[n]; sz = new int[n];
        components.reserve(n);
        for (int i = 0; i < n; i++)  {
            id[i] = i;
            sz[i] = 1;
            components.insert(i);
        }
    }
    ~UF() {
        delete[] id; delete[] sz;
    }

    // Return the id of component corresponding to object p. O(log(n))
    int find(int p) {
        int root = p;
        while (root != id[root]) {
            root = id[root];
        }
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }

    // Replace sets containing x and y with their union. O(log(n))
    void merge(int x, int y) {
        int i = find(x), j = find(y);
        if (i == j) return;
        // make smaller root point to larger one
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
            components.erase(i);
        } else {
            id[j] = i;
            sz[i] += sz[j];
            components.erase(j);
        }
        cnt--;
    }
    // Checks if x and y belong to same component. O(log(n))
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    // Return the number of components. Constant
    int count() {
        return cnt;
    }
};

vc<vll> g;
bool good = true;

void dfs(ll ni, ll parent, unordered_set<ll>* visited) {
    visited->insert(ni);
    if (g[ni].size() != 2) {
        good = false;
        return;
    }
    for (ll child : g[ni]) {
        if (child != parent) {
            if (visited->find(child) == visited->end()) {
                dfs(child, ni, visited);
            }
        }
        if (!good) return;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; see(n, m);
    g.resize(n);
    UF uf(n);
    ll temp, temp2;
    rep(i, 0, m, 1) {
        see(temp, temp2);
        g[temp - 1].push_back(temp2 - 1);
        g[temp2 - 1].push_back(temp - 1);
        uf.merge(temp - 1, temp2 - 1);
    }
    ll ct = 0;
    for (auto p : uf.components) {
        unordered_set<ll> st;
        good = true;
        dfs(p, p, &st);
        if (good) {
            ct++;
        }
    }
    putl(ct);
    return 0;
}