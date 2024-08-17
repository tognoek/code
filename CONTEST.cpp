#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("CONTEST.inp","r",stdin);
    freopen("CONTEST.out","w",stdout);
    unordered_map<string, long long> myMaps;
    unordered_map<string, long long> points;
    vector<string> names;
    string name, student;
    string title;
    long long point;
    int c, p, s;
    cin >> c >> p >> s;
    for (int i = 0; i < c; i++){
        cin >> name;
        names.push_back(name);
    }
    for (int i = 0; i < p; i++){
        cin >> name >> point;
        points[name] = point;
    }
    for (int i = 0; i < s; i++){
        cin >> student >> name >> title;;
        if (title == "AC"){
            // cout << student << " " << name << endl;
            myMaps[student] += points[name];
        }
    }
    for (int i = 0; i < c; i++){
        cout << names[i] << " " << myMaps[names[i]] << endl;
    }
    return 0;
}