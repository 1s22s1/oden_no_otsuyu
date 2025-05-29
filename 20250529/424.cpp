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

    int H, W;
    cin >> H >> W;

    int X0, Y0, X1, Y1;
    cin >> X0 >> Y0 >> X1 >> Y1;

    vector<string> S(H);
    for (auto &row : S)
    {
        cin >> row;
    }

    queue<pair<int, int>> queue;
    vector<vector<int>> dist(H, vector<int>(W, -1));

    queue.push({X0, Y0});
    dist.at(X0).at(Y0) = 0;

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    while (!queue.empty())
    {
        pair<int, int> tmp = queue.front();
        int x = tmp.first;
        int y = tmp.second;
        queue.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int x2 = x + dx.at(dir), y2 = y + dy.at(dir);

            if (x2 < 0 || x2 >= H || y2 < 0 || y2 >= W)
            {
                continue;
            }

            if (S.at(x2).at(y2) == 'B')
            {
                continue;
            }

            if (dist.at(x2).at(y2) != -1)
            {
                continue;
            }

            queue.push({x2, y2});
            dist.at(x2).at(y2) = dist.at(x).at(y) + 1;
        }
    }

    cout << dist.at(X1).at(Y1) << endl;

    return 0;
}
