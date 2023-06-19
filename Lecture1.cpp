#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(NlogN), Space complexity: O(n)
void bruteMerge(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> res(n + m);
    int i = 0;
    for (; i < n; i++)
    {
        res[i] = a[i];
    }
    for (int j = 0; j < m; j++, i++)
    {
        res[i] = b[j];
    }
    sort(res.begin(), res.end());
    i = 0;
    for (; i < n + m; i++)
    {
        a[i] = res[i];
    }
}

// Time Complexity: O(N), Space complexity: O(1)
void optimisedMerge(vector<int> &a, vector<int> &b, int n, int m)
{
    int i = n - 1, j = m - 1, k = n + m - 1;
    while (i >= 0 && j >= 0)
    {
        if (a[i] >= b[j])
        {
            a[k] = a[i];
            i--;
        }
        else
        {
            a[k] = b[j];
            j--;
        }
        k--;
    }
    while (j >= 0)
    {
        a[j] = b[j];
        j--;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + m, 0), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    // Don't use both simultaneously
    bruteMerge(a, b, n, m);
    for (int i = 0; i < n + m; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    optimisedMerge(a, b, n, m);
    for (int i = 0; i < n + m; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}