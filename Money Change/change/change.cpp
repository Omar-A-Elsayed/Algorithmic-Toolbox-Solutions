#include <iostream>

using namespace std;

int get_change(int money) {
  int n = 0;
  while(money > 0){
    if(money >= 10){
        money = money - 10;
    }
    else if(money >= 5){
        money = money - 5;
    }
    else
        money = money - 1;
    n += 1;
  }
  return n;
}

int main() {
  int money;
  cin >> money;
  cout << get_change(money) << "\n";
}
