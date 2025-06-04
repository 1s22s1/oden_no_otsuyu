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

int main()
{
    init();

    int N, M;
    cin >> N >> M;

    vector<int> H(N);
    for (auto i : ranges::views::iota(0, N))
    {
        cin >> H.at(i);
    }

    vector<vector<int>> G(N, vector<int>());

    for (auto _ : ranges::views::iota(0, M))
    {
        int a, b;
        cin >> a >> b;

        G.at(a - 1).push_back(b - 1);
        G.at(b - 1).push_back(a - 1);
    }

    int answer = 0;

    for (auto i : ranges::views::iota(0, N))
    {
        bool satisfy = true;

        for (const auto &e : G.at(i))
        {
            if (H.at(i) <= H.at(e))
            {
                satisfy = false;
            }
        }

        if (satisfy)
        {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}
