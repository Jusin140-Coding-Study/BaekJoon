#include <iostream>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int start = 1;
    int end = 1;
    int count = 0;
    int answer = 1;

    while (N != start) {

        count += end;

        if (N == count) {
            ++answer;
            count = 0;
            ++start;
            end = start;

        }else if (count > N) {
            count = 0;
            ++start;
            end = start;
        }
        else {
            ++end;
        }

    }

    cout << answer << "\n";

    return 0;


}