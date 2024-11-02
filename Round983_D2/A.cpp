#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int nOnes = 0, nZeros = 0;
        int tmp;
        for(int i=1; i<=2*n; i++){
            cin >> tmp;
            if(tmp){
                nOnes++;
            }else{
                nZeros++;
            }
        }
        cout << nOnes%2 << " " << min(nOnes,nZeros) << endl; 
    }
}