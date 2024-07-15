/*
* @title    : 1269�� ��Ī ������(�ǹ�4)
* @content  : ���հ� ��
* @author   : �յ���
* @date     : 240715
* @time     : 128 ms
* @memory   : 11536 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;
	unordered_set<int> usNums;
	for (int i = 0; i < A; ++i)
	{
		int iNum;
		cin >> iNum;
		usNums.insert(iNum);
	}

	int iCount = 0;
	for (int i = 0; i < B; ++i)
	{
		int iNum;
		cin >> iNum;
		if (usNums.find(iNum) == usNums.end())
		{
			iCount++;
			continue;
		}
		usNums.erase(iNum);
	}

	cout << usNums.size() + iCount;
	
	return 0;
}
