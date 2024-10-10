#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m;
    char c;
    int l, r;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int maxVal = 0;
        int tmp;
        for(int i=0; i<n; i++){
            cin >> tmp;
            maxVal = max(maxVal, tmp);
        }
        for(int i=0; i<m; i++){
            cin >> c >> l >> r;
            if(maxVal>=l && maxVal<=r){
                if(c=='+'){
                    maxVal += 1;
                }else{
                    maxVal -= 1;
                }
            }
            cout << maxVal << (i==m-1 ? "\n" : " ");
        }
    }
}