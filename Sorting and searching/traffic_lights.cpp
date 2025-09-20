#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int x, n; cin >> x >> n;
    vector<int> a(n);

    for(int i=0; i<n; i++) cin >> a[i];

    set<pair<int,int>> order_by_end;
    set<pair<int,pair<int,int>>> order_by_length;
    order_by_end.insert({x,0});
    order_by_length.insert({x, {x, 0}});

    for(int i=0;i<n;i++) {
        auto it = order_by_end.lower_bound({a[i],0});
        if(it != order_by_end.end()) {
            pair<int,int> new_position1 = {(*it).first, a[i]}, new_position2 = {a[i], (*it).second};
            //cout<<new_position1.first-new_position1.second<<" "<<new_position2.first-new_position2.second<<endl;
            order_by_length.erase({(*it).first - (*it).second, *it});
            order_by_end.erase(it);
            order_by_end.insert(new_position1);
            order_by_end.insert(new_position2);
            order_by_length.insert({new_position1.first-new_position1.second, new_position1});
            order_by_length.insert({new_position2.first-new_position2.second, new_position2});
        }

        cout<<(*(--order_by_length.end())).first<<" ";
    }
    cout<<endl;
    return 0;
}