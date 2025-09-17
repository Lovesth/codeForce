#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t{};
    cin >> t;
    int n, c;

    while(t--) {
        cin >> n >> c;
        ll trash{};
        ll base{1};

        ll minVal{LLONG_MAX};
        priority_queue<ll, vector<ll>, less<ll>> pq{};
        for(int i=0; i<n; i++) {
            cin >> trash;
            pq.push(trash);
            minVal = min(minVal, trash);
        }

        int res{};
        while(!pq.empty()) {
            if(c/base < pq.top()) {
                res++;
                pq.pop();
                continue;
            }

            pq.pop();
            // res++;
            base <<= 1;
        }
        cout << res << endl;
    }
}