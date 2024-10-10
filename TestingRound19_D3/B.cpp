#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> r(4);
    r[a] = r[b] = 1;
    for (int i = 1; i <= 3; i++)
    {
        if (r[i] == 0)
            cout << i << endl;
    }
}