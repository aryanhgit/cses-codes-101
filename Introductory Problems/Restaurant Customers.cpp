#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, 1});
        arr.push_back({b, -1});
    }
    sort(arr.begin(), arr.end());

    int ans = 0, curr = 0;
    for (auto it : arr)
    {
        curr += it.second;
        ans = max(ans, curr);
    }
    printf("%d\n", ans);
    return 0;
}
