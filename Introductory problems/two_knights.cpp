#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;
    for(long long j=1; j<=n; j++) {
        long long i = j*j;

        long long totalpositions = (i * (i - 1)) / 2;
        long long totalattacks = 0;
        totalattacks += 8 * (j - 4) * (j - 4);
        totalattacks += 6 * (j - 4) * 4;
        totalattacks += 4 * (j - 3) * 4;
        totalattacks += 3 * 8;
        totalattacks += 2 * 4;
        totalattacks /= 2;

        cout << totalpositions - totalattacks << endl;
    }
    return 0;
}

/*
234444444432  
346666666643
468888888864
468888888864
468888888864
468888888864
468888888864
468888888864
468888888864
468888888864
346666666643
234444444432
*/