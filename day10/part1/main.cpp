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

bool checkMove(int i, int j, char direction)
{
    if (direction == 'N')
    {
        // maze[i-1][j]
        return (
            maze[i][j] == '|' || maze[i][j] == 'L' || maze[i][j] == 'J' || maze[i][j] == 'S') 
            && (maze[i - 1][j] == '|' || maze[i - 1][j] == '7' || maze[i-1][j] == 'F');
        
    }
    else if (direction == 'S')
    {
        // maze[i+1][j]
        // cout<<"entering"<<i<<" "<<j<<"\n";
        return (
            maze[i][j] == '|' || maze[i][j] == '7' || maze[i][j] == 'F' || maze[i][j] == 'S'
        ) && (maze[i+1][j] == '|' || maze[i+1][j] == 'L' || maze[i+1][j] == 'J');
    }
    else if (direction == 'E')
    {
        return (
            maze[i][j] == '-' || maze[i][j] == 'F' || maze[i][j] == 'L' || maze[i][j] == 'S'
        ) && (maze[i][j+1] == '-' || maze[i][j+1] == 'J' || maze[i][j+1] == '7');


    }
    else if (direction == 'W')
    {
        // maze[i][j-1]
        return (
            maze[i][j] == '-' || maze[i][j] == 'J' || maze[i][j] == '7' || maze[i][j] == 'S'
        ) && (maze[i][j-1] == '-' || maze[i][j-1] == 'F' || maze[i][j-1] == 'L');
    }
}

int main()
{
    string currentLine;

    int start_i, start_j;
    int i = 0;
    while (getline(cin, currentLine))
    {
        maze.push_back(currentLine);
        for (int j = 0; j < currentLine.length(); j++)
        {
            if (currentLine[j] == 'S')
            {
                start_i = i;
                start_j = j;
            }
        }
        i++;

        visited.push_back(vector<bool>(currentLine.length()));
        dist.push_back(vector<int>(currentLine.length()));
    }

    queue<pair<int, int> > q;
    q.push(make_pair(start_i, start_j));

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
        if(curr_i + 1 < maze.size() && !visited[curr_i+1][curr_j] && checkMove(curr_i, curr_j, 'S')) {
            dist[curr_i + 1][curr_j] = dist[curr_i][curr_j] + 1;
            visited[curr_i + 1][curr_j] = true;
            q.push(make_pair(curr_i + 1, curr_j));
        }
        if(curr_j - 1 >= 0 && !visited[curr_i][curr_j-1] && checkMove(curr_i, curr_j, 'W')) {
            dist[curr_i][curr_j-1] = dist[curr_i][curr_j] + 1;
            visited[curr_i][curr_j-1] = true;
            q.push(make_pair(curr_i, curr_j-1));
        }
        if(curr_j + 1 >= 0 && !visited[curr_i][curr_j+1] && checkMove(curr_i, curr_j, 'E')) {
            dist[curr_i][curr_j+1] = dist[curr_i][curr_j] + 1;
            visited[curr_i][curr_j+1] = true;
            q.push(make_pair(curr_i, curr_j+1));
        }
    }

    // for(int i=0;i<dist.size();i++) {
    //     for(int j=0;j<dist[i].size();j++) {
    //         cout<<dist[i][j];
    //     } cout<<"\n";
    // }

    cout<<maxDist<<"\n";
}