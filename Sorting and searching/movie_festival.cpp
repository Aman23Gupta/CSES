#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    vector<pair<int,int>> movies(n);

    for(int i = 0; i < n; i++) {
        int a,b; cin >> a >> b;
        movies[i] = {b, a};
    }

    sort(movies.begin(), movies.end());
    int ans = 1;
    int cur = movies[0].first;
    for (int i=1; i<n; i++) {
        if (cur <= movies[i].second) {
            ans++;
            cur = movies[i].first;
        }
    }

    cout<<ans<<endl;
    return 0;
}