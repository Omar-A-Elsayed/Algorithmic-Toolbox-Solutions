#include <iostream>
using namespace std;

int fibonacci_sum_squares(long long n) {
    int pisano_period = 60;
    long long remainder = n % pisano_period;
    if (remainder <= 1)
        return remainder;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 1; i < remainder ; i++) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current % 10;
        sum += current * current;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
}
