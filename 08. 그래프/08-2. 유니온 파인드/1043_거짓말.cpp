#include <iostream>
#include <vector>

using namespace std;

vector<int> truePerson;
vector<int> person;

vector<int> v;

vector<vector<int>> party;

void Union(int first, int second);
int Find(int origin);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, num;
    cin >> N >> M >> num;

    int answer = 0;

    truePerson.resize(num);

    for (int i = 0; i < num; ++i) {
        int p;
        cin >> p;
        truePerson[i] = p;
    }

    party.resize(M);

    for (int j = 0; j < M; ++j) {

        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {

            int participants;
            cin >> participants;

            party[j].push_back(participants);

        }
    }

    v.resize(N + 1);

    for (int i = 0; i < N + 1; ++i) {
        v[i] = i;
    }

    for (int j = 0; j < M; ++j) {

        int firstNumber = party[j][0];

        for (int i = 1; i < party[j].size(); ++i) {
     
            Union(firstNumber, party[j][i]);
        }
    }

    for (int i = 0; i < M; ++i) {

        int firstNum = party[i][0];
        bool isOkay = true;

        for (int j = 0; j < truePerson.size(); ++j) {

            if (Find(firstNum) == Find(truePerson[j])) {
                isOkay = false;
                break;
            }

        }
        if (isOkay) {
            ++answer;
        }

    }

    cout << answer;

    return 0;
}


void Union(int first, int second){

    first = Find(first);
    second = Find(second);
    
    v[first] = second;
}

int Find(int origin) {

    if (origin == v[origin])
        return origin;

    return Find(v[origin]);

}