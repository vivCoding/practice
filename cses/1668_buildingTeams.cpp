#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1668
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

ll n, m;
ll* teams;
vector<vll> g;

void dfs(ll ni, ll parent, ll prev) {
    teams[ni] = prev == 1 ? 2 : 1;
    for (ll child : g[ni]) {
        if (child != parent) {
            if (teams[child] != 0 && teams[child] == teams[ni]) {
                cout << "IMPOSSIBLE\n";
                exit(0);
            } else if (teams[child] == 0) {
                dfs(child, ni, teams[ni]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    UF uf(n);
    teams = new ll[n];
    fill(teams, teams + n, 0);
    g.reserve(n);
    ll t1, t2;
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        uf.merge(t1 - 1, t2 - 1);
        g[t1 - 1].push_back(t2 - 1);
        g[t2 - 1].push_back(t1 - 1);
    }
    for (auto p = uf.components.begin(); p != uf.components.end(); p++) {
        dfs(*p, *p, 1);
    }
    for (int i = 0; i < n; i++) {
        cout << teams[i] << " ";
    }
    cout << endl;
    return 0;
}