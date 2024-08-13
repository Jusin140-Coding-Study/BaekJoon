#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long weights[31];
//vector<long long> weights;

int N;
long long C;
long long answer = 0;

void BinarySum(int _start, int _end, vector<long long>& _v, long long _sum);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    //weights.resize(N, 0);

    for (int i = 0; i < N; ++i) {

        cin >> weights[i];
    }

    vector<long long> left;
    vector<long long> right;

    BinarySum(0, (N / 2) - 1, left, 0);
    BinarySum(N/ 2, (N - 1), right, 0);

    sort(right.begin(), right.end());

    long long rest = 0;

    for (int i = 0; i < (int)left.size(); ++i) {
        rest = C - left[i];
        answer += upper_bound(right.begin(), right.end(), rest) - right.begin();
    }


    cout << answer;

    return 0;
}


void BinarySum(int _start, int _end, vector<long long>& _v, long long _sum) {

    if (_end < _start)
        _v.push_back(_sum);
    else {
        BinarySum(_start + 1, _end, _v, _sum);
        BinarySum(_start + 1, _end, _v, _sum + weights[_start]);
    }
}