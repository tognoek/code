#include <bits/stdc++.h>
#define N 1000006
using namespace std;
int n,q,a,p,l,r;
string s;
vector<int> st;
bool check[N];
int main()
{
    cin>>n>>q>>s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1')
        {
            st.push_back(i+1);
            check[i+1] = true;
        }
        else check[i+1] = false;
    }
    for(int i = 1; i <= q; i++)
    {
        cin>>a;
        if(a == 1)
        {
            cin>>p;
            if(check[p]) 
            {
                st.erase(st.begin() + p);
                check[p] = false;
            }
            else
            {
                check[p] = true;
                st.push_back(p);
                sort(st.begin(),st.end());
            }
        }
        else if(a == 2)
        {
            cin>>l>>r;
            auto it1 = lower_bound(st.begin(),st.end(),l);
            auto it2 = upper_bound(st.begin(),st.end(),r);
            it2--;
            if(it1 == it2) cout<<"-1"<<'\n';
            else
            {
                int kq = int(1e6);
                while(it1 != it2)
                {
                    auto k = it1;
                    k++;
                    kq = min(kq,*(k) - *(it1));
                    it1++;
                }
                cout<<kq<<'\n';
            }
        }
    }
    return 0;
}
