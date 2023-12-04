#include <iostream>
#include <vector>
using namespace std;

vector<string> maze;

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
    }

    int result = 0;

    for (int i = 0; i < maze.size(); i++)
    {
        bool isPreviousCharDigit = false;
        vector<char> currentNumber;
        for (int j = 0; j < maze[i].length(); j++)
        {
            if (j > 0 && isdigit(maze[i][j - 1]))
                isPreviousCharDigit = true;

            if (isdigit(maze[i][j]))
            {
                currentNumber.push_back(maze[i][j]);
            }
            else if (isPreviousCharDigit)
            {
                bool isNumberTouchingSymbol = false;

                for (int start_i = i - 1; start_i <= i + 1; start_i++)
                {
                    for (int start_j = j - currentNumber.size() - 1; start_j <= j; start_j++)
                    {
                        if (start_i >= 0 && start_i < maze.size() && start_j >= 0 && start_j < maze[i].length())
                        {
                            isNumberTouchingSymbol |= isSpecialSymbol(maze[start_i][start_j]);
                        }
                    }
                }

                int value = 0;
                for (char digit : currentNumber)
                {
                    value *= 10;
                    value += (digit - '0');
                }

                if(isNumberTouchingSymbol)
                    result += value;

                currentNumber.clear();
            }
        }

        if (isPreviousCharDigit)
        {
            bool isNumberTouchingSymbol = false;

            for (int start_i = i - 1; start_i <= i + 1; start_i++)
            {
                for (int start_j = maze[i].length() - currentNumber.size() - 1; start_j <= maze[i].length(); start_j++)
                {
                    if (start_i >= 0 && start_i < maze.size() && start_j >= 0 && start_j < maze[i].length())
                    {
                        isNumberTouchingSymbol |= isSpecialSymbol(maze[start_i][start_j]);
                    }
                }
            }

            int value = 0;
            for (char digit : currentNumber)
            {
                value *= 10;
                value += (digit - '0');
            }

            if(isNumberTouchingSymbol)
                result += value;

            currentNumber.clear();
        }
    }

    cout<<result;
}