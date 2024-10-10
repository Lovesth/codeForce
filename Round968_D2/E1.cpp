// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int nums1[5'000 + 100];

// void merge_sort(int l, int r, ll &res, vector<int> &nums)
// {
//     if (l >= r)
//     {
//         return;
//     }
//     int mid = l + r >> 1;
//     merge_sort(l, mid, res, nums);
//     merge_sort(mid + 1, r, res, nums);
//     int k = 0, i = l, j = mid + 1;
//     while (i <= mid && j <= r)
//     {
//         if (nums[i] <= nums[j])
//             nums1[k++] = nums[i++];
//         else
//         {
//             nums1[k++] = nums[j++];
//             res += mid - i + 1;
//         }
//     }
//     while (i <= mid)
//         nums1[k++] = nums[i++];
//     while (j <= r)
//         nums1[k++] = nums[j++];
//     for (i = l, j = 0; i <= r;)
//     {
//         nums[i++] = nums1[j++];
//     }
// }

// int main()
// {
//     int t, n, m;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n >> m;
//         vector<pair<int, int>> intervals(m);
//         for (auto &pii : intervals)
//         {
//             cin >> pii.first >> pii.second;
//         }
//         vector<int> nums(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             nums[i] = n - i + 1;
//         }
//         vector<int> tmp;
//         for (int i = m - 1; ~i; i--)
//         {
//             auto &[l, r] = intervals[i];
//             for (int j = r; j >= l; j--)
//             {
//                 tmp.push_back(n - j + 1);
//             }
//         }
//         int curPos = 0;
//         for (int i = m - 1; ~i; i--)
//         {
//             auto &[l, r] = intervals[i];
//             nums[l] = tmp[curPos++];
//         }
//         for (int i = m - 1; ~i; i--)
//         {
//             auto &[l, r] = intervals[i];
//             for (int j = r; j > l; j--)
//             {
//                 nums[j] = tmp[curPos++];
//             }
//         }
//         //----------------------------//
//         ll res = 0;
//         merge_sort(1,n,res,nums);
//         cout << res << endl;
//     }
// }

#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<ll, ll> pii;

const int maxn = 5050;

int n, m, f[maxn][maxn], a[maxn], b[maxn];

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n + 1; ++i)
    {
        for (int j = 0; j <= n + 1; ++j)
        {
            f[i][j] = -1e9;
        }
        a[i] = 0;
    }
    for (int i = 1, l, r; i <= m; ++i)
    {
        scanf("%d%d", &l, &r);
        a[l] = r;
    }
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i])
        {
            int p = a[i];
            for (int j = 0; j < i; ++j)
            {
                for (int k = 1; k <= p - i; ++k)
                {
                    f[p][j + k] = max(f[p][j + k], f[i - 1][j] + (p - i + 1 - k) * j);
                }
            }
            i = p;
        }
        else
        {
            for (int j = 0; j <= i; ++j)
            {
                f[i][j] = f[i - 1][j] + j;
                if (j)
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans = max(ans, f[n][i] + i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
    }
    printf("%d\n", ans);
}

int main()
{
    int T = 1;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}