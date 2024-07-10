#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S, P;
    cin >> S >> P;

    vector<char> letters(S, '0');
    vector<int> numLetters(4, 0);
    int a = 0, c = 0, g = 0, t = 0;
    int answer = 0;

    for (int i = 0; i < S; ++i) {

        cin >> letters[i];

        if ('A' == letters[i]) {
            ++a;
        }
        else if ('C' == letters[i]) {
            ++c;
        }
        else if ('G' == letters[i]) {
            ++g;
        }
        else if ('T' == letters[i]) {
            ++t;
        }

    }

    for (int i = 0; i < 4; ++i) {
        cin >> numLetters[i];
    }

    if (numLetters[0] > a || numLetters[1] > c ||
        numLetters[2] > g || numLetters[3] > t) {
        cout << answer;
        return 0;
    }


    int target = 0;
    int iter = 0;
    int a1 = 0, c1 = 0, g1 = 0, t1 = 0;

    for (int i = 0; i < P; ++i) {
        if ('A' == letters[i]) {
            ++a1;
        }
        else if ('C' == letters[i]) {
            ++c1;
        }
        else if ('G' == letters[i]) {
            ++g1;
        }
        else if ('T' == letters[i]) {
            ++t1;
        }

    }


    if (numLetters[0] <= a1 && numLetters[1] <= c1 &&
        numLetters[2] <= g1 && numLetters[3] <= t1) {
        ++answer;
    }

    ++target;

    while (target + P <= S) {


        if ('A' == letters[target + P -1]) {
            ++a1;
        }
        else if ('C' == letters[target + P - 1]) {
            ++c1;
        }
        else if ('G' == letters[target + P - 1 ]) {
            ++g1;
        }
        else if ('T' == letters[target + P - 1]) {
            ++t1;
        }

        if ('A' == letters[target - 1]) {
            --a1;
        }
        else if ('C' == letters[target - 1]) {
            --c1;
        }
        else if ('G' == letters[target - 1]) {
            --g1;
        }
        else if ('T' == letters[target - 1]) {
            --t1;
        }

        if (numLetters[0] <= a1 && numLetters[1] <= c1 &&
            numLetters[2] <= g1 && numLetters[3] <= t1) {
            ++answer;
        }

        ++target;

    }

    cout << answer;

    return 0;
}