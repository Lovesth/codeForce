#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;
const int mod = 998244353;

vector<int> g[MAXN], dcc[MAXN];

int dfn[MAXN], low[MAXN], id;

int s[MAXN], tp, p[MAXN], cnt;

void tarjan(int u, int f = 0) {
	dfn[u] = low[u] = ++id, s[++tp] = u;
	for (int v : g[u]) {
		if (!dfn[v]) tarjan(v, u), low[u] = min(low[u], low[v]);
		else if (v != f) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		cnt++;
		for (int x = 0; x != u; ) {
			x = s[tp--], p[x] = cnt;
			dcc[cnt].emplace_back(x);
		}
	}
}

int col[MAXN];

bool check(int u, int f = 0) {
	if (~col[u]) return col[u] == f; col[u] = f;
	for (int v : g[u]) if (p[u] == p[v] && !check(v, f ^ 1)) return 0;
	return 1;
}

int T, n, m, V, a[MAXN], ans;

int main() {
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d%d", &n, &m, &V), id = cnt = 0, ans = 1;
		for (int i = 1; i <= n; i++) dfn[i] = low[i] = p[i] = 0, col[i] = -1;
		for (int i = 1; i <= n; i++) g[i].clear(), dcc[i].clear();
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1, u, v; i <= m; i++) {
			scanf("%d%d", &u, &v);
			g[u].emplace_back(v), g[v].emplace_back(u);
		}
		for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
		for (int i = 1; i <= cnt; i++) {
			int x = -1;
			for (int u : dcc[i]) {
				if (a[u] < 0) continue;
				if (x < 0) x = a[u];
				else if (x != a[u]) { ans = 0; break; }
			}
			if (!ans) break;
			bool f = check(dcc[i][0]);
			if (f) { if (x < 0) ans = (ll)ans * V % mod; }
			else if (x > 0) ans = 0;
			if (!ans) break;
		}
		printf("%d\n", ans);
	}
}