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

    int N;
    cin >> N;

    vector<int> A(N);

    rep(i, N)
    {
        cin >> A.at(i);
    }

    auto answer = -1;

    for (auto e : A)
    {
        auto count = 0;

        for (auto f : A)
        {
            if (e <= f)
            {
                count++;
            }
        }

        if (e <= count)
        {
            answer = max(answer, e);
        }
    }

    for (auto e : A)
    {
        auto count = 0;

        for (auto f : A)
        {
            if (e - 1 <= f)
            {
                count++;
            }
        }

        if (e - 1 <= count)
        {
            answer = max(answer, e - 1);
        }
    }

    cout << answer << endl;

    return 0;
}
