#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long total = 1;
    long long current = 1;
    for(int i = 0; i < n; i++) {
        total += current;
        total %= 1000000007;
        current *= 2;
        current %= 1000000007;
    }
    cout << total << "\n";
    return 0;
}