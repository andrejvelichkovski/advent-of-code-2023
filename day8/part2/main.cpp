#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include <climits>
#include <algorithm>
#include <unistd.h>

#define ll long long
using namespace std;

map<string, string> leftDirection, rightDirection;

map<string, int> firstReach[6];

string cleanKey(string key, int startPosition) {
    return key.substr(startPosition, 3);
}

bool checkFinish(vector<string> keys) {
    for(int i=0;i<keys.size();i++) {
        if(keys[i][keys[i].length() - 1] != 'Z')
            return false;
    }
    return true;
}

int main()
{
    string steps;
    cin>>steps;

    string placeKey, leftKey, rightKey;
    string emptystring;

    vector<string> currentKeys;
    while(cin>>placeKey>>emptystring>>leftKey>>rightKey) {
        leftKey = cleanKey(leftKey, 1);
        rightKey = cleanKey(rightKey, 0);

        leftDirection[placeKey] = leftKey;
        rightDirection[placeKey] = rightKey;

        if(placeKey[placeKey.length() - 1] == 'A') {
            currentKeys.push_back(placeKey);

            cout<<placeKey<<"\n";
        }

        // cout<<placeKey<<" "<<emptystring<<" "<<leftKey<<" "<<rightKey<<"\n";
    }

    int index = 0;
    int stepCount = 0;
    while(!checkFinish(currentKeys)) {
        for(int i=0;i<currentKeys.size();i++){
            if(currentKeys[i][currentKeys[i].length() - 1] == 'Z' && firstReach[i][currentKeys[i]] == 0) {
                firstReach[i][currentKeys[i]] = stepCount;

                cout<<currentKeys[i]<<" "<<i<<" "<<stepCount<<"\n";
            }

            if(steps[index] == 'L') {
                currentKeys[i] = leftDirection[currentKeys[i]];
            }
            else {
                currentKeys[i] = rightDirection[currentKeys[i]];
            }
        }

        stepCount++;
        index = (index + 1 ) % (steps.length());

        sleep(0.1);
    }

    // SOLUTION IS LCM of all repetitions
    cout<<stepCount<<"\n";
}