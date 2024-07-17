#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v(5);

    for (int i = 0; i < 5; ++i) {
        cin >> v[i];
    }

    float avg = ((float)accumulate(v.begin(), v.end(), 0)) / 5.f;

    sort(v.begin(), v.end(), less<int>());

    cout << avg << "\n";
    cout << v[2] << "\n";

    return 0;
}
