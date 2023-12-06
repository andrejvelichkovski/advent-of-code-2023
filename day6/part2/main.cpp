#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include <climits>

#define ll long long 
using namespace std;

ll str_to_ll(string a)
{
    ll value = 0LL;
    for (int i = 0; i < a.length(); i++)
    {
        value *= 1LL * 10;
        value += (a[i] - '0');
    }
    return value;
}


ll parseValues(string valueString, string keyword) {
    stringstream parser(valueString);

    string strElement;
    string fullString = "";
    while(parser>>strElement) {
        if(strElement != keyword) {
            fullString += strElement;
        }
    }

    return str_to_ll(fullString);
}

int main() {
    string timeString;
    getline(cin, timeString);
    ll time = parseValues(timeString, "Time:");

    string distanceString;
    getline(cin, distanceString);
    ll distance = parseValues(distanceString, "Distance:");

    ll currCount = 0LL;
    for(int j=1;j<time;j++) {
        if((time - j)*j > distance) {
            currCount++;
        }
    }

    cout<<currCount<<"\n";
}