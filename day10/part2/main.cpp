#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include <climits>
#include <algorithm>
#include <deque>
#include <queue>

#define ll long long
using namespace std;

vector<string> maze;
vector<vector<bool> > visited;
vector<vector<int> > dist;

vector<string>extendedMaze;

bool checkMove(int i, int j, char direction)
{
    if (direction == 'N')
    {
        // maze[i-1][j]
        return (
            extendedMaze[i][j] == '|' || extendedMaze[i][j] == 'L' || extendedMaze[i][j] == 'J' || extendedMaze[i][j] == 'S') 
            && (extendedMaze[i - 1][j] == '|' || extendedMaze[i - 1][j] == '7' || extendedMaze[i-1][j] == 'F');
        
    }
    else if (direction == 'S')
    {
        // maze[i+1][j]
        // cout<<"entering"<<i<<" "<<j<<"\n";
        return (
            extendedMaze[i][j] == '|' || extendedMaze[i][j] == '7' || extendedMaze[i][j] == 'F' || extendedMaze[i][j] == 'S'
        ) && (extendedMaze[i+1][j] == '|' || extendedMaze[i+1][j] == 'L' || extendedMaze[i+1][j] == 'J');
    }
    else if (direction == 'E')
    {
        return (
            extendedMaze[i][j] == '-' || extendedMaze[i][j] == 'F' || extendedMaze[i][j] == 'L' || extendedMaze[i][j] == 'S'
        ) && (extendedMaze[i][j+1] == '-' || extendedMaze[i][j+1] == 'J' || extendedMaze[i][j+1] == '7');


    }
    else if (direction == 'W')
    {
        // maze[i][j-1]
        return (
            extendedMaze[i][j] == '-' || extendedMaze[i][j] == 'J' || extendedMaze[i][j] == '7' || extendedMaze[i][j] == 'S'
        ) && (extendedMaze[i][j-1] == '-' || extendedMaze[i][j-1] == 'F' || extendedMaze[i][j-1] == 'L');
    }
}

int main()
{
    string currentLine;

    int start_i, start_j;
    int i = 0;

    string firstLine;
    while (getline(cin, currentLine))
    {
        maze.push_back(currentLine);
        string extendedMazeCurrent = ".";

        firstLine = ".";
        for (int j = 0; j < currentLine.length(); j++)
        {
            extendedMazeCurrent += currentLine[j];
            extendedMazeCurrent += ".";

            if (currentLine[j] == 'S')
            {
                start_i = i;
                start_j = j;
            }

            firstLine += "..";
        }
        i++;

        if(extendedMaze.size() == 0) {
            extendedMaze.push_back(firstLine);
            visited.push_back(vector<bool>(extendedMazeCurrent.length()));
            dist.push_back(vector<int>(extendedMazeCurrent.length()));
        }
        extendedMaze.push_back(extendedMazeCurrent);
        extendedMaze.push_back(firstLine);

        visited.push_back(vector<bool>(extendedMazeCurrent.length()));
        visited.push_back(vector<bool>(extendedMazeCurrent.length()));
        dist.push_back(vector<int>(extendedMazeCurrent.length()));
        dist.push_back(vector<int>(extendedMazeCurrent.length()));
    }

    // extendedMaze.push_back(firstLine);

    for(int i=1;i<extendedMaze.size();i+=2) {
        for(int j=2;j<extendedMaze[i].length();j+=2) {
            if(extendedMaze[i][j-1] == '-' && extendedMaze[i][j+1] == '-') {
                extendedMaze[i][j] = '-';
            }
            if(extendedMaze[i][j-1] == '-' && extendedMaze[i][j+1] == 'J') {
                extendedMaze[i][j] = '-';
            }
            if(extendedMaze[i][j-1] == '-' && extendedMaze[i][j+1] == '7') {
                extendedMaze[i][j] = '-';
            }
            if(extendedMaze[i][j-1] == '-' && extendedMaze[i][j+1] == 'S') {
                extendedMaze[i][j] = '-';
            }

            if(extendedMaze[i][j-1] == 'L' && extendedMaze[i][j+1] == '-') {
                extendedMaze[i][j] = '-';
            }
            if(extendedMaze[i][j-1] == 'L' && extendedMaze[i][j+1] == 'J') {
                extendedMaze[i][j] = '-';
            }
            if(extendedMaze[i][j-1] == 'L' && extendedMaze[i][j+1] == '7') {
                extendedMaze[i][j] = '-';
            }
            if(extendedMaze[i][j-1] == 'L' && extendedMaze[i][j+1] == 'S') {
                extendedMaze[i][j] = '-';
            }

            if(extendedMaze[i][j-1] == 'F' && extendedMaze[i][j+1] == '-') {
                extendedMaze[i][j] = '-';
            }
            if(extendedMaze[i][j-1] == 'F' && extendedMaze[i][j+1] == 'J') {
                extendedMaze[i][j] = '-';
            }
            if(extendedMaze[i][j-1] == 'F' && extendedMaze[i][j+1] == '7') {
                extendedMaze[i][j] = '-';
            }
            if(extendedMaze[i][j-1] == 'F' && extendedMaze[i][j+1] == 'S') {
                extendedMaze[i][j] = '-';
            }

            if(extendedMaze[i][j-1] == 'S' && extendedMaze[i][j+1] == '-') {
                extendedMaze[i][j] = '-';
            }
            if(extendedMaze[i][j-1] == 'S' && extendedMaze[i][j+1] == 'J') {
                extendedMaze[i][j] = '-';
            }
            if(extendedMaze[i][j-1] == 'S' && extendedMaze[i][j+1] == '7') {
                extendedMaze[i][j] = '-';
            }
        }
    }

    for(int i=2;i+1<extendedMaze.size();i+=2) {
        for(int j=1;j<extendedMaze[i].length();j+=2) {
            if(extendedMaze[i-1][j] == '|' && extendedMaze[i+1][j] == '|') {
                extendedMaze[i][j] = '|';
            }
            if(extendedMaze[i-1][j] == '|' && extendedMaze[i+1][j] == 'J') {
                extendedMaze[i][j] = '|';
            }
            if(extendedMaze[i-1][j] == '|' && extendedMaze[i+1][j] == 'L') {
                extendedMaze[i][j] = '|';
            }
            if(extendedMaze[i-1][j] == '|' && extendedMaze[i+1][j] == 'S') {
                extendedMaze[i][j] = '|';
            }

            if(extendedMaze[i-1][j] == 'F' && extendedMaze[i+1][j] == '|') {
                extendedMaze[i][j] = '|';
            }
            if(extendedMaze[i-1][j] == 'F' && extendedMaze[i+1][j] == 'J') {
                extendedMaze[i][j] = '|';
            }
            if(extendedMaze[i-1][j] == 'F' && extendedMaze[i+1][j] == 'L') {
                extendedMaze[i][j] = '|';
            }
            if(extendedMaze[i-1][j] == 'F' && extendedMaze[i+1][j] == 'S') {
                extendedMaze[i][j] = '|';
            }

            if(extendedMaze[i-1][j] == '7' && extendedMaze[i+1][j] == '|') {
                extendedMaze[i][j] = '|';
            }
            if(extendedMaze[i-1][j] == '7' && extendedMaze[i+1][j] == 'J') {
                extendedMaze[i][j] = '|';
            }
            if(extendedMaze[i-1][j] == '7' && extendedMaze[i+1][j] == 'L') {
                extendedMaze[i][j] = '|';
            }
            if(extendedMaze[i-1][j] == '7' && extendedMaze[i+1][j] == 'S') {
                extendedMaze[i][j] = '|';
            }

            if(extendedMaze[i-1][j] == 'S' && extendedMaze[i+1][j] == '|') {
                extendedMaze[i][j] = '|';
            }
            if(extendedMaze[i-1][j] == 'S' && extendedMaze[i+1][j] == 'J') {
                extendedMaze[i][j] = '|';
            }
            if(extendedMaze[i-1][j] == 'S' && extendedMaze[i+1][j] == 'L') {
                extendedMaze[i][j] = '|';
            }
        }
    }

    // for(int i=0;i<extendedMaze.size();i++) {
    //     for(int j=0;j<extendedMaze[i].length();j++) {
    //         cout<<extendedMaze[i][j];
    //     } cout<<"\n";
    // }

    queue<pair<int, int> > q;
    q.push(make_pair(start_i * 2 + 1, start_j * 2 + 1));
    visited[start_i*2+1][start_j*2+1] = true;

    cout<<start_i*2+1<<" "<<start_j*2+1<<"\n";

    int maxDist = 0;

    while(!q.empty()) {
        int curr_i = q.front().first;
        int curr_j = q.front().second;

        maxDist = max(maxDist, dist[curr_i][curr_j]);

        q.pop();

        // if(visited[curr_i][curr_j]) continue;

        //north N curr_i-1 

        if(curr_i - 1 >= 0 && !visited[curr_i-1][curr_j] && checkMove(curr_i, curr_j, 'N')) {
            dist[curr_i - 1][curr_j] = dist[curr_i][curr_j] + 1;
            visited[curr_i - 1][curr_j] = true;
            q.push(make_pair(curr_i-1, curr_j));
        }
        if(curr_i + 1 < extendedMaze.size() && !visited[curr_i+1][curr_j] && checkMove(curr_i, curr_j, 'S')) {
            dist[curr_i + 1][curr_j] = dist[curr_i][curr_j] + 1;
            visited[curr_i + 1][curr_j] = true;
            q.push(make_pair(curr_i + 1, curr_j));
        }
        if(curr_j - 1 >= 0 && !visited[curr_i][curr_j-1] && checkMove(curr_i, curr_j, 'W')) {
            dist[curr_i][curr_j-1] = dist[curr_i][curr_j] + 1;
            visited[curr_i][curr_j-1] = true;
            q.push(make_pair(curr_i, curr_j-1));
        }
        if(curr_j + 1 < extendedMaze[0].length() && !visited[curr_i][curr_j+1] && checkMove(curr_i, curr_j, 'E')) {
            dist[curr_i][curr_j+1] = dist[curr_i][curr_j] + 1;
            visited[curr_i][curr_j+1] = true;
            q.push(make_pair(curr_i, curr_j+1));
        }
    }

    for(int i=0;i<extendedMaze.size();i++) {
        for(int j=0;j<extendedMaze[i].size();j++) {
            if(i!=0 && j!=0 && i!=extendedMaze.size()-1 && j != extendedMaze[i].size()-1) {
                continue;
            }

            q.push(make_pair(i, j));
            while(!q.empty()) {
                int curr_i = q.front().first;
                int curr_j = q.front().second;

                visited[curr_i][curr_j] = true;

                q.pop();

                // if(visited[curr_i][curr_j]) continue;

                //north N curr_i-1 

                if(curr_i - 1 >= 0 && !visited[curr_i-1][curr_j]) {
                    dist[curr_i - 1][curr_j] = dist[curr_i][curr_j] + 1;
                    visited[curr_i - 1][curr_j] = true;
                    q.push(make_pair(curr_i-1, curr_j));
                }
                if(curr_i + 1 < extendedMaze.size() && !visited[curr_i+1][curr_j]) {
                    dist[curr_i + 1][curr_j] = dist[curr_i][curr_j] + 1;
                    visited[curr_i + 1][curr_j] = true;
                    q.push(make_pair(curr_i + 1, curr_j));
                }
                if(curr_j - 1 >= 0 && !visited[curr_i][curr_j-1]) {
                    dist[curr_i][curr_j-1] = dist[curr_i][curr_j] + 1;
                    visited[curr_i][curr_j-1] = true;
                    q.push(make_pair(curr_i, curr_j-1));
                }
                if(curr_j + 1 < extendedMaze[0].length() && !visited[curr_i][curr_j+1]) {
                    dist[curr_i][curr_j+1] = dist[curr_i][curr_j] + 1;
                    visited[curr_i][curr_j+1] = true;
                    q.push(make_pair(curr_i, curr_j+1));
                }
            }
        }
    }
    int cnt = 0;
    for(int i=1;i<visited.size();i+=2) {
        for(int j=1;j<visited[i].size();j+=2) {
            // cout<<visited[i][j];

            if(!visited[i][j]) {
                cout<<(i-1)/2<<" "<<(j-1)/2<<"\n";
                cnt++;
            }
        } //cout<<"\n";
    }

    

    cout<<cnt;

    // cout<<maxDist<<"\n";
}