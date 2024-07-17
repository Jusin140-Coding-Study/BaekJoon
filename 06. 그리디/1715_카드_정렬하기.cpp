#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        q.push(num);
    }

    int answer = 0;

    for (int i = 0; i < N - 1; ++i) {

        int min = q.top();
        q.pop();

        int min2 = q.top();
        q.pop();

        answer += min2 + min;
        q.push(min2 + min);
    }

    cout << answer;

    return 0;
}
