#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    vector<int> v;
    vector<int> origin;

    string currentNumber = "";

    int number = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            currentNumber += s[i];
        }
        else {
            if ('-' == s[i]) {
                origin.push_back(stoi(currentNumber));
                currentNumber = "-";
            }
            else {
                origin.push_back(stoi(currentNumber));
                currentNumber = "";
            }
        }
    }

    origin.push_back(stoi(currentNumber));

    bool isMinus = false;
    int answer = 0;

    for (int i = 0; i < origin.size(); ++i) {

        if (origin[i] < 0) {

            answer += origin[i];
            isMinus = true;
        }
        else {
            if (isMinus) {
                answer += origin[i] * -1;

            }
            else {
                answer += origin[i];
            }
        }

    }



    cout << answer;



    return 0;
}
