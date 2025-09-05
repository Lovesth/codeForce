#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t, n, m, q;
    int x, y, z;
    cin >> t;
    while(t--) {
        cin >> n >> m >> q;
        vector<ll> cardsVad(n);
        vector<ll> cardsKos(m);
        for(auto& card : cardsVad)
            cin >> card;
        
        for(auto& card : cardsKos)
            cin >> card;
        sort(cardsVad.begin(), cardsVad.end());
        sort(cardsKos.begin(), cardsKos.end());

        vector<ll> sum1(n+10);
        vector<ll> sum2(m+10);

        partial_sum(cardsVad.begin(), cardsVad.end(), sum1.begin()+1);
        partial_sum(cardsKos.begin(), cardsKos.end(), sum2.begin()+1);


        while(q--) {
            cin >> x >> y >> z;
            x = min(x, n);
            y = min(y, m);

            int s = n-x;
            int e = n-1;

            while(s <= e) {
                int mid = (s+e+1) / 2;
                int pos = lower_bound(cardsKos.begin()+m-y, cardsKos.end(), cardsVad[mid]) - cardsKos.begin();
                if(n-mid+m-pos > z) {
                    s = mid+1;
                }else if(n-mid+m-pos < z){
                    e = mid-1;
                }else{
                    s = mid;
                    break;
                }
            }

            ll r{0};
            // s = max(min(s,e), 0);
            int tmp = n-s;
            if(tmp > 0) {
                r += sum1[n] - sum1[s];
            }

            tmp = min(y, z-tmp);
            r += sum2[m] - sum2[m-tmp];
            cout <<  r << endl;
        }
    }
}