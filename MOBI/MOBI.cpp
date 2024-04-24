#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool compare_x(const Point& a, const Point& b) {
    return a.x < b.x;
}

int main() {
    ifstream in("MOBI.INP");
    ofstream out("MOBI.OUT");

    int n, k;
    in >> n >> k;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        in >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), compare_x);

    long long max_users = 0;
    for (int i = 0; i < n; i++) {
        int left = points[i].x - k;
        int right = points[i].x + k;
        long long users = points[i].y;
        for (int j = i + 1; j < n; j++) {
            if (points[j].x > right) {
                break;
            }
            if (points[j].x >= left) {
                users += points[j].y;
            }
        }
        if (users > max_users) {
            max_users = users;
        }
    }

    out << max_users << endl;

    return 0;
}
