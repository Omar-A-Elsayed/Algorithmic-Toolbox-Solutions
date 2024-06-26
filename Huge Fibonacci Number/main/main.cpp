#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

long pisano_period(long long m){
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }

}

long long get_fibonacci_huge(long long n, long long m) {
    // write your code here
    long long period = pisano_period(m);
    long long remainder = n % period;
    if ( remainder <= 1) {
        return remainder;
    }
    long long first = 0;
    long long second = 1;

    long long res = remainder;
    for (int i = 1; i < remainder; i++){
        res = (first + second) % m;
        first = second;
        second = res;

    }
    return res % m;





}

int main()
{
    long long n, m;
    cin >> n >> m;
    long long result = get_fibonacci_huge(n, m);
    cout << result;


return 0;
}
