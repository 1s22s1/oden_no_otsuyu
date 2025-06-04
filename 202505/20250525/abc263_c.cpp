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

int N, M;

void f(vector<int> vec)
{
    if (vec.size() == N)
    {
        for (const auto &e : vec)
        {
            cout << e << ' ';
        }

        cout << endl;
    }
    else
    {
        for (auto i : ranges::views::iota(vec.back() + 1, M + 1))
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

    cin >> N >> M;

    for (auto i : ranges::views::iota(1, M + 1))
    {
        vector<int> vec = {i};
        f(vec);
    }

    return 0;
}
