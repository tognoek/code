#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void buildSegmentTreeAndCollectSums(const vector<int> &a, const vector<long long> &ar, vector<long long> &segTree, set<long long> &sums, int node, int start, int end)
{
    if (start == end)
    {
        segTree[node] = a[start];  
        sums.insert(segTree[node]); 
    }
    else
    {
        int mid = (start + end) / 2;
        buildSegmentTreeAndCollectSums(a, ar, segTree, sums, 2 * node + 1, start, mid);
        buildSegmentTreeAndCollectSums(a, ar, segTree, sums, 2 * node + 2, mid + 1, end);
        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2]; 
        for (int i = start; i <= end; ++i)
        {
            for (int j = i; j <= end; ++j)
            {
                if (i == 0){
                    sums.insert(ar[j]);
                }else{
                    sums.insert(ar[j] - ar[i-1]);
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<long long> ar(n+2);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (i == 0){
                ar[i] = a[i];
            }else{
                ar[i] = ar[i-1] + a[i];
            }
        }

        vector<long long> segTree(4 * n, 0);
        set<long long> sums;
        sums.insert(0);

        buildSegmentTreeAndCollectSums(a, ar, segTree, sums, 0, 0, n - 1);
        cout << sums.size() << endl;
        for (auto sum : sums)
        {
            cout << sum << " ";
        }
        cout << endl;
    }

    return 0;
}
