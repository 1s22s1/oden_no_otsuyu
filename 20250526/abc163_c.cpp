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

    int N;
    cin >> N;

    vector<vector<int>> G(N, vector<int>());

    for (auto i : ranges::views::iota(0, N - 1))
    {
        int a;
        cin >> a;

        G.at(a - 1).push_back(i + 1);
    }

    for (const auto &e : G)
    {
        cout << e.size() << endl;
    }

    return 0;
}
