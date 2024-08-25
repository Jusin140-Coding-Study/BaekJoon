#include <iostream>
#include <vector>

using namespace std;

int N;

int maxResult = -1000000001;
int minResult = 1000000001;

vector<int> arr;
vector<int> sign;

void DFS(int _currentIdx, int _result);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    arr.resize(N);
    sign.resize(4);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < 4; ++i) {
        cin >> sign[i];
    }

    DFS(1, arr[0]);

    cout << maxResult << "\n" << minResult;

    return 0;
}


void DFS(int _currentIdx, int _result) {

    if (_currentIdx == N) {
        maxResult = max(maxResult, _result);
        minResult = min(minResult, _result);

        return;
    }

    for (int i = 0; i < 4; ++i) {

        if (sign[i] > 0) {
            --sign[i];

            if (0 == i) {
                DFS(_currentIdx + 1, _result + arr[_currentIdx]);
            }
            else if (1 == i) {
                DFS(_currentIdx + 1, _result - arr[_currentIdx]);
            }
            else if (2 == i) {
                DFS(_currentIdx + 1, _result * arr[_currentIdx]);
            }
            else if (3 == i) {
                DFS(_currentIdx + 1, _result / arr[_currentIdx]);
            }
            ++sign[i];
        }
    }

}
