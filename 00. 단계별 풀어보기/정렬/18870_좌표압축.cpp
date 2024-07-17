#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end(), less<pair<int, int>>());

    int count = 0;
    int prev = v[0].first;

    for (int i = 0; i < v.size(); ++i) {

        if (prev == v[i].first) {
            v[i].first = count;
        }
        else {
            prev = v[i].first;
            ++count;
            v[i].first = count;
        }

        int temp = v[i].first;
        v[i].first = v[i].second;
        v[i].second = temp;

    }

    sort(v.begin(), v.end(), less<pair<int, int>>());


    for (int i = 0; i < v.size(); ++i) {

        cout << v[i].second << " ";

    }

    return 0;
}
