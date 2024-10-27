#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2)
{
    if (num1.empty() || num2.empty())
        return "";
    if (num1[0] == '0' || num2[0] == '0')
        return "0";
    int l1 = num1.size();
    int l2 = num2.size();
    string res(l1 + l2, '0');
    for (int i = l1 - 1; i >= 0; --i)
    {
        int add = 0;
        for (int j = l2 - 1; j >= 0; --j)
        {
            int num = (num1[i] - '0') * (num2[j] - '0');
            int jinwei = res[i + j + 1] - '0' + add + num % 10;
            res[i + j + 1] = '0' + jinwei % 10;
            add = jinwei / 10 + num / 10;
        }
        res[i] += add;
    }
    // cout<<res;
    for (int i = 0; i < res.size(); ++i)
    {
        if (res[i] != '0')
            return res.substr(i);
    }
    return "0";
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << -1 << endl;
        }
        else if (n == 2)
        {
            cout << "66" << endl;
        }
        else
        {
            string res = "66";
            string tmp = "";
            int cnt = n - 3;
            for (int i = 1; i <= cnt; i++)
            {
                if (i == cnt)
                {
                    tmp += "5";
                    break;
                }
                if (i & 1)
                    tmp += "5";
                else
                    tmp += "0";
            }
            tmp += "0";
            tmp = multiply(tmp, "66");
            int len = tmp.size();
            if (len != n)
            {
                cout << "-1" << endl;
                continue;
            }
            tmp[len - 1] = '6';
            tmp[len - 2] = '6';
            cout << tmp << endl;
        }
    }
}