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
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/ndwbkd/problems/treehouses
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

ld distance(pair<ld, ld> p1, pair<ld, ld> p2) {
    ld x = pow(p1.first - p2.first, 2);
    ld y = pow(p1.second - p2.second, 2);
    return sqrt(x + y);
}

struct Edge {
    int p1, p2;
    ld dist;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, e, p; see(n, e, p);
    vc<pair<ld, ld>> v;
    v.reserve(n);
    ld a, b;
    UF uf(n);

    rep(i, 0, n, 1) {
        see(a, b);
        v.push_back({a, b});
    }

    rep(i, 0, p, 1) {
        see(a, b);
        uf.merge(a - 1, b - 1);
    }

    vc<Edge> ev;
    rep(i, 0, n, 1) {
        rep(j, i + 1, n, 1) {
            if (i < e && j < e) {
                uf.merge(i, j);
            }
            Edge e;
            e.p1 = i, e.p2 = j;
            e.dist = distance(v[i], v[j]);
            ev.push_back(e);
        }
    }

    sort(ev.begin(), ev.end(), [](Edge e1, Edge e2) {
        return e1.dist < e2.dist;
    });

    ld ct = 0;
    for (auto e : ev) {
        if (!uf.connected(e.p1, e.p2)) {
            uf.merge(e.p1, e.p2);
            ct += e.dist;
        }
    }

    setpr(6);
    putl(ct);
    return 0;
}