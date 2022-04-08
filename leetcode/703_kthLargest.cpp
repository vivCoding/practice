#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/

class KthLargest {
public:
    multiset<int> ms;
    int kth;

    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (int num : nums) {
            ms.insert(num);
        }
    }
    
    int add(int val) {
        ms.insert(val);
        auto pt = ms.rbegin();
        for (int i = 0; i < kth; i++) {
            pt++;
        }
        return *pt;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */