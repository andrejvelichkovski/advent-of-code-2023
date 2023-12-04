#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> inputValues;
vector<set<int>> winningValues;

int str_to_int(string a)
{
    int value = 0;
    for (int i = 0; i < a.length(); i++)
    {
        value *= 10;
        value += (a[i] - '0');
    }
    return value;
}

int main()
{
    string currentLine;
    while (getline(cin, currentLine))
    {
        stringstream parser(currentLine);

        string cardText, lineNum;
        parser >> cardText >> lineNum;

        inputValues.push_back(vector<int>());
        winningValues.push_back(set<int>());
        string numValue;
        while (parser >> numValue && numValue != "|")
        {
            inputValues.back().push_back(str_to_int(numValue));
        }

        while (parser >> numValue)
        {
            winningValues.back().insert(str_to_int(numValue));
        } 
    }

    long long result = 0LL;
    for (int i = 0; i < inputValues.size(); i++)
    {
        long long value = 0LL;

        for (int j = 0; j < inputValues[i].size(); j++)
        {
            // cout<<inputValues[i][j]<<"\n";
            if (winningValues[i].find(inputValues[i][j]) != winningValues[i].end())
            {
                if(value == 0) value = 1LL;
                else value = value << 1LL;
            }
        }//cout<<"\n";

        result += value;
    }

    cout<<result<<"\n";
}