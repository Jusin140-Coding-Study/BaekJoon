#include <iostream>
#include <vector>

using namespace std;

vector<pair<long long, long long>> points;
int result[4];


int CCW(pair<long long, long long> _p1, pair<long long, long long> _p2, pair<long long, long long> _p3) {

    long long result = (_p1.first * _p2.second + _p2.first * _p3.second + _p3.first * _p1.second) -
        (_p2.first * _p1.second + _p3.first * _p2.second + _p1.first * _p3.second);

    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;

    return 0;

}

bool IsOverlab(pair<long long, long long> _p1, pair<long long, long long> _p2, pair<long long, long long> _p3, pair<long long, long long> _p4) {

    if (min(_p1.first, _p2.first) <= max(_p3.first, _p4.first) && min(_p3.first, _p4.first) <= max(_p1.first, _p2.first) &&
        min(_p1.second, _p2.second) <= max(_p3.second, _p4.second) && min(_p3.second, _p4.second) <= max(_p1.second, _p2.second))
        return true;

    return false;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    points.resize(4);

    for (int i = 0; i < 4; ++i) {
        cin >> points[i].first;
        cin >> points[i].second; 
    }

    //선분 A-B에 대해서 
    result[0] = CCW(points[0], points[1], points[2]);
    result[1] = CCW(points[0], points[1], points[3]);

    //선분 C-D에 대해서 
    result[2] = CCW(points[2], points[3], points[0]);
    result[3] = CCW(points[2], points[3], points[1]);

    if (result[0] * result[1] == 0 && result[2] * result[3] == 0) {

        cout << IsOverlab(points[0], points[1], points[2], points[3]);
        return 0;
    }

    if (result[0] * result[1] <= 0 && result[2] * result[3] <= 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}

