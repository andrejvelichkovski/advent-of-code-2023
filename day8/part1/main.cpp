#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include <climits>
#include <algorithm>

#define ll long long
using namespace std;

map<string, string> leftDirection, rightDirection;

string cleanKey(string key, int startPosition) {
    return key.substr(startPosition, 3);
}


int main()
{
    string steps;
    cin>>steps;

    string placeKey, leftKey, rightKey;
    string emptystring;
    while(cin>>placeKey>>emptystring>>leftKey>>rightKey) {
        leftKey = cleanKey(leftKey, 1);
        rightKey = cleanKey(rightKey, 0);

        leftDirection[placeKey] = leftKey;
        rightDirection[placeKey] = rightKey;

        // cout<<placeKey<<" "<<emptystring<<" "<<leftKey<<" "<<rightKey<<"\n";
    }

    string currentKey="AAA";
    int index = 0;
    int stepCount = 0;
    while(currentKey != "ZZZ") {
        if(steps[index] == 'L') {
            currentKey = leftDirection[currentKey];
        }
        else {
            currentKey = rightDirection[currentKey];
        }

        stepCount++;
        index = (index + 1 ) % (steps.length());

        // cout<<currentKey<<"\n";
    }

    cout<<stepCount<<"\n";
}