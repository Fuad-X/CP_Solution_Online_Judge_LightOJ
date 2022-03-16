#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, take[30][31], reject[30][31];
    cin >> t;

    for(int i=1; i<=t; i++)
    {
        int p, o, w;
        cin >> p >> o >> w;
        for(int j=0; j<p; j++)
        {
            int take_c = 0, reject_c = 0;
            for(int k=0; k<w; k++)
            {
                char x;
                int y;
                cin >> x >> y;
                if(x == '+') take[j][take_c++] = y;
                else if(x == '-') reject[j][reject_c++] = y;
            }
            take[j][take_c] = 0;
            reject[j][reject_c] = 0;
        }
        
        int take_box[30], size;
        cin >> size;
        
        for(int j = 0; j<size; j++) cin >> take_box[j];
        sort(take_box, take_box+size);
        
        bool key = false, key2;
        for(int j = 0; j<p; j++)
        {
            key2 = false;
            for(int k = 0; take[j][k] != 0; k++)
            {
                if(binary_search(take_box, take_box+size, take[j][k]))
                {
                    key2 = true;
                    break;
                }
            }
            
            if(!key2)
            {
                int cc = 0;
                for(int k = 0; reject[j][k] != 0; k++)
                {
                    cc++;
                    if(!binary_search(take_box, take_box+size, reject[j][k]))
                    {
                        key2 = true;
                        break;
                    }
                }
                if(cc == 0) key = true;
            }
            if(!key2) key = true;
            if(key) break;
        }
        if(key) cout << "Case "<<i<<": No\n";
        else cout << "Case "<<i<<": Yes\n";
        
        /*for(int j = 0; j<size; j++) cout << take_box[j] << " ";
        cout << "Take Box\n";
        
        /*for(int j = 0; j<p; j++)
        {
            cout << "Person " << j << "\n";
            for(int k = 0; take[j][k] != 0; k++)
            {
                cout << take[j][k] << " ";
            }
            cout << "Take\n";
            
            for(int k = 0; reject[j][k] != 0; k++)
            {
                cout << reject[j][k] << " ";
            }
            cout << "Reject\n";
        }*/
    }

    return 0;
}
