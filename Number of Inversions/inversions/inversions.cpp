#include <iostream>
#include <vector>
using namespace std;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
    size_t i = left, j = ave, k = left;
    while (i < ave && j < right) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
            number_of_inversions += ave - i;
        }
    }

    while (i < ave) b[k++] = a[i++];
    while (j < right) b[k++] = a[j++];

    for (size_t i = left; i < right; i++) {
        a[i] = b[i];
    }
  return number_of_inversions;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  vector<int> b(a.size());
  cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
