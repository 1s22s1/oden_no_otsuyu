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

    auto answer = 0;

    for (auto a : A)
    {
        auto count = 0;
        for (auto b : A)
        {
            if (b >= a)
            {
                count++;
            }
        }

        if (count >= a)
        {
            answer = max(answer, a);
        }
    }

    cout << answer << endl;

    return 0;
}
