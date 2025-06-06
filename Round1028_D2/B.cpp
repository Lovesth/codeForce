#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD{998244353};

ll fastPow(ll x, ll M)
{
    ll base{2};
    ll res{1};
    while(x){
        if(x&1){
            res *= base;
            res %= MOD;
        }
        base *= base;
        base %= MOD;
        x /= 2;
    }
    return res;
}

int main()
{
    int t;
    int n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> nums1(n);
        vector<int> nums2(n);
        for (auto &num : nums1)
            cin >> num;

        for (auto &num : nums2)
            cin >> num;

        int maxPos1{0}, maxPos2{0};
        // 2^pj*(1 + 2^(qij - pj))
        for (int i = 0; i < n; i++)
        {
            if (nums1[maxPos1] < nums1[i])
            {
                maxPos1 = i;
            }
            if (nums2[maxPos2] < nums2[i])
            {
                maxPos2 = i;
            }
            if (nums1[maxPos1] > nums2[maxPos2])
            {
                cout << (fastPow(nums1[maxPos1], MOD) + fastPow(nums2[i - maxPos1], MOD)) % MOD << endl;
            }
            else if (nums1[maxPos1] < nums2[maxPos2])
            {
                cout << (fastPow(nums2[maxPos2], MOD) + fastPow(nums1[i - maxPos2], MOD)) % MOD << endl;
            }
            else
            {
                cout << (fastPow(nums1[maxPos1], MOD) + fastPow(max(nums1[i-maxPos2], nums2[i-maxPos1]), MOD)) % MOD << endl;
            }
        }
    }
}