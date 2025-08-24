#include <bits/stdc++.h>
using namespace std;
long long n;

int main() {
	cin>>n;
    long long sum = 0;
    for(long long i = 0; i < n-1; i++) {
        long long x;
        cin >> x;
        sum += x;
    }

    long long total = (n * (n + 1)) / 2;
    cout << total - sum << "\n";
	return 0;
}