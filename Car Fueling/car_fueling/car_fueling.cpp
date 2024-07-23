#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int num_refills = 0;
    int current_position = 0;
    int n = stops.size();

    stops.push_back(dist);
    for(int i = 0; i <= n; i++){
        if (stops[i + 1] - stops[i] > tank){
           return -1;
        }
        if(stops[i] - current_position > tank){
        current_position = stops[i - 1];
        num_refills++;
        }
    }
    return num_refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
