#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t{};
    int n{};

    cin >> t;
    while(t--) {
        cin >> n;

        ll res{};
        ll tmp{};
        vector<pair<ll, pair<ll,ll>>> segments(n);
        for(auto& seg : segments) {
            cin >> seg.second.first >> seg.second.second;
            seg.first = seg.second.first + seg.second.second;
            res += seg.second.second - seg.second.first;
            tmp += seg.second.second;
        }

        sort(segments.begin(), segments.end(), [](pair<ll, pair<ll,ll>>& s1, pair<ll, pair<ll,ll>>& s2){
            return s1.first < s2.first;
        });

        for(int i=0; i<n/2; i++) {
            tmp -= segments[i].first;
        }

        if(n%2 == 0) {
            cout << res + tmp << endl;
            continue;
        }

        ll newTmp{};
        for(int i=n/2; i<n; i++) {
            newTmp = max(newTmp, tmp-segments[i].second.second);
        }

        tmp -= segments[n/2].first;

        for(int i=0; i<n/2; i++) {
            newTmp = max(newTmp, tmp+segments[i].second.first);
        }
        cout << res + newTmp << endl;;
    }
}