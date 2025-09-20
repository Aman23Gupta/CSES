#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x-1] = i;
    }
    int backwards = 0;
    for(int i=0;i<n-1;i++) {
        if(a[i] > a[i+1]) backwards++;
    }

    cout<<backwards+1<<endl;

    return 0;
}