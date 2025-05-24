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

int N;
void f(string s)
{
    if (s.size() == N)
    {
        cout << s << endl;

        return;
    }

    for (char c = 'a'; c <= 'c'; c++)
    {
        f(s + c);
    }
}

int main()
{
    init();

    cin >> N;

    f("");

    return 0;
}
