#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};

bool compare(Segment x, Segment y){
    return x.end < y.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  sort(segments.begin(), segments.end(), compare);
  int current_point = segments[0].end;
  points.push_back(current_point);

  for (size_t i = 0; i < segments.size(); ++i) {
     if (current_point < segments[i].start || current_point > segments[i].end) {
            current_point = segments[i].end;
            points.push_back(current_point);
        }
  }
  return points;
}

int main() {
  int n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    cout << points[i] << " ";
  }
}
