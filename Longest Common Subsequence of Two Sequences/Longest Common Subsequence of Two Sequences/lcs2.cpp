#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    size_t n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    size_t m;
    cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++) {
        cin >> b[i];
    }

    cout << lcs2(a, b) << endl;
}
