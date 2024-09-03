/*
* @title    : 15658�� ������ �����ֱ�(2)(�ǹ�2)
* @content  : ���Ʈ ���� - ���
* @author   : �յ���
* @date     : 240825
* @time     : 0ms
* @memory   : 2020 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vecNums;
int operators[4]; // +, -, *, /
int MaxResult = -1000000001;
int MinResult = 1000000001;

void DFS(int index, int current) {
    if (index == N) {
        MaxResult = max(MaxResult, current);
        MinResult = min(MinResult, current);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (operators[i] > 0) {
            operators[i]--;
            if (i == 0) DFS(index + 1, current + vecNums[index]);
            else if (i == 1) DFS(index + 1, current - vecNums[index]);
            else if (i == 2) DFS(index + 1, current * vecNums[index]);
            else DFS(index + 1, current / vecNums[index]);
            operators[i]++;
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    vecNums.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> vecNums[i];
    }
    
    for (int i = 0; i < 4; ++i) {
        cin >> operators[i];
    }
    
    DFS(1, vecNums[0]);
    
    cout << MaxResult << "\n" << MinResult << "\n";

	return 0;
}
