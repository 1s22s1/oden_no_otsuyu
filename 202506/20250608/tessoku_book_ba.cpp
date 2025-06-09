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

    int Q;
    cin >> Q;

    priority_queue<int, vector<int>, greater<int>> pq;

    rep(i, Q)
    {
        int pattern;
        cin >> pattern;

        switch (pattern)
        {
        case 1:
            int price;
            cin >> price;

            pq.push(price);

            break;
        case 2:
            cout << pq.top() << endl;

            break;
        case 3:
            pq.pop();

            break;
        }
    }

    return 0;
}
