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

vector<string> tmpMaze, maze;
map<int, int> colCnt;
int main() {
    string currentLine;
    while(getline(cin, currentLine)) {
        int cnt = 0;
        for(int i=0;i<currentLine.length();i++) {
            if(currentLine[i] == '#') {
                cnt++;
                colCnt[i]++;
            }
        }

        tmpMaze.push_back(currentLine);
        if(cnt == 0) {
            tmpMaze.push_back(currentLine);
        }
    }

    vector<pair<int,int> > coordinates;
    for(int i=0;i<tmpMaze.size();i++) {
        currentLine = "";
        for(int j=0;j<tmpMaze[0].length();j++) {
            currentLine += tmpMaze[i][j];
            if(colCnt[j] == 0) {
                currentLine += ".";
            }

            if(tmpMaze[i][j] == '#') {
                // cout<<i<<" "<<currentLine<<"\n";
                coordinates.push_back(make_pair(i, currentLine.length() - 1));
            }
        }
        maze.push_back(currentLine);
    }

    ll result = 0LL;
    for(int i=0;i<coordinates.size();i++) {
        // cout<<"First coordinate"<<coordinates[i].first<<" "<<coordinates[i].second<<"\n";
        for(int j=i+1;j<coordinates.size();j++) {
            // cout<<"second"<<coordinates[j].first<<" "<<coordinates[j].second<<" "<<(
            //  abs(coordinates[i].first - coordinates[j].first) + abs(coordinates[i].second - coordinates[j].second) + 1
            // )<<"\n";
            result += (
                abs(coordinates[i].first - coordinates[j].first) + abs(coordinates[i].second - coordinates[j].second)
            );
        }
    }
    cout<<result<<"\n";
}