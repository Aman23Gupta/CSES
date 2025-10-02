#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);

    for(int i=0; i<n; i++) {
        int x; cin >> x;
        a[i] = {x, i};
    }

    sort(a.begin(), a.end());

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int l = j+1, h = n-1;
            while(l < h) {
                int sum = a[i].first + a[j].first + a[l].first + a[h].first;
                if(sum == k) {
                    cout<< a[i].second + 1 <<" "<< a[j].second + 1 <<" "<< a[l].second + 1 <<" "<< a[h].second + 1 <<endl;
                    return 0;
                }
                else if(sum > k) {
                    h--;
                }
                else {
                    l++;
                }
            }
        }
    }


    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}