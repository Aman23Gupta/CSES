#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long total = n * (n+1);
    if(total % 4 != 0) {
        cout << "NO" << "\n";
        return 0;
    }

    cout<< "YES" << "\n";
    // First half of the set
    int left = n / 4;
    int right = (n + 3) / 4;
    cout << left + right << "\n";
    for (long long i = 1; i <= left; i++) {
        cout << i << " ";
    }
    for(long long i = 1; i <= right; i++) {
        cout << n - i + 1 << " ";
    }
    cout << "\n";
    cout << n - left - right << "\n";
    // Second half of the set
    for (long long i = left + 1; i <= n - right; i++) {
        cout << i << " ";
    }
    return 0;
}