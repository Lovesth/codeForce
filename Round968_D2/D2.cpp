#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  int t;
  int n, m, u, v;
  int maxU, maxV;
  int li;
  vector<int> vis(2e5 + 10);
  vector<int> nums(2e5 + 10);
  vector<int> f(2e5 + 5);

  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    unordered_map<int, vector<int>> edges;
    maxU = maxV = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> li;
      for (int i = 0; i < li; i++)
      {
        cin >> nums[i];
        if (nums[i] < li + 5)
          vis[nums[i]] = 1;
      }
      u = v = 0;
      while (vis[u])
      {
        u++;
      }
      v = u + 1;
      while (vis[v])
      {
        v++;
      }
      edges[u].push_back(v);
      maxU = max(maxU, u);
      maxV = max(maxV, v);
      for (int i = 0; i < li; i++)
      {
        if (nums[i] < li + 5)
          vis[nums[i]] = 0;
      }
    }
    for (int k = maxV; ~k; k--)
    {
      f[k] = k;
      for (auto p : edges[k])
      {
        f[k] = max(f[k],f[p]);
      }
      if(edges[k].size()>=2){
        maxU = max(maxU, f[k]);
      }
    }
    ll res = 0;
    for(int i=0; i<=min(maxV,m); i++){
      res += max(f[i],maxU);
    }
    if(m>maxV){
      res += ll(m+maxV+1)*ll(m-maxV)/2;
    }
    cout << res << endl;
  }
}