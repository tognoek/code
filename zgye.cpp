#include <bits/stdc++.h>
using namespace std;
int a[10][10];
void print(){
    for (int i =1; i < 9; i++){
        for (int t = 1; t < 9; t++){
            if (a[i][t] == 1){
                cout<<"X";
            }
            else{
                cout<<"0";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
bool check(int u, int v){
    int x, y;
    x = u;
    y = v;
    while (x <= 8 && y <= 8 && x >=0 && y >=0){
        x++;
        if (a[x][y] == 1){
            return true;
        }
    }
    x = u;
    y = v;
    while (x <= 8 && y <= 8 && x >=0 && y >=0){
        x--;
        if (a[x][y] == 1){
            return true;
        }
    }
    x = u;
    y = v;
    while (x <= 8 && y <= 8 && x >=0 && y >=0){
        x++;
        y++;
        if (a[x][y] == 1){
            return true;
        }
    }
    x = u;
    y = v;
    while (x <= 8 && y <= 8 && x >=0 && y >=0){
        x++;
        y--;
        if (a[x][y] == 1){
            return true;
        }
    }
    x = u;
    y = v;
    while (x <= 8 && y <= 8 && x >=0 && y >=0){
        y--;
        if (a[x][y] == 1){
            return true;
        }
    }
    x = u;
    y = v;
    while (x <= 8 && y <= 8 && x >=0 && y >=0){
        y++;
        if (a[x][y] == 1){
            return true;
        }
    }
    x = u;
    y = v;
    while (x <= 8 && y <= 8 && x >=0 && y >=0){
        y--;
        x++;
        if (a[x][y] == 1){
            return true;
        }
    }
    x = u;
    y = v;
    while (x <= 8 && y <= 8 && x >=0 && y >=0){
        y--;
        x--;
        if (a[x][y] == 1){
            return true;
        }
    }
}
void checkAll()
{
    for (int i = 1; i < 9; i++){
        for(int t = 1; t < 9; t++){
            if (a[i][t] == 1){
                if (check(i, t)) return;
            }
        }
    }
    print();
}
void tryy(int k)
{
    for (int i = 1; i < 9; i++){
        a[k][i] = 1;
        if (k == 8){
            checkAll();
        }
        else{
            tryy(k + 1);
        }
        a[k][i] = 0;
    }
}
int main()
{
    tryy(1);
}