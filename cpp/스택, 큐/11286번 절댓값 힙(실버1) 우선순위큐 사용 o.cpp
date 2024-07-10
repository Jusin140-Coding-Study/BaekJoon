/*
* @title    : 11286번 절댓값 힙(실버1) 우선순위큐 사용 o
* @content  : 스택, 큐
* @author   : 손동찬
* @date     : 240710
* @time     : 12 ms
* @memory   : 2532 KB
* @state    : 완료
*/
#include <iostream>
#include <queue>

using namespace std;

//struct compare
//{
//	bool operator()(int A, int B)
//	{
//		int absA = abs(A);
//		int absB = abs(B);
//
//		if (absA == absB)
//			return A > B;
//
//		else
//			return absA > absB;
//	}
//};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	auto compare = [](int A, int B) 
	{
			int absA = abs(A);
			int absB = abs(B);
			
			if (absA == absB)
				return A > B;
			
			else
				return absA > absB;
	};

	//priority_queue<int, vector<int>, compare> MyQueue; 
	priority_queue<int, vector<int>, decltype(compare)> MyQueue(compare);

	for (int i = 0; i < N; ++i)
	{
		int iNum;
		cin >> iNum;

		if (iNum == 0)
		{
			if (MyQueue.empty())
			{
				cout << "0" << "\n";
				continue;
			}
			cout << MyQueue.top() << "\n";
			MyQueue.pop();
		}
		else
			MyQueue.push(iNum);

	}


	return 0;
}