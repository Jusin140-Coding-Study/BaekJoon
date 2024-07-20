/*
* @title    : 10773번 제로(실버4)
* @content  : 스택, 큐, 덱
* @author   : 손동찬
* @date     : 240717
* @time     : 8 ms
* @memory   : 2548 KB
* @state    : 완료
*/
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	stack<int> stNums;
	for (int i = 0; i < N; ++i)
	{
		int iNum;
		cin >> iNum;
		if (iNum)
			stNums.push(iNum);
		else
			stNums.pop();
	}
	int iResult = 0;

	while (!stNums.empty())
	{
		iResult += stNums.top();
		stNums.pop();
	}

	cout << iResult;

	return 0;
}
