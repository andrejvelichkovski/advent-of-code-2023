#include <iostream>
#include <vector>
using namespace std;

vector<string> maze;
vector<vector<int> > gearCount;
vector<vector<int> > gearProduct;

bool isSpecialSymbol(char currentCharacter)
{
    return !isdigit(currentCharacter) && currentCharacter != '.';
}

int main()
{
    string currentLine;
    while (getline(cin, currentLine))
    {
        maze.push_back(currentLine);

        gearCount.push_back(vector<int>(currentLine.length(), 0));
        gearProduct.push_back(vector<int>(currentLine.length(), 1));
    }

    int result = 0;

    for (int i = 0; i < maze.size(); i++)
    {
        bool isPreviousCharDigit = false;
        vector<char> currentNumber;
        for (int j = 0; j < maze[i].length(); j++)
        {
            isPreviousCharDigit = false;
            if (j > 0 && isdigit(maze[i][j - 1]))
                isPreviousCharDigit = true;

            if (isdigit(maze[i][j]))
            {
                currentNumber.push_back(maze[i][j]);
            }
            else if (isPreviousCharDigit)
            {
                bool isNumberTouchingSymbol = false;

                int value = 0;
                for (char digit : currentNumber)
                {
                    value *= 10;
                    value += (digit - '0');
                }

                for (int start_i = i - 1; start_i <= i + 1; start_i++)
                {
                    for (int start_j = j - currentNumber.size() - 1; start_j <= j; start_j++)
                    {
                        if (start_i >= 0 && start_i < maze.size() && start_j >= 0 && start_j < maze[i].length())
                        {
                            if(maze[start_i][start_j] == '*') {
                                // cout<<"Updating"<<" "<<start_i<<" "<<start_j<<" from "<<i<<" "<<j<<"\n";
                                gearCount[start_i][start_j] += 1;
                                gearProduct[start_i][start_j] *= value;
                            }
                        }
                    }
                }

                currentNumber.clear();
            }
        }

        if (isPreviousCharDigit)
        {
            bool isNumberTouchingSymbol = false;

            int value = 0;
            for (char digit : currentNumber)
            {
                value *= 10;
                value += (digit - '0');
            }

            for (int start_i = i - 1; start_i <= i + 1; start_i++)
            {
                for (int start_j = maze[i].length() - currentNumber.size() - 1; start_j <= maze[i].length(); start_j++)
                {
                    if (start_i >= 0 && start_i < maze.size() && start_j >= 0 && start_j < maze[i].length())
                    {
                        if(maze[start_i][start_j] == '*') {
                            gearCount[start_i][start_j] += 1;
                            gearProduct[start_i][start_j] *= value;
                        }
                    }
                }
            }

            currentNumber.clear();
        }
    }

    for(int i=0;i<maze.size();i++) {
        for(int j=0;j<maze[i].length();j++) {
            if(maze[i][j] == '*' and gearCount[i][j] == 2) {
                // cout<<i<<" "<<j<<"\n";
                result += gearProduct[i][j];
            } 
        }
    }

    cout<<result;
}