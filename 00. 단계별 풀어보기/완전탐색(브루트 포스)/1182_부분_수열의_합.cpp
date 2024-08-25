#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int S;
vector<int> arr;
vector<bool> visited;

int answer = 0;

void DFS(int _depth, int _result, int _startIdx);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> S;
    arr.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    DFS(0, 0, 0);

    cout << answer;

    return 0;
}

void DFS(int _depth, int _result, int _startIdx) {

    if (_depth != 0 && S == _result) {
        ++answer;
    }

    if ((S >= 0 && _result > S) ||
        (S < 0 && _result > S && arr[_startIdx] > 0) ||
         _depth == N) {
        return;
    }

    for (int i = _startIdx; i < N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            DFS(_depth + 1, _result + arr[i], i + 1);
            visited[i] = false;
        }
    }

}

