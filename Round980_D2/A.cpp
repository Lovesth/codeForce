#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a>=b){
            cout << a << endl;
        }else{
            if(2*a>=b){
                cout << 2*a-b << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }
}