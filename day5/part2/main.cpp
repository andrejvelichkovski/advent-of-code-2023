#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include <climits>

#define ll long long
using namespace std;

const string MAP_TYPES[7] = {
    "seed-to-soil map:",
    "soil-to-fertilizer map:",
    "fertilizer-to-water map:",
    "water-to-light map:",
    "light-to-temperature map:",
    "temperature-to-humidity map:",
    "humidity-to-location map:"
};

vector<ll> seeds;
map<string, vector<pair<pair<ll, ll>, ll> > > mapping;

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

int main()
{
    string currentLine;
    string currentMapType;
    while (getline(cin, currentLine))
    {
        if(currentLine.length() == 0)
            continue;

        if (!currentLine.find("seeds:"))
        {
            stringstream parser(currentLine);

            string strInput;
            while (parser >> strInput)
            {
                if (strInput != "seeds:")
                {
                    seeds.push_back(str_to_ll(strInput));
                }
            }
            continue;
        }

        if(currentLine.find("map:") < currentLine.length()) {
            currentMapType = currentLine;
            continue;
        }

        stringstream parser(currentLine);
        string source, dest, range;
        parser >> source >> dest >> range;

        mapping[currentMapType].push_back(
            make_pair(
                make_pair(
                    1LL * str_to_ll(source),
                    1LL * str_to_ll(dest)
                ),
                1LL * str_to_ll(range)
            )
        );
    }

    ll minSeed = LLONG_MAX;
    for(ll sIndex=0;sIndex < seeds.size(); sIndex += 2) {
        for(ll seed=seeds[sIndex]; seed < seeds[sIndex]+seeds[sIndex+1]; seed++) {
            ll currentSeed = seed;
            for(string i: MAP_TYPES) {
                ll tempSeed = currentSeed;
                for(pair<pair<ll, ll>, ll> tuple: mapping[i]) {
                    if(currentSeed >= tuple.first.second && currentSeed <= tuple.first.second + tuple.second - 1) {
                        ll diff = 1LL * currentSeed - 1LL * tuple.first.second;
                        if(tuple.first.first + diff < 0) {
                            cout<<tuple.first.first<< " "<<diff<<"\n";
                        }
                        tempSeed = 1LL * tuple.first.first + diff;
                    }
                }
                if(tempSeed < 0 ){
                    cout<<"overflow"<<"\n";
                }
                currentSeed = tempSeed;
            }
            minSeed = min(minSeed, currentSeed);
        }
        cout<<"DONE FOR ONE MORE SEED\n";
    }
    cout<<minSeed<<"\n";
}