#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> &values, vector<int> &parents, unordered_map<int, vector<int>> &children, int idx)
{
    int res = INT_MAX;
    for (auto &child : children[idx])
    {
        res = min(dfs(values, parents, children, child), res);
    }
    if(children[idx].size()==0){
        return values[idx];
    }
    if(idx==1){
        return values[idx]+res;
    }
    if(values[idx]>=res){
        return res;
    }
    return values[idx]+(res-values[idx])/2;
}

int main()
{
    int t;
    int n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> values(n + 1);
        vector<int> parents(n + 1);
        unordered_map<int, vector<int>> children;
        for (int i = 1; i <= n; i++)
        {
            cin >> values[i];
            children[i];
        }
        parents[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            cin >> parents[i];
            children[parents[i]].push_back(i);
        }
        cout << dfs(values, parents, children, 1) << endl;
    }
}