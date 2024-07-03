#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compare(string x, string y){
    if(x + y > y + x){
        return 1;
    }
    else if(x + y < y + x){
        return 0;
    }
}

string largest_number(vector<string> a) {
  //write your code here
  sort(a.begin(), a.end(), compare);
  stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  cout << largest_number(a);
}
