#include <iostream>
#include <vector>
using namespace std;

long long largest_two_numbers(const vector<int>& numbers){
    long long max1 = -1;
    long long max2 = -1;
    for(int num : numbers){
        if(num > max1){
            max2 = max1;
            max1 = num;
        } else if (num >= max2) {
            max2 = num;
        }
    }
    return max1 * max2;
}


int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(int i = 0 ; i < n; i++){
        cin >> numbers[i];
    }
    long long max = largest_two_numbers(numbers);
    cout << max << "\n";
return 0;
}
