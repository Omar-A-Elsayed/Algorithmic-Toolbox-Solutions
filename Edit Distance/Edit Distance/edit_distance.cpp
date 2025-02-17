#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int n = str1.length(), m = str2.length();

    vector<vector<int>> vector1(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) vector1[i][0] = i;
    for (int j = 0; j <= m; j++) vector1[0][j] = j;

    // Edit Distance
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                vector1[i][j] = vector1[i - 1][j - 1];
            } else {
                vector1[i][j] = min({vector1[i - 1][j - 1] + 1,
                                vector1[i - 1][j] + 1,
                                vector1[i][j - 1] + 1});
            }
        }
    }
    return vector1[n][m];
  return 0;
}

int main() {
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << endl;
  return 0;
}
