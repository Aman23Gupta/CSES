#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void go(int i, int n, string s, set<string> &st) {
    // cout<< i << " " << n << " " << s << endl;
    if(i == n) {
        st.insert(s);
        return;
    }

    for(int j = i; j < n; j++) {
        // if(s[i] == s[j]) continue;
        swap(s[i], s[j]);
        go(i+1, n, s, st);
        swap(s[i], s[j]);
    }
}

int32_t main() {
    string s; cin >> s;
    int n = s.size();

    set<string> st;
    go(0,n, s, st);

    cout << st.size() << endl;
    for(auto &x : st) {
        cout << x << endl;
    }

    return 0;
}

/*

*/