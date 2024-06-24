#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0){
        return a;
    }
    int a_remainder = a % b;
    return gcd(b, a_remainder);
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b) << "\n";
  return 0;
}
