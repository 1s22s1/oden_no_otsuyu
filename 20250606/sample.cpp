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

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(1);
    pq.push(3);
    pq.push(2);

    cout << pq.top() << endl;

    return 0;
}
