#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, p;
    cin >> n >> m >> p;
    double P = p / 100.0;
    vector<int> nums(n);
    int minVal{INT_MAX};
    int s{0};
    for(auto& num : nums){
        cin >> num;
        s += num;
        minVal = min(minVal, num);
    }
    
    int r = s - minVal * n;
    if(m < r){
        cout << 0 << endl;
        return;
    }
    vector<vector<double>> f1(m+2, vector<double>(r+2));
    f1[0][0] = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<r; j++){
            f1[i+1][j] += f1[i][j] * P;
            f1[i+1][j+1] += f1[i][j] * (1-P);
        }
    }

    vector<vector<vector<double>>> f2(m+1, vector<vector<double>>(n, vector<double>(minVal+1)));
    f2[0][0][0] = 1;

    for(int i=1; i<=m; i++){
        f2[i][0][0] = 1;
        for(int k=1; k<=minVal; k++){
            f2[i][0][k] = f2[i-1][0][k-1] * P + max(f2[i-1][0][k] ,f2[i-1][n-1][k-1]) * (1-P);
        }


        for(int j=1; j<n; j++){
            f2[i][j][0] = f2[i-1][j-1][0] * (1-P) + f2[i-1][j][0] * P;
            for( int k=1; k<=minVal; k++){
                f2[i][j][k] = f2[i-1][j][k-1] * P + f2[i-1][j-1][k] * (1-P);
            }
        }
    }

    double res{0};
    for(int i=r; i<=m; i++){
        double tmp{0};
        for(int j=0; j<=min(i-r, minVal-1); j++){
            // cout << m-i << " " << minVal-j << " " << f2[m-i][0][minVal-1-j] << endl;
            tmp = max(tmp, f2[m-i][0][minVal-j-1]);
        }
        // cout << tmp << endl;
        res += tmp * f1[i][r];
    }
    cout << res << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

// #include<bits/stdc++.h>

// using namespace std;

// const int N = 22, K = 4000 + 5, M = 400 + 5, Inf = 0x3f3f3f3f;

// inline void checkmin(double &x, double y){
// 	if(y < x) x = y;
// }

// int n = 0, m = 0, s = 0, k = 0, p0 = 0, h[N] = {};
// double p = 0, f[K][K] = {}, g[K][N][M] = {}, ans = 0;

// inline void init(){
// 	for(int i = 0 ; i <= k ; i ++){
// 		for(int c = 0 ; c < n ; c ++) for(int x = 0 ; x <= m ; x ++) g[i][c][x] = 0;
// 		for(int x = 0 ; x <= s ; x ++) f[i][x] = 0;
// 	}
// 	m = Inf, s = 0, ans = 0;
// }

// inline void solve(){
// 	scanf("%d %d %d", &n, &k, &p0);
// 	p = 1.0 * p0 / 100;
// 	for(int i = 1 ; i <= n ; i ++){
// 		scanf("%d", &h[i]); h[i] --;
// 		m = min(m, h[i]);
// 	}
// 	for(int i = 1 ; i <= n ; i ++) s += h[i] - m;
// 	if(s > k){
// 	    printf("0.000000\n");
// 	    return;
// 	}
// 	g[0][0][0] = 1;
// 	for(int i = 1 ; i <= k ; i ++){
// 		g[i][0][0] = 1;
// 		for(int x = 1 ; x <= m ; x ++) g[i][0][x] = g[i - 1][0][x - 1] * p + max(g[i - 1][0][x], g[i - 1][n - 1][x - 1]) * (1 - p);
// 		for(int c = 1 ; c < n ; c ++){
// 			g[i][c][0] = g[i - 1][c][0] * p + g[i - 1][c - 1][0] * (1 - p);
// 			for(int x = 1 ; x <= m ; x ++) g[i][c][x] = g[i - 1][c][x - 1] * p + g[i - 1][c - 1][x] * (1 - p);
// 		}
// 	}
// 	f[0][0] = 1;
// 	for(int i = 0 ; i < k ; i ++) for(int x = 0 ; x < s ; x ++){
// 		f[i + 1][x] += f[i][x] * p;
// 		f[i + 1][x + 1] += f[i][x] * (1 - p);
// 	}
// 	for(int i = s ; i <= k ; i ++){
// 		double r = 0;
        
// 		for(int x = 0 ; x <= min(i - s, m) ; x ++){
//             cout << k-i << " " << m-x << " " << g[k - i][0][m - x] << endl;
//             r = max(r, g[k - i][0][m - x]);
//         }
// 		// cout << f[i][s] << endl;
//         ans += r * f[i][s];
// 	}
// 	printf("%.6lf\n", ans);
// }

// int T = 0;

// int main(){
// 	scanf("%d", &T);
// 	while(T --) init(), solve();
// 	return 0;
// }