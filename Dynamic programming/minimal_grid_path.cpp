#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

vector<string> v;

int32_t main() {
    int n; cin >> n;
    v.resize(n);

    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    queue<pair<int,int>> q;
    q.push({0, 0});
    string ans = "";
    vector<vector<int>> vis(n, vector<int>(n,0));

    vis[0][0] = 1;

    while(!q.empty()) {
        int size = q.size();
        vector<pair<int,int>> lq;
        char minc = CHAR_MAX;
        ans += v[q.front().first][q.front().second];
        for(int i=0; i<size; i++) {
            auto t = q.front();
            q.pop();
            int row = t.first, col = t.second;
            if(row+1<n && vis[row+1][col] == 0) {
                vis[row+1][col] = 1;
                lq.push_back({row+1, col});
                if (v[row+1][col] < minc) minc = v[row+1][col];
            }
            if(col+1<n && vis[row][col+1] == 0) {
                vis[row][col+1] = 1;
                lq.push_back({row, col+1});
                if (v[row][col+1] < minc) minc = v[row][col+1];
            }
        }

        if(lq.empty()) break;
        for(int i=0;i<lq.size();i++) {
            if(minc == v[lq[i].first][lq[i].second])
                q.push(lq[i]);
        }
    }

    cout<<ans<<endl;

    return 0;
}