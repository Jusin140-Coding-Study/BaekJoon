#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<char> sign;
vector<string> answer;
int N;

void DFS(vector<bool> _visited, int _prevNum, string _s);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    sign.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> sign[i];
    }

    vector<bool> visit(10);

    for (int i = 0; i <= 9; ++i) {
        string s = "";
        DFS(visit, i, s);
    }

    sort(answer.begin(), answer.end());

    cout << answer.back() << "\n";
    cout << answer.front();

    return 0;
}


void DFS(vector<bool> _visited, int _prevNum, string _s) {


    _visited[_prevNum] = true;
    _s += to_string(_prevNum);

    if (_s.size() == N + 1) {

        answer.push_back(_s);
        return;
    }

    for (int i = 0; i <= 9; i++) {

        if (!_visited[i]) {

            if (sign[_s.size() - 1] == '>') {
                if (_s.back() - '0' < i) {
                    continue;
                }

            }
            else if (sign[_s.size() - 1] == '<') {
                if (_s.back() - '0' > i) {
                    continue;
                }
            }

            DFS(_visited, i, _s);
        }
    }
}


