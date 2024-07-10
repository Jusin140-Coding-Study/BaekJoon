#include <iostream>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> cards;

    for (int i = 1; i <= N; ++i) {
        cards.push(i);
    }

    bool isDiscard = true;

    while (1 != cards.size()) {

        if (isDiscard) {
            cards.pop();

        }
        else {
            int num = cards.front();
            cards.pop();
            cards.push(num);
        }

        isDiscard = !isDiscard;
    }


    cout << cards.front();


    return 0;
}