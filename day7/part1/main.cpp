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

char symbols[13] = {
    'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2'};

map<char, int> symbolScore;

vector<pair<string, ll>> bids;

int getScore(string hand)
{
    map<char, int> charCount;

    for (int i = 0; i < hand.length(); i++)
    {
        charCount[hand[i]]++;
    }

    // Check five of a kind
    for (auto it : charCount)
    {
        if (it.second == 5)
        {
            return 8;
        }
    }

    // Check four of a kind
    for (auto it : charCount)
    {
        if (it.second == 4)
        {
            return 7;
        }
    }

    // Check full-house
    bool foundThree = false, foundTwo = false;
    for (auto it : charCount)
    {
        foundThree |= (it.second == 3);
        foundTwo |= (it.second == 2);
    }

    if (foundThree && foundTwo)
        return 6;
    // Check three of a kind
    if (foundThree)
        return 5;

    // Check two / one pair
    int cntTwo = 0;
    for (auto it : charCount)
    {
        if (it.second == 2)
            cntTwo++;
    }

    if (cntTwo == 2)
        return 4;
    if (cntTwo == 1)
        return 3;
    return 2;
}

int compareSameScore(string handA, string handB)
{
    for (int i = 0; i < handA.length(); i++)
    {
        if(handA[i] == handB[i]) continue;
        
        if(symbolScore[handA[i]] < symbolScore[handB[i]])
            return true;
        else
            return false;
    }
}

bool compareHands(pair<string, ll> handA, pair<string, ll> handB) {
    // cout<<"comparing"<<handA.first<<" "<<handB.first<<" "<<getScore(handA.first)<<" "<<getScore(handB.first)<<"\n";
    if(getScore(handA.first) == getScore(handB.first)) {
        return compareSameScore(handA.first, handB.first);
    }

    if(getScore(handA.first) > getScore(handB.first)) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    for(int i=0;i<13;i++) {
        symbolScore[symbols[i]] = i;
    }

    string hand;
    ll bid;
    while (cin >> hand >> bid)
    {
        bids.push_back(make_pair(hand, bid));
    }

    sort(bids.begin(), bids.end(), compareHands);

    ll result = 0LL;
    for(int i=0;i<bids.size();i++) {
        result += (bids.size() - i) * bids[i].second;
        cout<<bids[i].first<<"\n";
    }
    cout<<result<<"\n";
}