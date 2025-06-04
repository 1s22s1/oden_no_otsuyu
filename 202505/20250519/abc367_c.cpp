#include <bits/stdc++.h>

using namespace std;

#define endl '\n';
#define ll long long

int init()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}

int N, K;
vector<int> R;

void f(int count, vector<int> vec)
{
    if (count == N)
    {
        if (accumulate(vec.begin(), vec.end(), 0) % K == 0)
        {
            for (auto const &e : vec)
            {
                cout << e << ' ';
            }

            cout << endl;
        }
    }
    else
    {
        for (auto i : ranges::views::iota(1, R.at(count) + 1))
        {
            vec.push_back(i);
            f(count + 1, vec);
            vec.pop_back();
        }
    }
}

int main()
{
    init();

    cin >> N >> K;

    for (auto i : ranges::views::iota(0, N))
    {
        int r;
        cin >> r;

        R.push_back(r);
    }

    vector<int> vec;
    f(0, vec);

    return 0;
}
