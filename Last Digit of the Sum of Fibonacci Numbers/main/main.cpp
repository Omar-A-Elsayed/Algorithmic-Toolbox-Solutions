#include <iostream>
using namespace std;


long long fibonacci_sum_fast(long long n) {
    int period = 60;
    long long remainder = n % period;
    if (remainder <= 1)
        return remainder;

    long long a = 0;
    long long b  = 1;
    long long sum = 1;

    for (long long i = 1; i < remainder; i++) {
        long long res = (a + b) % 10;
        a = b;
        b = res;
        sum += b;
    }

    return sum % 10;
}
int main()
{
long long n;
cin >> n;
cout << fibonacci_sum_fast(n);

return 0;
}
