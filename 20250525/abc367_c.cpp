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

void f(vector<int> vec)
{
    if (vec.size() == N)
    {
        if (accumulate(vec.begin(), vec.end(), 0) % K == 0)
        {
            for (const auto &e : vec)
            {
                cout << e << ' ';
            }

            cout << endl;
        }
    }
    else if (vec.size() <= N)
    {
        for (auto i : ranges::views::iota(1, R.at(vec.size()) + 1))
        {
            vec.push_back(i);
            f(vec);
            vec.pop_back();
        }
    }
}

int main()
{
    init();

    cin >> N >> K;

    for (auto _ : ranges::views::iota(0, N))
    {
        int r;
        cin >> r;

        R.push_back(r);
    }

    vector<int> vec;
    f(vec);

    return 0;
}
