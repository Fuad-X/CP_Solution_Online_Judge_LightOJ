#include <iostream>
#include <algorithm>
using namespace std;

int binary(long long arr[], int l, int h, int f)
{
    if (l > h)
        return l;
    int m = l + (h - l) / 2;
    if (arr[m] <= f) return binary(arr, m + 1, h, f);
    else return binary(arr, l, m - 1, f);
}

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        long long arr[2000];
        int n;
        cin >> n;
        for(int j=0; j<n; j++) cin >> arr[j];
        sort(arr, arr+n);
        int count = 0;

        for(int j=0; j<n-2; j++)
        {
            for(int k=j+1; k<n-1; k++)
            {
                int sum = arr[j]+arr[k];
                int m = binary(arr, 0, n-1, sum-1);
                if(arr[m-1] == sum) m--;
                count+= m-1 >= k ? m-k-1 : 0;
            }
        }
        cout << "Case " << i << ": " << count << endl;
    }

    return 0;
}
