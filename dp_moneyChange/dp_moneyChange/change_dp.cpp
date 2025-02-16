#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int get_change(int m) {
    vector<int> coins = {1, 3, 4};
    vector<int> MinNumCoins(m + 1, INT_MAX);

    MinNumCoins[0] = 0;

    for (int money = 1; money <= m; ++money) {
        for (int coin : coins) {
            if (money >= coin) {
                int NumCoins = MinNumCoins[money - coin] + 1;
                if (NumCoins < MinNumCoins[money]) {
                    MinNumCoins[money] = NumCoins;
                }
            }
        }
    }

    return MinNumCoins[m];
}

int main() {
    int m;
    cin >> m;
    cout << get_change(m) << '\n';
}
