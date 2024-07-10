//나중에 다시 풀어보기

#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    long count = 0;

    vector<long> sums(N, 0);
    vector<long> C(M, 0);

    cin >> sums[0];

    for (int i = 1; i < N; ++i) {
        int num;
        cin >> num;

        sums[i] = (num + sums[i - 1]);
    }


    for (int i = 0; i < N; ++i) {
        
        int remainder = sums[i] % M;

        if (0 == remainder)
            ++count;

        C[remainder]++;
       
    }

    for (int i = 0; i < M; ++i) {

        if (C[i] > 1) {
            count = count + (C[i] * (C[i] - 1) / 2);
        }

    }


    cout << count<< "\n";

    return 0;
}