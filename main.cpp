#include <bits/stdc++.h>
using namespace std;
bool Possible(vector<int> &nums, int n, int k, int sep)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i] % sep==0) cnt+= nums[i]/sep-1;
        else
            cnt+= nums[i]/sep;
    }
    if(cnt <= k) return true;
    return false;
}
int solve(vector<int>& nums, int n, int k)
{
    sort(nums.begin(),nums.end());
    int s=0;
    int e= nums[n-1];
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        bool check= Possible(nums,n,k,mid);
        if(check)
        {
            ans= mid;
            e=mid-1;
        }
        else
            s= mid+1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>> nums[i];
    cout<<solve(nums,n,k);

}