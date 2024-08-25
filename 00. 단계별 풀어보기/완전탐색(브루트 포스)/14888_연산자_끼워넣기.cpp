#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N;
vector<int> arr;
vector<int> sign;

int maxResult = -1000000001;
int minResult = 1000000001;

void Calculator(int _current, int _depth) {


    if (_depth == N) {

        maxResult = max(_current, maxResult);
        minResult = min(_current, minResult);
    }
    

    for (int i = 0; i < 4; ++i) {

        if (sign[i] > 0) {

            if (0 == i) {
                --sign[i];
                Calculator(_current + arr[_depth], _depth + 1);

            }
            else if (1 == i) {
                --sign[i];
                Calculator(_current - arr[_depth], _depth + 1);
            }
            else if (2 == i) {
                --sign[i];
                Calculator(_current * arr[_depth], _depth + 1);
            }
            else if (3 == i) {
                --sign[i];
                Calculator(_current / arr[_depth], _depth + 1);
            }

            ++sign[i];
        }
    }


}

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

    Calculator(arr[0], 1);


    cout << maxResult << "\n";
    cout << minResult << "\n";

    return 0;
}

