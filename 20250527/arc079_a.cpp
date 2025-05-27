#include <bits/stdc++.h>

using namespace std;

#define endl '\n';
#define ll long long

using Graph = vector<vector<int>>;

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

    Graph G(N);

    for (auto i : ranges::views::iota(0, M))
    {
        int a, b;
        cin >> a >> b;

        G.at(a - 1).push_back(b - 1);
        G.at(b - 1).push_back(a - 1);
    }

    bool satisfy = false;

    for (const auto &e : G)
    {
        if (find(e.begin(), e.end(), 0) != e.end() && find(e.begin(), e.end(), N - 1) != e.end())
        {
            satisfy = true;
        }
    }

    if (satisfy)
    {
        cout << "POSSIBLE" << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
