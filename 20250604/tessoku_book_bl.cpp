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

    vector<vector<pair<int, int>>> g(N);

    for (auto _ : ranges::views::iota(0, M))
    {
        int a, b, c;
        cin >> a >> b >> c;

        g.at(a - 1).push_back(make_pair(b - 1, c));
        g.at(b - 1).push_back(make_pair(a - 1, c));
    }

    vector<bool> confirmed(N, false);
    vector<int> distance(N, INT_MAX);

    distance.at(0) = 0;
    while (true)
    {
        int current = -1;
        int min_it = INT_MAX;
        for (auto i : ranges::views::iota(0, N))
        {
            if (!confirmed.at(i) && distance.at(i) <= min_it)
            {
                current = i;
                min_it = distance.at(i);
            }
        }

        if (current == -1)
        {
            break;
        }

        confirmed.at(current) = true;
        for (auto e : g.at(current))
        {
            int next = e.first;
            int cost = e.second;

            distance.at(next) = min(distance.at(next), distance.at(current) + cost);
        }
    }

    for (auto e : distance)
    {
        cout << e << endl;
    }

    return 0;
}
