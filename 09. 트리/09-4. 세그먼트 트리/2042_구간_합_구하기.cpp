#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
long long indexStart = 0;
vector<long long> nodes;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    long long current = 1;
    while (true) {

        current *= 2;

        if (current >= N) {
            nodes.resize(current * 2);
            indexStart = current;
            break;
        }
    }

    for (long long i = indexStart; i < indexStart + N; ++i) {
        cin >> nodes[i];
    }

    //배열에 구간합 채워넣기
    for (long long i = indexStart - 1; i > 0; --i) {
        nodes[i] = nodes[i * 2] + nodes[i * 2 + 1];
    }


    //수변경 + 구간합 구하기 테케
    for (int i = 0; i < M + K; ++i) {

        int command;
        long long first, second;
        cin >> command >> first >> second;

        if (1 == command) {

            nodes[first + indexStart - 1] = second;

            for (long long i = (first + indexStart - 1) / 2; i > 0; i = i / 2) {
                nodes[i] = nodes[i * 2] + nodes[i * 2 + 1];
            }


        }
        else if (2 == command) {

            long long answer = 0;

            first = first + indexStart - 1;
            second = second + indexStart - 1;

            while (second >= first) {

                if (1 == first % 2) {
                    answer += nodes[first];
                }

                if (0 == second % 2) {
                    answer += nodes[second];
                }

                first = (first + 1) / 2;
                second = (second - 1) / 2;

            }

            cout << answer << "\n";

        }
    }


    return 0;
}
