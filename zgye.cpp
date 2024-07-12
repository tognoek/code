    #include <bits/stdc++.h>
    #define N 10005
    using namespace std;
    long long n,k,a[N],l,r;
    string s,c = "";
    bool kq = false;
    int main()
    {
        // freopen("EraseChar.inp","r",stdin);
        // freopen("EraseChar.out","w",stdout);
        cin>>n>>k;
        cin>>s;
        int len = n - k;
        for(int t = 0; t <= k; t++)
        {
            bool check = true;
            int right = t + len - 1;
            // cout<<t<<" "<<right<<endl;
            for(int i = t; i + (len / 2) <= right; i++)
                if(s[i] != s[right - (i - t)])
                    check = false;
            if(check)
            {
                kq = true;
                for(int i = t; i <= right; i++)
                    c = c + s[i];
                break;
            }
        }
        if(!kq)
        {
            cout<<"No";
            return 0;
        }
        cout<<c;
        return 0;
    }
