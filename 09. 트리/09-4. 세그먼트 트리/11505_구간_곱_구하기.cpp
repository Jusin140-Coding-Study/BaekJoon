#include <iostream>
#include <vector>

using namespace std;
int N, M, K;

long long startIndex = 0;

vector<long long> nodes;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long maxIndex = 1;

    cin >> N >> M >> K;

    while (true) {

        maxIndex *= 2;

        if (maxIndex >= N) {
            startIndex = maxIndex;
            nodes.resize(startIndex * 2);
            break;
        }

    }


    for (long long i = startIndex; i < startIndex + N; ++i) {
        cin >> nodes[i];
    }

    //곱 배열 채워놓기
    for (long long i = startIndex - 1; i > 0; --i) {

        nodes[i] = (nodes[i * 2] * nodes[i * 2 + 1]);
        nodes[i] %= 1000000007;
    }

    for (int i = 0; i < M + K; ++i) {

        int command;
        long long first, second;

        cin >> command >> first >> second;

        //숫자 변경
        if (1 == command) {

            first = first + startIndex - 1;
            nodes[first] = second;

            for (int k = first / 2; k > 0; k /= 2) {

                nodes[k] = (nodes[k * 2] * nodes[k * 2 + 1]);
                nodes[k] %= 1000000007;
            }


            //곱 출력
        }
        else if (2 == command) {

            long long answer = 1;

            first = first + startIndex - 1;
            second = second + startIndex - 1;

            while (second >= first) {

                if (first % 2 == 1) {

                    answer *= nodes[first];
                    answer %= 1000000007;

                    ++first;
                }

                if (second % 2 == 0) {
                    answer *= nodes[second];
                    answer %= 1000000007;
                    --second;
                }

                second = second / 2;
                first = first / 2;

            }


            cout << answer << "\n";

        }


    }


    return 0;
}
