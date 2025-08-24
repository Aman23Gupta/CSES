#include <bits/stdc++.h>
using namespace std;
long long n;

int main() {
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    if(n<4) {
        cout << "NO SOLUTION"<<"\n";
        return 0;
    }

    if (n == 4) {
        cout << "2 4 1 3\n";
        return 0;
    }

    for (int i = n - 1; i >= 0; i-=2) {
        cout << i + 1 << " ";
    }

    for (int i = n - 2; i >= 0; i-=2) {
        cout << i + 1 << " ";
    }
    cout << "\n";
    return 0;
}