#include<bits/stdc++.h>
using namespace std;

long long slove(string s){
    stack<long long> myStack;
    long long fisrt_num;
    long long second_num;
    long long number = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '+'){
            fisrt_num = myStack.top();
            myStack.pop();
            second_num = myStack.top();
            myStack.pop();
            // cout<<fisrt_num<<" "<<second_num<<endl;
            myStack.push(second_num + fisrt_num);
            number = 0;
        }
        else if (s[i] == '-'){
            fisrt_num = myStack.top();
            myStack.pop();
            second_num = myStack.top();
            myStack.pop();
            // cout<<fisrt_num<<" "<<second_num<<endl;
            myStack.push(second_num - fisrt_num);
            number = 0;
        }
        else if (s[i] == '*'){
            fisrt_num = myStack.top();
            myStack.pop();
            second_num = myStack.top();
            myStack.pop();
            // cout<<fisrt_num<<" "<<second_num<<endl;
            myStack.push(second_num * fisrt_num);
            number = 0;
        }
        else if (s[i] == ' ' && (s[i-1] - '0') >= 0 && (s[i-1] - '0') <= 9){
            myStack.push(number);
            // cout<<number<<" "<<s[i-1]<<endl;
            number = 0;
        }
        else if ((s[i] - '0') >= 0 && (s[i] - '0') <= 9){
            number = number * 10 + (s[i] - '0');
            // cout<<number<<" "<<s[i]<<endl;
        }
    }
    return myStack.top();
}

int main() {
    freopen("Postfix.inp","r",stdin);
    freopen("Postfix.out","w",stdout);   
    string BieuThuc;
    while (getline(cin, BieuThuc)){
        cout << slove(BieuThuc)<<endl;
    }
    return 0;
}
