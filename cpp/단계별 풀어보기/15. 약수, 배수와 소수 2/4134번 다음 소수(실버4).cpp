/*
* @title    : 4134�� ���� �Ҽ�(�ǹ�4)
* @content  : ���, ����� �Ҽ� 2
* @author   : �յ���
* @date     : 240717
* @time     : 48 ms
* @memory   : 2032 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned int uint;

bool isPrime(uint num) {
	if (num == 2)
		return true;

	if (num <= 1 || num % 2 == 0)
		return false;

	for (uint i = 3; i <= sqrt(num); i += 2) 
		if (!(num % i)) 
			return false;
	
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	uint N;
	cin >> N;
	for (uint i = 0; i < N; ++i)
	{
		uint iNum;
		cin >> iNum;		
		while (!isPrime(iNum))
			iNum++;
		
		cout << iNum << "\n";
	}
	
	return 0;
}
