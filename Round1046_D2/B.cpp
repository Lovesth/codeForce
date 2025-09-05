#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    int n, k;
    string s{};

    cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> s;
        int maxLen{0};
        int oneCnt{0};

        int i{}, j{};

        for(; i<n; ) {
            for(; i<n && s[i]=='0'; i++);
            j = i;
            for(; j<n && s[j]=='1'; j++);
            oneCnt += j-i;
            maxLen = max(maxLen, j-i);
            i = j;
        }

        if(maxLen >= k) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        int id1{1}, id2{oneCnt+1};
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                cout << id1++ << " ";
            }else{
                cout << id2++ << " ";
            }
        }

        cout << endl;
    }
}