#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int N, M;
vector<long long> nodes;
long long startIndex;

long long FindMin(long long s, long long e);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M;

    long long powNum = 1;
    while (true) {

        powNum *= 2;

        if (N <= powNum) {

            startIndex = powNum;
            nodes.resize(powNum * 2);
            break;
        }

    }

    //배열 채우기
    for (long long i = startIndex; i < startIndex + N; ++i) {
        cin >> nodes[i];
    }

    for (long long i = startIndex - 1; i > 0; --i) {
        nodes[i] = min(nodes[2 * i], nodes[2 * i + 1]);
    }

    for (long long i = 0; i < M; ++i) {

        long long start, end;
        cin >> start >> end;

        start = start + startIndex - 1;
        end = end + startIndex - 1;

        cout << FindMin(start, end) << "\n";

    }


    return 0;
}


long long FindMin(long long s, long long e) {

    long long answer = LLONG_MAX;

    while (e >= s) {


        if (1 == s % 2) {
            
            answer = min(nodes[s], answer);
            ++s;
        }

        if (0 == e % 2) {
            answer = min(nodes[e], answer);
            --e;
        }

        s = s / 2;
        e = e / 2;

    }

    return answer;

}
