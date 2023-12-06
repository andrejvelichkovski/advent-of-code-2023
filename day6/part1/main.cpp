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


vector<ll> parseValues(string valueString, string keyword) {
    stringstream parser(valueString);

    string strElement;
    vector<ll> values;
    while(parser>>strElement) {
        if(strElement != keyword) {
            values.push_back(str_to_ll(strElement));
        }
    }

    return values;
}

int main() {
    string timeString;
    getline(cin, timeString);
    vector<ll> times = parseValues(timeString, "Time:");

    string distanceString;
    getline(cin, distanceString);
    vector<ll> distances = parseValues(distanceString, "Distance:");

    ll result = 1LL;
    for(int i=0;i<times.size();i++) {
        ll currCount = 0LL;
        for(int j=1;j<times[i];j++) {
            if((times[i] - j)*j > distances[i]) {
                currCount++;
            }
        }

        result *= currCount;
    }

    cout<<result<<"\n";
}