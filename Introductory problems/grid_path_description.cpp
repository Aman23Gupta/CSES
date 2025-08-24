#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool visited[7][7];
int ans = 0;

bool is_cell_empty(int i, int j) {
    return (i >= 0 && i <= 6 && j >= 0 && j <= 6 && !visited[i][j]);
}

void count_possible_paths(int index, int i, int j, string& s) {
    if (index == s.size() && i == 6 && j == 0) {
        ans++;
        return;
    }
    if (index == s.size()) return;

    if(!is_cell_empty(i + 1, j) && !is_cell_empty(i - 1, j) && is_cell_empty(i, j + 1) && is_cell_empty(i, j - 1)) return;
    if(!is_cell_empty(i, j + 1) && !is_cell_empty(i, j - 1) && is_cell_empty(i + 1, j) && is_cell_empty(i - 1, j)) return;
    
    if(is_cell_empty(i, j + 1) && is_cell_empty(i - 1, j) && !is_cell_empty(i - 1, j + 1)) return;
    if(is_cell_empty(i, j - 1) && is_cell_empty(i + 1, j) && !is_cell_empty(i + 1, j - 1)) return;
    if(is_cell_empty(i, j - 1) && is_cell_empty(i - 1, j) && !is_cell_empty(i - 1, j - 1)) return;
    if(is_cell_empty(i, j + 1) && is_cell_empty(i + 1, j) && !is_cell_empty(i + 1, j + 1)) return;

    if(s[index] == '?') {
        for(int dir = 0; dir < 4; dir++) {
            int new_i = i + dx[dir];
            int new_j = j + dy[dir];
            if(new_i >= 0 && new_i <= 6 && new_j >= 0 && new_j <= 6 && !visited[new_i][new_j]) {
                visited[new_i][new_j] = true;
                count_possible_paths(index + 1, new_i, new_j, s);
                visited[new_i][new_j] = false;
            }
        }
    } else {
        int dir;
        if(s[index] == 'R') dir = 0;
        else if(s[index] == 'D') dir = 1;
        else if(s[index] == 'L') dir = 2;
        else if(s[index] == 'U') dir = 3;
        int new_i = i + dx[dir];
        int new_j = j + dy[dir];
        if(new_i >= 0 && new_i <= 6 && new_j >= 0 && new_j <= 6 && !visited[new_i][new_j]) {
            visited[new_i][new_j] = true;
            count_possible_paths(index + 1, new_i, new_j, s);
            visited[new_i][new_j] = false;
        }
    }
}

int32_t main() {
    string s; cin >> s;
    int n = s.size();
    visited[0][0] = true;
    count_possible_paths(0, 0, 0, s);
    cout << ans << endl;
    return 0;
}