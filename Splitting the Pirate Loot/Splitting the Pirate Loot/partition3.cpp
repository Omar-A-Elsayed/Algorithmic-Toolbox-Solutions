#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool backtrack(vector<int>& A, vector<int>& groups, int index, int target) {
    if (index == A.size()) {
        return groups[0] == target && groups[1] == target && groups[2] == target;
    }

    for (int i = 0; i < 3; i++) {
        if (groups[i] + A[index] <= target) {
            groups[i] += A[index];
            if (backtrack(A, groups, index + 1, target)) return true;
            groups[i] -= A[index];
        }
        if (groups[i] == 0) break;
    }

    return false;
}

int partition3(vector<int>& A) {
    int totalSum =  std::accumulate(A.begin(), A.end(), 0);
    if (totalSum % 3 != 0) return 0;

    sort(A.rbegin(), A.rend());
    vector<int> groups(3, 0);
    return backtrack(A, groups, 0, totalSum / 3) ? 1 : 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        cin >> A[i];
    }

    cout << partition3(A) << '\n';
    return 0;
}
