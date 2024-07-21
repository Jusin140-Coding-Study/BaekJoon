/*
* @title    : 10814�� ���̼� ����(�ǹ�5)
* @content  : ����
* @author   : �յ���
* @date     : 240714
* @time     : 40 ms
* @memory   : 6716 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
	int iAge;
	string strName;
	int iNum;
};

bool compare(const Data& a , const Data& b)
{
	if(a.iAge == b.iAge)
		return  a.iNum < b.iNum;

	return a.iAge < b.iAge;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<Data> vecDatas(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecDatas[i].iAge >> vecDatas[i].strName;
		vecDatas[i].iNum = i;
	}

	sort(vecDatas.begin(), vecDatas.end(), compare);
	
	for (Data& iter : vecDatas)
		cout << iter.iAge << " " << iter.strName << "\n";
	
	return 0;
}