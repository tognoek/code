#include <bits/stdc++.h>
using namespace std;
int a[1000][10000];
int kq[1000][10000];
int bl[1000][10000];
int tx[] = {2,2,1,-1,-2,-2,-1,1};
int ty[] = {-1,1,2,2,1,-1,-2,-2};
int main(){
    int n, k;
    int aa[10000];
    int bb[10000];
    cin>>n>>k;
    int x, y, u;
    int t = 0;
    for (int i = 0; i < k; i++){
        cin>>x>>y>>u;
        if (a[x][y] == 0){
            // Lọc ra các giá trị ô thưởng không bị trùng lặp
            // Nếu làm như này thì nếu có 2 ô thưởng trùng lặp thì giá trị của ô thương đó sẽ bị độn lên
            aa[t] = x;
            bb[t] = y;
            t++;
            bl[x][y] = 1;
            a[x][y] = u;
            if (a[x][y] < 0){
                a[x][y] = 0;
            }
        }else{
            a[x][y] = max(u,a[x][y]);
        }
    }
    for (int i = 1; i<=n; i++){
        for (int t = 1; t<=n; t++){
            cout << a[i][t] << " ";
        }
        cout<<endl;
    }
    int res = 0;
    for (int i = 0; i < t; i++){
        for (int j = 0; j < 8; j++){
            int xx = aa[i] + tx[j];
            int yy = bb[i] + ty[j];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && bl[xx][yy] == 0){
                kq[xx][yy] += a[aa[i]][bb[i]];
                res = max(res,kq[xx][yy]);
            }
        }
    }
        cout<<endl;
    for (int i = 1; i<=n; i++){
        for (int t = 1; t<=n; t++){
            cout << kq[i][t] << " ";
        }
        cout<<endl;
    }
    cout<<res;
    return 0;
}