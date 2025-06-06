#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int a, b, c, d;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        if(min(a,c) < min(b,d)){
            cout << "Flower" << endl;
        }else{
            cout << "Gellyfish" << endl;
        }
    }
}