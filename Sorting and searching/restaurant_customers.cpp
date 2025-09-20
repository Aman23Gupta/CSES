#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    vector<int> start(n), end(n);

    for (int i=0; i<n; i++) {
        cin>>start[i]>>end[i];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int ans = 0, curr = 0;
    int i=0,j=0;
    while(i < n && j < n) {
        if(start[i] < end[j]) {
            i++;
            curr++;
        }
        else {
            j++;
            ans = max(curr, ans);
            curr--;
        }
    }

    ans = max(ans, curr);

    cout<<ans<<endl;
    return 0;
}