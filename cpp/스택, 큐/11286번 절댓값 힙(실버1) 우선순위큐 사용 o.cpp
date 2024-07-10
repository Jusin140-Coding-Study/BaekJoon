/*
* @title    : 11286�� ���� ��(�ǹ�1) �켱����ť ��� o
* @content  : ����, ť
* @author   : �յ���
* @date     : 240710
* @time     : 12 ms
* @memory   : 2532 KB
* @state    : �Ϸ�
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