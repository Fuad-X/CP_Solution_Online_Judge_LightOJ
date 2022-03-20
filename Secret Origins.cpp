#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        long long n, m;
        cin >> n;
        m = n;
        int arr[64];
        int size = 0;
        while(n)
        {
            arr[size] = (n&1);
            n = (n>>1);
            size++;
        }

        bool flag = true;
        for(int j=0; j<size-1; j++)
        {
            if(arr[j]==1 && arr[j+1]==0) 
            {
                flag = false;
                arr[j]=0, arr[j+1]=1;
                int count = 0;
                for(int k=j-1; k>=0; k--) if(arr[k]==1) count++, arr[k]=0;
                for(int k=0; k<count; k++) arr[k] = 1;
                break;
            }
        }

        if(flag) 
        {
            m = (m<<1);
            arr[size] = 0;
            size++;

            for(int j=0; j<size-1; j++)
            {
                if(arr[j]==1 && arr[j+1]==0) 
                {
                    flag = false;
                    arr[j]=0, arr[j+1]=1;
                    int count = 0;
                    for(int k=j-1; k>=0; k--) if(arr[k]==1) count++, arr[k]=0;
                    for(int k=0; k<count; k++) arr[k] = 1;
                    break;
                }
            }
        }

        int res = 0;
        for(int j=0, m=1; j<size; j++,m*=2) if(arr[j]==1) res+=m;
        cout << "Case " << i+1 << ": "  << res << endl; 
    }
   
   return 0;
}
