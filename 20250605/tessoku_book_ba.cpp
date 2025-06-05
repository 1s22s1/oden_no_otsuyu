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

    int Q;
    cin >> Q;

    priority_queue<int, vector<int>, greater<int>> pqueue;

    for (auto _ : ranges::views::iota(0, Q))
    {
        int query;
        cin >> query;

        switch (query)
        {
        case 1:
            int price;
            cin >> price;

            pqueue.push(price);

            break;
        case 2:
            cout << pqueue.top() << endl;
            break;
        case 3:
            pqueue.pop();

            break;
        }
    }

    return 0;
}
