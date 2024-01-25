#include<bits/stdc++.h>

using namespace std;

int main(){
    unordered_map<string, string> map;
    string s;
    while (getline(cin, s))
    {
        size_t space = s.find(' ');

        if (space != string::npos){
            string valuse = s.substr(0, space);
            string key = s.substr(space+1);
            map.insert({key, valuse});
        }
        else{
            if (s.length() > 0){
                auto it = map.find(s);
                if (it != map.end()){
                    cout<<it->second<<endl;
                }
                else{
                    cout<<"eh"<<endl;
                }
            }
        }
    }
    
}