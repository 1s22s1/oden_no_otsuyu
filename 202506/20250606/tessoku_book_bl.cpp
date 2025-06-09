#include <bits/stdc++.h>

using namespace std;

#define endl '\n';
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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

    vector<vector<pair<int, int>>> graph(N);
    rep(i, M)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph.at(a - 1).push_back({b - 1, c});
        graph.at(b - 1).push_back({a - 1, c});
    }

    vector<bool> confirmed(N, false);
    vector<int> distance(N, INT_MAX);
    distance.at(0) = 0;

    while (true)
    {
        int current = -1;
        int current_distance = INT_MAX;
        rep(i, N)
        {
            if (!confirmed.at(i) && distance.at(i) <= current_distance)
            {
                current = i;
                current_distance = distance.at(i);
            }
        }

        if (current == -1)
        {
            break;
        }

        for (auto e : graph.at(current))
        {
            auto next = e.first;
            auto cost = e.second;

            distance.at(next) = min(distance.at(next), distance.at(current) + cost);
        }

        confirmed.at(current) = true;
    }

    rep(i, N)
    {
        cout << distance.at(i) << endl;
    }

    return 0;
}
