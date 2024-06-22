#include <iostream>
#include <vector>
using namespace std;

long long get_fibonacci_partial_sum(long long from, long long to) {
    int pisano_period = 60;
    long long to_remainder = to % pisano_period;
    long long from_remainder = from % pisano_period;

        if(from_remainder > to_remainder){
            to_remainder += pisano_period;
        }

    long long sum = 0;
    long long current = 0;
    long long next  = 1;


    for (long long i = 0; i <= to_remainder; i++) {

        if (i >= from_remainder) {
            sum = (sum + current)%10;
        }

        long long new_current = next;
        next = (next + current) % 10;
        current = new_current;

    }

    return sum % 10;
}

int main() {
    long long from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum(from, to) << '\n';

}
