#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

   and submit it to the grader.

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacci_fast(int n) {
    
    if (n <= 1) {
        return n;
    }

    vector<long long> numbers(n + 1);
    numbers[0] = 0;
    numbers[1] = 1;
    for (int i = 2; i <= n; i++){
        numbers[i] = numbers[i - 1] + numbers[i - 2];

    }
    long long res = numbers[n];

    return res;


}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    cin >> n;
    long long result = fibonacci_fast(n);
    cout << result;
    return 0;
}
