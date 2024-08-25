#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N;
vector<int> arr;
vector<int> sum;

void DFS(int _startIdx, int _result);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    arr.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; ++i) {
        DFS(i + 1, arr[i]);
    }

    sort(sum.begin(), sum.end());
    sum.erase(unique(sum.begin(), sum.end()), sum.end());

    int count = 1;
    int idx = 0;

    while (true) {

        if (idx >= (int)sum.size()) {
            cout << count;
            break;
        }

        if (count != sum[idx]) {
            cout << count;
            break;
        }

        ++count;
        ++idx;
    }

    return 0;
}


void DFS(int _startIdx, int _result) {

    sum.push_back(_result);

    for (int i = _startIdx; i < N; ++i) {
        DFS(i + 1, _result + arr[i]);
    }
}

