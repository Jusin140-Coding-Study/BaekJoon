#include <iostream>
#include <vector>

using namespace std;

string firstWord;
string secondWord;

vector<vector<int>> DP;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> firstWord >> secondWord;

    DP.resize(firstWord.size() + 1, vector<int>(secondWord.size() + 1));

    for (int i = 1; i <= firstWord.size(); ++i) {
        for (int j = 1; j <= secondWord.size(); ++j) {
            if (firstWord[i - 1] == secondWord[j - 1]) {
                DP[i][j] = max(DP[i][j], DP[i - 1][j - 1] + 1);
            }
            else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    cout << DP[firstWord.size()][secondWord.size()];

    return 0;
}

