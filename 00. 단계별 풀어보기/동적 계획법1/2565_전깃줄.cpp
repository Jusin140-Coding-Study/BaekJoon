#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> arr;
vector<int> DP;
int N;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    arr.resize(N);
    DP.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i].second;
        cin >> arr[i].first;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; ++i) {
        DP[i] = 1;
        for (int j = i - 1; j >= 0; --j) {
            if (arr[j].second < arr[i].second) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }

    int maxElement = *max_element(DP.begin(), DP.end());
    cout << N - maxElement;

    return 0;
}

