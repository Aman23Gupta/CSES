#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);

    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // for(int i=0; i<n; i++) cout << a[i] <<" ";
    // cout<<endl;
    // for(int i=0; i<m; i++) cout << b[i] <<" ";
    // cout<<endl;

    int ans = 0;
    int i = 0;
    for(int j = 0; j < m; j++) {
        while(i < n && a[i] < b[j] - k) {
            i++;
        }

        if(i < n && b[j] >= a[i] - k && b[j] <= a[i] + k) {
            ans++;
            i++;
        }
    }

    cout<<ans<<endl;
    return 0;
}
