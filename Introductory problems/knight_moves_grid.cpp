#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

vector<int> x_moves = {2, 1, -1, -2, -2, -1, 1, 2};
vector<int> y_moves = {1, 2, 2, 1, -1, -2, -2, -1};

int32_t main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    grid[0][0] = 0; // Starting position

    queue<pair<int, int>> q;
    q.push({0, 0});

    while(!q.empty()) {
        auto p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int new_x = x + x_moves[i];
            int new_y = y + y_moves[i];

            if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && grid[new_x][new_y] == -1) {
                grid[new_x][new_y] = grid[x][y] + 1; // Increment the move count
                q.push({new_x, new_y});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}