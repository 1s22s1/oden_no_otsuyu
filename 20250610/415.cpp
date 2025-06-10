#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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

    int N, X;
    cin >> N >> X;

    vector<int> A(N);
    A.at(0) = -1;

    for (int i = 1; i < N; i++)
    {
        cin >> A.at(i);
    }

    auto answer = 0;

    while (A.at(X) != -1)
    {
        X = A.at(X);
        answer++;
    }

    cout << answer << endl;

    return 0;
}
