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

    vector<vector<int>> G(N, vector<int>());

    for (auto _i : ranges::views::iota(0, M))
    {
        int a, b;
        cin >> a >> b;

        G.at(a - 1).push_back(b - 1);
        G.at(b - 1).push_back(a - 1);
    }

    for (const auto &e : G)
    {
        cout << e.size() << endl;
    }

    return 0;
}
