#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


long long get_fibonacci_last_digit(int n) {
    if (n <= 1) {
        return n;
    }
    vector<long long> numbers(n + 1);
    numbers[0] = 0;
    numbers[1] = 1;
    for (int i = 2; i <= n; i++){
        numbers[i] = (numbers[i - 1] + numbers[i - 2]) % 10;

    }
    long long res = numbers[n];
    return res;

}

int main() {
    int n = 0;
    cin >> n;
    long long result = get_fibonacci_last_digit(n);
    cout << result;
    return 0;
}
