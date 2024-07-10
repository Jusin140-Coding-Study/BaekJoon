#include <iostream>
#include <list>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int answer = 0;
    cin >> N >> M;

    list<int> nums = {};

    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        nums.push_back(n);
    }

    auto startIter = nums.begin();
    auto endIter = nums.begin();

    while (nums.end() != startIter) {

        ++endIter;

        if (nums.end() == endIter) {
            ++startIter;
            endIter = startIter;
        }
        else if (M == *startIter + *endIter) {
            answer++;
            ++startIter;
            endIter = startIter;

        }
    }

    cout << answer;

    return 0;
}