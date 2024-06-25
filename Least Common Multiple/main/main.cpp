#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0){
        return a;
    }
    int a_remainder = a % b;
    return gcd(b, a_remainder);
}

long long lcm(long long a, long long b){
    long long res = (a * b) / gcd(a, b);
    return res;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << lcm(a, b) << "\n";
  return 0;
}
