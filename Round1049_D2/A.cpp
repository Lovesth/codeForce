#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;

        int res{0};
        while(1) {
            int zeroLeft{0}, zeroRight{n-1};
            for(;zeroLeft<n&&s[zeroLeft]!='0';zeroLeft++);
            for(;zeroRight>=0&&s[zeroRight]!='0';zeroRight--);

            int onesLeft{0};
            for(;onesLeft<n&&s[onesLeft]!='1';onesLeft++);

            if(onesLeft>zeroRight){
                break;
            }

            if(onesLeft < zeroLeft) {
                swap(s[onesLeft], s[zeroRight]);
            }else if(onesLeft > zeroLeft) {
                swap(s[onesLeft], s[zeroRight]);
            }
            res++;
        }
        cout << res << endl;
    }
    return 0;
}