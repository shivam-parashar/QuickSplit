#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, m, u, v, w, mini, x, maxi, y;
    cout<<"Enter the number of people and the number of transaction"<<endl;
    cin >> n >> m;
    int debt[n+1];
    for(i=0; i<=n; i++) 
    {
        debt[i]=0;
    }
    cout<<"ThankYou!"<<endl;
    cout<<"In the next "<<m<<" lines " <<"please enter the index of the person who paid the amount followed by the index of the person who owe it"<<endl;


    for(i=0; i<m; i++) 
    {
        //u has to pay v an amount w
        cin >> u >> v >> w;
        debt[u] = debt[u] - w;
        debt[v] = debt[v] + w;
    }

    multiset< pair<int, int > > S;

    for(i=0; i<n; i++)
    {
        if(debt[i] != 0) S.insert(make_pair(debt[i], i));
    } 
           
    int TotalTransactions = 0;

    while(!S.empty()) 
    {
        pair<int, int > p1 = *S.begin(); 
        S.erase(S.begin());
        mini = p1.first;
        x = p1.second;

        pair<int, int > p2 = *S.rbegin(); 
        S.erase(prev(S.end()));
        maxi = p2.first;
        y = p2.second;

        int amount = min(-mini, maxi);
        
        TotalTransactions++; 
        // mini pays amount "amount" to maxi
        cout<<x<<" pays amount "<<amount<<" to "<<y<<endl;
        mini = mini + amount;
        maxi = maxi - amount;
        
        if(mini)
        {
            S.insert(make_pair(mini, x));
        }
        if(maxi) 
        {
            S.insert(make_pair(maxi, y));
        }
    }
    
    cout <<"Total number of Transactions occurred are "<<TotalTransactions << endl;
    return 0;
}
