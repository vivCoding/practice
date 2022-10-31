#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int DaysInMonth(int month, int year);
// Do not edit above this line. It is only shown so you can see the function signature.
/*
 * Complete the function below.
 */
// int DaysBetween(int year1, int month1, int day1, int year2, int month2, int day2) {
//     // using year1 as starting point
//     // how many days with month1 day1 since starting point
    
//     int days1 = day1;
//     for (int i = 1; i < month1; i++) {
//         days1 += DaysInMonth(i, year1);
//     }

//     int days2 = day2;
//     for (int i = 1; i < month2; i++) {
//         days2 += DaysInMonth(i, year2);
//     }

//     days2 += 365 * (year2 - year1) + (year2 - year1) / 4;
//     if (year2 / 100 != year1 / 100) {
//         // account for leap years during centuries
//         int numLeapCenturies = (year2 / 100 - year1 / 100) / 4 + (year2 / 100 % 4 == 0 ? 1 : 0);
//         int numCenturies = year2 / 100 - year1 / 100;
//         days2 += numCenturies - numLeapCenturies;
//     }

//     return days2 - days1;
// }

int solution(vector<int> a, int m, int k) {
    unordered_map<int, int> mp;
    unordered_set<int> st;
    for (int i = 0; i < a.size(); i++) {
        if (mp.find(k - a[i]) != mp.end() && i - mp[a[i]] <= m) {
            st.insert(i);
            st.insert(mp[a[i]]);
        }
        mp[a[i]] = i;
    }
    int ct = 0;
    for (int i = 0; i < m; i++) {
        if (st.find(i) != st.end()) {
            ct++;
        }
    }
    int pairs = ct != 0;
    for (int i = m; i < a.size(); i++) {
        if (st.find(i - m) != st.end()) ct--;
        if (st.find(i) != st.end()) ct++;
        if (ct != 0) pairs++;
    }
    return pairs;
}



int main() {
    vector<int> a = {2, 4, 7, 5, 3, 5, 8, 5, 1, 7};
    cout << solution(a, 4, 10) << endl;
    return 0;
}