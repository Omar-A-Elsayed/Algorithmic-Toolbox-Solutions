#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int counter = 0;
  int res = -1;
  for(int i = 0; i < a.size(); i++){
    if(counter == 0){
        res = a[i];
        counter = 1;
    }
    else if(a[i] == res){
        counter++;
    }
    else{
        counter--;
    }
  }
  counter = 0;
  for(int i = 0; i < a.size(); i++){
    if(a[i] == res){
        counter++;
    }
  }
  if(counter > (a.size() / 2)){
    return res;
  } else {
    return -1;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
