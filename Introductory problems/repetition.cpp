#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    int n = s.size();
    int i = 0, j = 0, ans = 0;
    while (j < n) {
        if (s[j] == s[i]) {
            j++;
        } else {
            ans = max(ans, j - i);
            i = j;
        }
    }
    ans = max(ans, j - i);
    cout << ans << "\n";
    return 0;
}