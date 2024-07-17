#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool Comp(pair<int, string > a, pair<int, string > b) {

    if (a.first < b.first) {
        return true;
    }

    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, string>> v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i].first;
        cin >> v[i].second;
    }
    

    stable_sort(v.begin(), v.end(), Comp);

    for (int i = 0; i < v.size(); ++i) {

        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}
