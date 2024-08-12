#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> points;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    points.resize(3);

    for (int i = 0; i < 3; ++i) {

        cin >> points[i].first;
        cin >> points[i].second;

    }

    int result = (points[0].first * points[1].second +
        points[1].first * points[2].second +
        points[2].first * points[0].second) -
        (points[1].first * points[0].second +
            points[2].first * points[1].second +
            points[0].first * points[2].second);

    if (0 < result) {
        cout << 1;
    }
    else if (0 == result) {
        cout << 0;
    }
    else {
        cout << -1;
    }



    return 0;
}

