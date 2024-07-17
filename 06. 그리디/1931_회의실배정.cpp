#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N, {0, 0});

    for (int i = 0; i < N; ++i) {

        int s, e;
        cin >> s >> e;

        v[i] = { e, s };

    }

    sort(v.begin(), v.end());


    int end = -1;
    int answer = 0;
    
    for (int i = 0; i < v.size(); ++i) {

        if (v[i].second >= end) {
            ++answer;
            end = v[i].first;
        }

    }


    cout << answer;

    return 0;
}
