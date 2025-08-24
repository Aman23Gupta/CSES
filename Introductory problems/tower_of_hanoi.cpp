#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void go(int n, int from, int to, int aux) {
    if(n == 0) return;
    go(n - 1, from, aux, to);
    cout << from << " " << to << endl;
    go(n - 1, aux, to, from);
}

int32_t main() {
    int n; cin >> n;
    cout << (1 << n) - 1 << endl; // Total moves
    go(n, 1, 3, 2);
}