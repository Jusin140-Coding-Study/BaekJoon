#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iN;
    cin >> iN;

    vector<pair<int, int>> vecNum(iN);

    for (int i = 0; i < iN; ++i)
    {
        vecNum[i].second = i;
        cin >> vecNum[i].first;
    }

    sort(vecNum.begin(), vecNum.end());

    int iMaxIdxDiff = 0;

    for (int i = 0; i < iN; ++i)
    {
        if (vecNum[i].second - i > iMaxIdxDiff)
        {
            iMaxIdxDiff = vecNum[i].second - i;
        }
    }

    cout << iMaxIdxDiff + 1 << '\n';
}