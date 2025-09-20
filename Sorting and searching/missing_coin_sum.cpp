#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    vector<int> a(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int sum = 0;
    for(int i=0; i<n; i++) {
        if(sum + 1 < a[i]) {
            break;
        }
        sum += a[i];
    }

    cout<<sum + 1<<endl;
    return 0;
}