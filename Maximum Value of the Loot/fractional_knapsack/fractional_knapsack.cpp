#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
    double ratio_of_item;
};

bool compare(Item x, Item y) {
    return x.ratio_of_item > y.ratio_of_item;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    int n = values.size();
    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        items[i] = {values[i], weights[i], (double)values[i] / weights[i]};
    }

    sort(items.begin(), items.end(), compare);

    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            return value;
        }
        int a = min(items[i].weight, capacity);
        value += a * items[i].ratio_of_item;
        //items[i].weight -= a;
        capacity -= a;
    }

    return value;
}

int main() {
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}
