#include <bits/stdc++.h>

using namespace std;

struct Dot
{
    int left, right;
    int assign, no_assign;
    int back;
    int next;
    void update()
    {
        no_assign = max(left, right);
        assign = min(left, right);
    }

    void updateLeft(int point)
    {
        left += point;
    }
    void updateRight(int point)
    {
        right += point;
    }

    int sum(){
        return left + right;
    }
};

struct Val
{
    int assign, left, right, index, no_assign;
};

int main()
{
    vector<Dot> dots;
    vector<Val> vals;
    string s;
    int n;
    cin >> n;
    cin >> s;
    int count, len;
    count = 0;
    len = s.length();
    Dot dot;
    Val val;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '0')
        {
            count++;
        }
        else
        {
            if (dots.size() == 0)
            {
                dot.left = count;
                dot.back = -1;
                dots.push_back(dot);
            }
            else
            {
                dot.left = count;
                dots.back().right = count;
                dots.back().update();
                val.assign = dots.back().assign;
                val.no_assign = dots.back().no_assign;
                val.index = dots.size() - 1;
                val.left = dots.size() - 2;
                val.right = dots.size();
                vals.push_back(val);
                dots.back().next = dots.size();
                dot.back = dots.size() - 1;
                dots.push_back(dot);
            }
            count = 0;
        }
    }
    dots.back().right = count;
    dots.back().update();
    dots.back().next = -1;
    val.assign = dots.back().assign;
    val.no_assign = dots.back().no_assign;
    val.index = dots.size() - 1;
    val.left = dots.size() - 2;
    val.right = -1;
    vals.push_back(val);
    sort(vals.begin(), vals.end(), [](const Val &a, const Val &b)
         {
             if (a.assign == b.assign)
             {
                 return a.no_assign < b.no_assign; 
             }
             return a.assign < b.assign; 
         });
    for (int i = 0; i < dots.size(); i++)
    {
        cout << dots[i].assign << " " << dots[i].no_assign << " " << dots[i].left << " " << dots[i].right << " " << dots[i].back << " " << dots[i].next << endl;
    }
    cout << endl;
    for (int i = 0; i < vals.size(); i++)
    {
        cout << vals[i].assign << " " << vals[i].no_assign << " " << vals[i].left << " " << vals[i].right << " " << vals[i].index << endl;
    }
    int length_vector;
    int count_zero;
    int sum_zero;
    int index_point;
    int result;
    int left_point, right_point;
    result = -1;
    length_vector = dots.size();
    for (int i = 0; i < length_vector; i++){
        index_point = vals.at(i).index;
        count_zero = dots.at(index_point).assign;
        result = max(result, (length_vector - i + 1) * count_zero);
        sum_zero = dots.at(index_point).sum();
        left_point = vals.at(i).left;
        right_point = vals.at(i).right;
        if (left_point > -1){
            dots.at(left_point).updateRight(sum_zero);
            dots.at(left_point).update();
        }
        if (right_point > -1){
            dots.at(right_point).updateLeft(sum_zero);
            dots.at(left_point).update();
        }
    }
}