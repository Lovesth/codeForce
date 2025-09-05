#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, c, d;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d;
        int minVal = min(a,b);
        int maxVal = max(a,b);

        if(2*minVal+2 < maxVal) {
            cout << "NO" << endl;
            continue;
        }

        minVal = min(c-a, d-b);
        maxVal = max(c-a, d-b);

        if(minVal < 0) {
            cout << "NO" << endl;
        }

        if(2*minVal+2 < maxVal) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }
}