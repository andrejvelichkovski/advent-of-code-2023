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
    'A', 'K', 'Q', 'T', '9', '8', '7', '6', '5', '4', '3', '2', 'J'};

map<char, int> symbolScore;

vector<pair<string, ll>> bids;

bool checkFiveKind(map<char, int> charCount) {
    bool countTwo=false, countThree=false;
    bool countFour =false;
    for(auto it:charCount) {
        if(it.second == 5)
            return true;

        if(it.second == 2) countTwo = true;
        if(it.second == 3) countThree = true;
        if(it.second == 4) countFour = true;
    }

    if(charCount['J'] == 4) return true;
    if(charCount['J'] == 3 && countTwo) return true;
    if(charCount['J'] == 2 && countThree) return true;
    if(charCount['J'] == 1 && countFour) return true;

    return false;
}

bool checkFourKind(map<char, int> charCount) {
    bool countTwo, countThree;
    for (auto it : charCount)
    {
        if (it.second == 4)
        {
            return true;
        }

        if(it.first == 'J') continue;

        if(it.second == 2) countTwo = true;
        if(it.second == 3) countThree = true;
    }

    if(charCount['J'] == 3) return true;
    if(charCount['J'] == 1 && countThree) return true;
    if(charCount['J'] == 2 && countTwo) return true;

    return false;
}

bool checkFullHouse(map<char, int> charCount) {
    bool foundThree = false, foundTwo = false;

    int countTwo = 0, countThree = 0;
    for (auto it : charCount)
    {
        foundThree |= (it.second == 3);
        foundTwo |= (it.second == 2);

        if(it.first == 'J') continue;

        if(it.second == 2) countTwo++;
        if(it.second == 3) countThree++;
    }

    if (foundThree && foundTwo)
        return true;

    if(charCount['J'] == 3) return true;
    if(charCount['J'] == 1 && countThree) return true;
    if(charCount['J'] == 1 && countTwo == 2) return true;

    if(charCount['J'] == 2 && countTwo) return true;

    return false;
}

bool checkThreeKind(map<char, int> charCount) {
    bool foundThree = false, foundTwo = false;

    int countTwo = 0, countThree = 0;
    for (auto it : charCount)
    {
        foundThree |= (it.second == 3);
        foundTwo |= (it.second == 2);

        if(it.first == 'J') continue;

        if(it.second == 2) countTwo++;
        if(it.second == 3) countThree++;
    }

    if (foundThree)
        return true;

    if(charCount['J'] == 2) return true;
    if(charCount['J'] == 1 && countTwo) return true;
    return false;
}

bool checkTwoPair(map<char, int> charCount) {
    // Check two / one pair
    int cntTwo = 0;
    for (auto it : charCount)
    {
        if (it.second == 2)
            cntTwo++;
    }

    if (cntTwo == 2)
        return true;
    
    if(charCount['J'] == 2)
        return true;
    
    if(charCount['J'] == 1 && cntTwo) 
        return true;
    
    return false;
}

bool checkPair(map<char, int> charCount) {
    int cntTwo = 0;
    for (auto it : charCount)
    {
        if (it.second == 2)
            cntTwo++;
    }

    if(cntTwo) return true;
    if(charCount['J'] == 1) return true;
    return false;
}

int getScore(string hand)
{
    map<char, int> charCount;

    for (int i = 0; i < hand.length(); i++)
    {
        charCount[hand[i]]++;
    }
    
    if(checkFiveKind(charCount)) {
        return 8;
    }

    if(checkFourKind(charCount)) {
        return 7;
    }

    if(checkFullHouse(charCount)) {
        return 6;
    }

    if (checkThreeKind(charCount)){
        return 5;
    }

    if(checkTwoPair(charCount)) {
        return 4;
    }

    if(checkPair(charCount)) {
        return 3;
    }

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
    reverse(bids.begin(), bids.end());

    ll result = 0LL;
    for(int i=0;i<bids.size();i++) {
        result += (i + 1) * bids[i].second;
        cout<<bids[i].first<<" " <<getScore(bids[i].first)<<"\n";
    }
    cout<<result<<"\n";
}