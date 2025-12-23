#include <bits/stdc++.h>
using namespace std;

static inline int mex_from_counts(const vector<int>& cnt, int n) {
    int x = 0;
    while (x <= n + 1) {
        if (x >= (int)cnt.size() || cnt[x] == 0) return x;
        ++x;
    }
    return n + 1;
}

static inline vector<int> one_step(const vector<int>& a, int n, long long &sum_out) {
    vector<int> cnt(n + 2, 0);
    int i = 0;
    while (i < n) { ++cnt[a[i]]; ++i; }

    int M = mex_from_counts(cnt, n);

    vector<int> nxt(n);
    long long s = 0;
    i = 0;
    while (i < n) {
        int v = a[i];
        if (v < M && cnt[v] == 1) nxt[i] = v;
        else nxt[i] = M;
        s += nxt[i];
        ++i;
    }
    sum_out = s;
    return nxt;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return;
    while (T--) {
        int n; long long k;
        cin >> n >> k;
        vector<int> a(n);
        int i = 0;
        while (i < n) { cin >> a[i]; ++i; }

        long long sum1 = 0;
        vector<int> A1 = one_step(a, n, sum1);

        if (k == 1) {
            cout << sum1 << '\n';
            continue;
        }

        long long sum2 = 0;
        vector<int> A2 = one_step(A1, n, sum2);

        cout << ((k % 2 == 1) ? sum1 : sum2) << '\n';
    }
}

int main() {
    solve();
    return 0;
}
