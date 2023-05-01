#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll solve(vector<vector<int>> nums, int n, int m)
{
    ll ans=0;
    for(ll i=0;i<m;i++)
    {
        vector<int> temp;
        for(ll j=0;j<n;j++)
        {
            temp.push_back(nums[j][i]);
        }
        sort(temp.begin(),temp.end());
        for(ll j=0;j<n;j++)
        {
            ans+= j*temp[j]- (n-1-j)*temp[j];
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin>> t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> nums(n, vector<int> (m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>> nums[i][j];
        cout<<solve(nums,n,m)<<endl;
 
    }
}
