// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n, m, q, t, x, y;
//     cin >> n >> m >> q;
//     vector<int>rows(n+1);
//     for(int i=1; i<=n; i++){
//         rows[i] = i;
//     }
//     vector<int> rot(n+1);
//     for(int i=1; i<=q; i++){
//         cin >> t >> x >> y;
//         if(t==1){
//             swap(rows[x], rows[y]);
//         }else if(t==2){
//             rot[x] += y;
//             rot[x] %= m;
//         }else{
//             int r = rows[x];
//             int tmp = rot[x];
//             int c;
//             if(y<=m-tmp){
//                 c = tmp+y;
//             }else{
//                 c = y-(n-tmp+1);
//             }
//             cout << (r-1)*m+c << endl;
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, L, R, T, D;
    cin >> n;
    set<vector<ll>> data;
    ll S = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> L >> R >> T >> D;
        data.insert(vector<ll>{L, T, R, D});
        while (!data.empty())
        {
            if ((*data.begin())[0] > S)
                break;
            // while((*data.begin())[1] < S){
            //     data.erase(data.begin());
            // }
            auto it = data.begin();
        }
    }
}