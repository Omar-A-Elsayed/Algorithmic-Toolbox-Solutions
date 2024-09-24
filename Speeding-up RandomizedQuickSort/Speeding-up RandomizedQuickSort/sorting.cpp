#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
using std::swap;

void partition3(vector<int> &a, int l, int r, int &lt, int &gt) {
  int pivot = a[l];
  lt = l;
  gt = r;
  int i = l;

  while (i <= gt) {
    if (a[i] < pivot) {
      swap(a[i], a[lt]);
      lt++;
      i++;
    } else if (a[i] > pivot) {
      swap(a[i], a[gt]);
      gt--;
    } else {
      i++;
    }
  }
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);

  int lt, gt;
  partition3(a, l, r, lt, gt);

  randomized_quick_sort(a, l, lt - 1);
  randomized_quick_sort(a, gt + 1, r);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
}
