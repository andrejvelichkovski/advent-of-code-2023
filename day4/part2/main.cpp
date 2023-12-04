#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> inputValues;
vector<set<int>> winningValues;
vector<int> cardCount;

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

        cardCount.push_back(1);
    }

    long long result = 0LL;
    for (int i = 0; i < inputValues.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < inputValues[i].size(); j++)
        {
            // cout<<inputValues[i][j]<<"\n";
            if (winningValues[i].find(inputValues[i][j]) != winningValues[i].end())
            {
                count++;
            }
        }//cout<<"\n";

        for(int next_i=i+1; next_i<=i+count && next_i<inputValues.size();next_i++) {
            cardCount[next_i] += cardCount[i];
        }

        result += cardCount[i];
    }

    cout<<result<<"\n";
}