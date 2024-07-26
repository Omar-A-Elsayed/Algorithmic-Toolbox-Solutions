#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(int x, int y){
    return x > y;
}

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here

  sort(a.begin(), a.end(), compare);
  sort(b.begin(), b.end(), compare);
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    cin >> b[i];
  }
  cout << max_dot_product(a, b) << endl;
}
