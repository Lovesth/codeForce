#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MOD = 1e9 + 7;

LL qmi(LL a, LL k, LL p)
{
    LL res = 1;
    while (k)
    {
        if (k & 1)
            res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    vector<int> ns(t+1);
    vector<int> ks(t+1);
    for(int i=1; i<=t; i++){
        cin >> ns[i];
    }
    for(int i=1; i<=t; i++){
        cin >> ks[i];
    }
    for(int i=1; i<=t; i++){
        LL res = 0;
        if (ns[i] == ks[i])
            res = 1;
        else
            res = qmi(2, ks[i], MOD);
        cout << res % MOD << endl;
    }
}