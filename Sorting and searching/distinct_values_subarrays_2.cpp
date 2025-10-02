#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n,k; cin >> n >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    map<int,int> counts;
    int total = 0, ans = 0;

    for(int i=0,j=0; i<n; i++) {
        if(counts[a[i]] == 0) total++;
        counts[a[i]]++;
        while(total > k) {
            counts[a[j]]--;
            if(counts[a[j]] == 0) {
                total--;
            }

            j++;
        }

        ans += (i-j+1);
    }

    cout<<ans<<endl;

    return 0;
}