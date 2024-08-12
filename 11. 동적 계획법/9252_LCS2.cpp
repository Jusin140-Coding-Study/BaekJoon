#include <iostream>
#include <vector>

using namespace std;

string A, B;
int DP[1001][1001];
vector<char> answer;

void GetText(int _r, int _c);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    for (int i = 1; i <= (int)A.size(); ++i) {
        for (int j = 1; j <= (int)B.size(); ++j) {

            if (A[i - 1] == B[j - 1]) {

                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }

        }
    }

    cout << DP[A.size()][B.size()] << "\n";
    GetText(A.size(), B.size());

    for (int i = answer.size() - 1; i >= 0; --i) {
        cout << answer[i];
    }

    return 0;
}


void GetText(int _r, int _c) {

    if (_r == 0 || _c == 0)
        return;

    if (A[_r - 1] == B[_c - 1]) {

        answer.push_back(A[_r - 1]);
        GetText(_r - 1, _c - 1);

    }
    else {

        if (DP[_r - 1][_c] > DP[_r][_c - 1]) {
            GetText(_r - 1, _c);
        }
        else {
            GetText(_r, _c - 1);
        }
    }

}

