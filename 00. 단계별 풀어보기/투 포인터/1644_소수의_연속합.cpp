#include <iostream>
#include <cmath>

using namespace std;

int N;
int D[4000001];
int result = 0;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        D[i] = i;
    }

    for (int i = 2; i <= N / 2; ++i) {
        if (0 == D[i])
            continue;

        for (int j = 2; j * i <= N; ++j) {
            
            D[i * j] = 0;
        }
    }

    int start = 2;
    int end = start + 1;

    int current = D[start];

    while (start <= N) {

        if (N == start) {
            if (0 != D[start])
                ++result;

            break;
        }

        while (0 == D[end] && end <= N) {
            ++end;
        }

        if (current + D[end] > N || end >= N) {
            ++start;

            while (0 == D[start]) {
                ++start;
            }

            current = D[start];
            end = start + 1;
        }
        else if (current + D[end] == N) {
            ++result;
            ++start;

            while (0 == D[start]) {
                ++start;
            }

            current = D[start];
            end = start + 1;
        }
        else {
            current += D[end];
            ++end;
        }

    }

    cout << result;

    return 0;
}

