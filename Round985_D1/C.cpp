#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (auto &val : a)
            std::cin >> val;

        int x = 0;
        std::vector<int> delta(n);
        for (int i = 0; i < n; ++i)
        {
            if (a[i] > x)
            {
                delta[i] = 1;
                ++x;
            }
            else if (a[i] == x)
            {
                delta[i] = 0;
            }
            else
            {
                delta[i] = -1;
                --x;
            }
        }

        int x_final = x;

        std::vector<int> gain(n);
        std::transform(delta.begin(), delta.end(), gain.begin(), [](int d)
                       { return -d; });

        int max_gain = gain[0], current_gain = gain[0];
        for (int i = 1; i < n; ++i)
        {
            current_gain = std::max(gain[i], current_gain + gain[i]);
            max_gain = std::max(max_gain, current_gain);
        }

        std::cout << x_final + max_gain << '\n';
    }

    return 0;
}