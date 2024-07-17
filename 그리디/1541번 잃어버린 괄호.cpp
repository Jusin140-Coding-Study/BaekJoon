#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string strInput;
    cin >> strInput;

    int iSum = 0;
    int iPrevNumIdx = 0;
    bool isPrevMinus = false;

    for (int i = 1; i < strInput.length(); ++i)
    {
        if (strInput[i] == '-')
        {
            if (isPrevMinus)
            {
                iSum -= stoi(strInput.substr(iPrevNumIdx, i));
            }
            else
            {
                iSum += stoi(strInput.substr(iPrevNumIdx, i));
            }

            isPrevMinus = true;
            iPrevNumIdx = -1;
        }

        else if (strInput[i] == '+')
        {
            if (isPrevMinus)
            {
                iSum -= stoi(strInput.substr(iPrevNumIdx, i));
            }

            else
            {
                iSum += stoi(strInput.substr(iPrevNumIdx, i));
            }
            iPrevNumIdx = -1;
        }

        else
        {
            if (iPrevNumIdx == -1)
                iPrevNumIdx = i;
        }
    }

    if (isPrevMinus)
        iSum -= stoi(strInput.substr(iPrevNumIdx, strInput.length()));
    else
        iSum += stoi(strInput.substr(iPrevNumIdx, strInput.length()));

    cout << iSum;
}