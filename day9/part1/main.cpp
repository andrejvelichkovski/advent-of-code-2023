#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include <climits>
#include <algorithm>
#include <deque>

#define ll long long
using namespace std;

vector< vector<ll> > sequences;

bool checkZeros(vector<ll> v) {
    for(ll i:v) {
        if(i!=0) return false;
    }
    return true;
}

int main() {
    string sequence;
    while(getline(cin, sequence)) {
        stringstream parser(sequence);
    
        sequences.push_back(vector<ll>());
        ll number;
        while(parser>>number) {
            sequences.back().push_back(number);
        }
    }

    ll result = 0;
    for(int i=0;i<sequences.size();i++) {
        vector<vector<ll> > currentSequences;

        currentSequences.push_back(vector<ll>());
        for(ll x:sequences[i])
            currentSequences.back().push_back(x);

        while(!checkZeros(currentSequences.back())) {
            currentSequences.push_back(vector<ll>());
            for(int j=1;j<currentSequences[currentSequences.size() - 2].size();j++) {
                int tmp = currentSequences.size() - 2;
                currentSequences.back().push_back(currentSequences[tmp][j] - currentSequences[tmp][j-1]);
            }
        }

        currentSequences.back().push_back(0);

        for(int i=currentSequences.size() - 2;i>=0;i--) {
            currentSequences[i].push_back(currentSequences[i].back() + currentSequences[i+1].back());
        }

        result += currentSequences[0].back();
    }
    cout<<result<<"\n";
}