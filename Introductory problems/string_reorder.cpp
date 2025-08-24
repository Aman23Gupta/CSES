#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    string s; cin >> s;
    int n = s.size();

    map<char, int> m;
    set<pair<int, char>> st;

    for(int i=0; i<n; i++) {
        m[s[i]]++;
    }

    for(auto p : m) {
        st.insert({-p.second,p.first});
    }   
    int cur_max = -(*st.begin()).first;
    if(cur_max > n - cur_max + 1) {
        cout << -1 << endl;
        return 0;
    }
    string res = "";
    bool first_small = true;
    while(n > 0) {
        if(cur_max <= (n - cur_max)) {
            auto first = *m.begin();
            auto second = *(++m.begin());
            //cout << first.first << " " << first.second << " " << second.first << " " << second.second << endl;
            if(first.first != res.back()) {
                res += first.first;
                st.erase({-first.second, first.first});
                m[first.first]--;
                if(first.second == 1) {
                    m.erase(first.first);
                }
                else {
                    st.insert({-m[first.first], first.first});
                }
            }
            else {
                res += second.first;
                st.erase({-second.second, second.first});
                m[second.first]--;
                if(second.second == 1) {
                    m.erase(second.first);
                }
                else {
                    st.insert({-m[second.first], second.first});
                }
            }   
        } else {
            auto first = *st.begin();
            res += first.second;
            st.erase(first);
            m[first.second]--;
            if(m[first.second] == 0) {
                m.erase(first.second);
            }
            else {
                st.insert({-m[first.second], first.second});
            }
        }
        n--;
        cur_max = -(*st.begin()).first;
        //cout << res << " " << cur_max << " " << n << endl;
    }

    cout << res << endl;
    return 0;
}

/*
HLHLHLHLHLHLRSRSRSRSRSRSYSYSYSYSYSYS
HLHLHLHLHLHLRSRSRSRSRSRSYSYSYSYSYSYS
*/