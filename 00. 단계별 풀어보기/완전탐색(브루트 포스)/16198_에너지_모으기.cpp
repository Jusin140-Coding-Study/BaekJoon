#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;
vector<bool> visited;

void DFS(int _result, int _count);
int answer = 0;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    arr.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    DFS(0, 0);

    cout << answer;

    return 0;
}

void DFS(int _result, int _count) {

    if (_count == N - 2) {
        answer = max(answer, _result);
        return;
    }


    for (int i = 1; i < N - 1; ++i) {
        if (!visited[i]) {
            visited[i] = true;

            int prev = i;
            int next = i;

            while (--prev) {
                if (!visited[prev]) {
                    break;
                }
            }

            while (++next) {
                if (!visited[next]) {
                    break;
                }
            }

            DFS(_result + (arr[prev] * arr[next]), _count + 1);
            visited[i] = false;
        }
    }
}

