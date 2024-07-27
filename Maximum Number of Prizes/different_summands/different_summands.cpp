#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int current_number = 1;

  while (n > 0) {
    if (n - current_number > current_number) {
      summands.push_back(current_number);
      n -= current_number;
      current_number++;
    } else {
      summands.push_back(n);
      break;
    }
  }
  return summands;
}

int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}
