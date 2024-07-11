#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<int> V(4, 0);
unordered_map<char, int> umapCheck;
bool Checked();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Result(0);
	int N(0); int P(0);
	string DNA = "";

	cin >> N >> P;
	cin >> DNA;
	
	for (int i = 0; i < 4; ++i)
		cin >> V[i];

	umapCheck.emplace('A', 0);
	umapCheck.emplace('C', 0);
	umapCheck.emplace('G', 0);
	umapCheck.emplace('T', 0);

	// 초기 부분 문자열
	for (int i = 0; i < P; ++i)
		umapCheck[DNA[i]]++;

	if (Checked())
		Result++;

	for (int i = P; i < N; ++i)
	{
		umapCheck[DNA[i]]++;
		umapCheck[DNA[i - P]]--;

		if (Checked())
			Result++;
	}

	cout << Result;
}

bool Checked()
{
	if (umapCheck['A'] >= V[0] && umapCheck['C'] >= V[1] && umapCheck['G'] >= V[2] && umapCheck['T'] >= V[3])
		return true;
	return false;
}