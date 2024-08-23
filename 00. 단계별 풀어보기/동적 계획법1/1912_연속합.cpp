#include <iostream>

using namespace std;

int origin[100001];
int add[100001];

int N;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> origin[i];
    }

    add[0] = origin[0];

    for (int i = 1; i < N; ++i) {
        add[i] = max(origin[i], add[i - 1] + origin[i]);
    }

    int answer = add[0];

    for (int i = 1; i < N; ++i) {
        answer = max(answer, add[i]);
    }

    cout << answer;

    return 0;
}

