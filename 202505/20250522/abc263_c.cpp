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
        for (const auto &v : vec)
        {
            cout << v << ' ';
        }

        cout << endl;
    }

    for (int i = vec.back() + 1; i <= M; i++)
    {
        vec.push_back(i);
        f(vec);
        vec.pop_back();
    }
}

int main()
{
    init();

    cin >> N >> M;

    for (int i = 1; i <= M; i++)
    {
        vector<int> vec = {i};

        f(vec);
    }

    return 0;
}
