#include <bits/stdc++.h>
using namespace std;
#define all(a) ((a).begin()) , ((a).end())
typedef vector<int> vi;

int main()
{

ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> a;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a.emplace_back(l, r, i);
    }
    sort(all(a));

    int ptr = 0;
    int cur = 1;
    int max_r = 0;
    vi ans;
    while (cur <= m) {
        int idx = -1;
        while (ptr < n and get<0>(a[ptr]) <= cur) {
            if (get<1>(a[ptr]) > max_r) {
                max_r = get<1>(a[ptr]);
                idx = get<2>(a[ptr]);
            }
            ++ptr;
        }

        if (idx == -1) {
            ans.clear();
            break;
        } else {
            ans.push_back(idx);
            cur = max_r + 1;
        }
    }

    if (ans.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << ans.size() << '\n';
        for (int x : ans) {
            cout << (x + 1) << ' ';
        }
    }
    return 0;
}
