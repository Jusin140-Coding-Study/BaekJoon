#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int totalNum = 0;
    int maxScore = 0;
    float newAvg = 0;

    cin >> totalNum;

    vector<int> scores(totalNum);

    for (int num = 0; num < totalNum; ++num) {

        int score = 0;
        cin >> score;

        scores[num] = score;
    }

    maxScore = *max_element(scores.begin(), scores.end());

    for (int count = 0; count < totalNum; ++count) {

        newAvg += ((float)scores[count] / maxScore * 100);

    }

    cout << newAvg / (float)totalNum;

    return 0;
}