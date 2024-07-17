#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string strInput;
    cin >> strInput;

    int iHead = 0;

    for (int i = 0; i < strInput.length(); ++i)
    {
        int iMaxIdx = max_element(strInput.begin() + iHead, strInput.end()) - strInput.begin();

        char cTemp;
        cTemp = strInput[iHead];
        strInput[iHead] = strInput[iMaxIdx];
        strInput[iMaxIdx] = cTemp;

        cout << strInput[iHead];

        iHead++;
    }
}