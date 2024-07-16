/*
* @title    : 1715�� ī�� �����ϱ�(���4)
* @content  : �׸���
* @author   : �յ���
* @date     : 240715
* @time     : 44 ms
* @memory   : 6776 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	multiset<int> sNums;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int iNum;
		cin >> iNum;
		sNums.insert(iNum);
	}
	int iTotal = 0;
	while (1 < sNums.size())
	{
		auto iter = sNums.begin();
		int ifirst = *iter;
		int isecond = *(++iter);
		int iSum = ifirst + isecond;

		iTotal += iSum;
		sNums.erase(sNums.find(ifirst));
		sNums.erase(sNums.find(isecond));
		sNums.insert(iSum);
	}

	cout << iTotal;

	return 0;
}
