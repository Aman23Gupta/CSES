#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n,x; cin>>n>>x;
    vector<pair<int,int>> a(n);
    
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        a[i] = {x, i};
    }

    if(n==1) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    sort(a.begin(), a.end());

    int i=0, j=n-1;

    while(i < j) {
        if(a[i].first + a[j].first == x) {
            cout<<min(a[i].second, a[j].second) + 1<<" "<<max(a[i].second, a[j].second) + 1<<"\n";
            return 0;
        }

        if(a[i].first + a[j].first > x) {
            j--;
        }
        else {
            i++;
        }
    }

    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}