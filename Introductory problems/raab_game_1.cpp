#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if(a + b > n || (a == 0 && b != 0) || (b == 0 && a != 0)) {
            cout << "NO" << endl;
            continue;
        }

        int min_shifts = min(a, b);
        int no_of_shifts = max(a, b);
        vector<int> a_choices, b_choices;
        for(int i = 0; i < no_of_shifts; i++) {
            b_choices.push_back(n - i);
            a_choices.push_back(n - i - min_shifts);
        }
        int last_a_choice = a == 0 ? n + 1 : a_choices.back();
        int last_b_choice = b == 0 ? 0 : b_choices.back();
        int count = 0;
        for(int i = last_a_choice; i < last_b_choice; i++) {
            b_choices.push_back(i);
            a_choices.push_back(n - count);
            count++;
        }

        for(int i = 1; i < last_a_choice; i++) {
            a_choices.push_back(i);
            b_choices.push_back(i);
        }
        if(a > b) {
            swap(a_choices, b_choices);
        }
        cout << "YES" << endl;
        for(int i = 0; i < a_choices.size(); i++) {
            cout << a_choices[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < b_choices.size(); i++) {
            cout << b_choices[i] << " ";    
        }
        cout << endl;
    }
    return 0;
}