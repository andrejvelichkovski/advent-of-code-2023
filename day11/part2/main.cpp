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
map<int, bool> colCnt;
map<int, bool> rowCnt;
vector<pair<int,int> > coordinates;
int main() {
    string currentLine;
    int ind = 1;
    while(getline(cin, currentLine)) {
        int cnt = 0;
        for(int i=1;i<=currentLine.length();i++) {
            if(currentLine[i-1] == '#') {
                // cout<<i<<" "<<currentLine<<"\n";
                cnt++;
                colCnt[i] = true;
                rowCnt[ind] = true;

                coordinates.push_back(make_pair(ind, i));
            }
        }

        maze.push_back(currentLine);
        ind++;
    }

    vector<int> prefixCntRow = {0};
    vector<int> prefixCntCol = {0};

    for(int i=1;i<=maze.size();i++) {
        prefixCntRow.push_back(prefixCntRow.back() + (1-rowCnt[i]));
    }
    for(int i=1;i<=maze[0].length();i++) {
        prefixCntCol.push_back(prefixCntCol.back() + (1-colCnt[i]));
    }

    ll result = 0LL;
    for(int i=0;i<coordinates.size();i++) {
        cout<<"first"<<coordinates[i].first<<" "<<coordinates[i].second<<"\n";
        for(int j=i+1;j<coordinates.size();j++) {
            cout<<"second"<<" "<<coordinates[j].first<<" "<<coordinates[j].second<<"\n";
            ll diffRow = abs(coordinates[i].first - coordinates[j].first);
            ll prefixDiffRow = (prefixCntRow[
                max(coordinates[i].first, coordinates[j].first)
            ] - prefixCntRow[
                min(coordinates[i].first, coordinates[j].first)
            ]) * (1000000-1);

            cout<<diffRow<<" "<<prefixDiffRow<<"\n";


            int diffCol = abs(coordinates[i].second - coordinates[j].second);
            diffCol += (prefixCntCol[
                max(coordinates[i].second, coordinates[j].second)
            ] - prefixCntCol[
                min(coordinates[i].second, coordinates[j].second) - 1
            ]) * (1000000-1);

            // cout<<diffCol<<" "<<

            result += (diffRow + prefixDiffRow + diffCol);
        }
    } 
    cout<<result<<"\n";
}  