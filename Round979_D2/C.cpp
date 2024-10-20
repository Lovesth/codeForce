#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        if(s[0]=='1' || s.back()=='1'){
            cout << "YES" << endl;
        }else{
            bool flag = false;
            for(int i=0; i<n-1; i++){
                if(s[i]=='1' && s[i+1]=='1'){
                    flag = true;
                    break;
                }
            }
            if(flag==true){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
}