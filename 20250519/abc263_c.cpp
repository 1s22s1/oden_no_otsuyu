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

void f(int rest, int M, vector<int> vec)
{
    // cout << rest << ' ' << M << ' ' << endl;

    if (rest == 0)
    {
        for (const auto &e : vec)
        {
            cout << e << ' ';
        }

        cout << endl;
    }

    for (int i = vec.back() + 1; i <= M; i++)
    {
        vec.push_back(i);
        f(rest - 1, M, vec);
        vec.pop_back();
    }
}

int main()
{
    init();

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
    {
        vector<int> vec;
        vec.push_back(i);

        f(N - 1, M, vec);
    }

    return 0;
}
