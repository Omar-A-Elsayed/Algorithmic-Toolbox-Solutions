#include <iostream>
#include <vector>
using namespace std;

int optimal_weight(int W, const vector<int> &w) {
    int n = w.size();
    vector<vector<int>> solutions(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int capacity = 1; capacity <= W; capacity++) {
            // Case 1) Ignore the item
            solutions[i][capacity] = solutions[i - 1][capacity];
            // Case 2) Take the item
            if (w[i - 1] <= capacity) {
                solutions[i][capacity] = max(solutions[i][capacity], solutions[i - 1][capacity - w[i - 1]] + w[i - 1]);
            }
        }
    }

    return solutions[n][W];
}

int main() {
    int n, W;
    cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    cout << optimal_weight(W, w) << '\n';
}
