#include <bits/stdc++.h>
using namespace std;
bool SortbySec(pair<int,int> &a, pair<int,int>&b)
{
    return a.second< b.second;
}
int solve(vector<pair<int,int>> map, int w,int h, int n)
{
    sort(map.begin(),map.end());
    int maxWidth= map[0].first- 1;
    for(int i=1;i<n;i++)
    {
        maxWidth= max(map[i].first-map[i-1].first,maxWidth);
    }
    maxWidth= max(maxWidth, w-map[n-1].first);
    sort(map.begin(),map.end(), SortbySec);
    int maxLength= map[0].second-1;
    for(int i=1;i<n;i++)
    {
        maxLength= max(map[i].second-map[i-1].second,maxLength);
    }
    maxLength= max(maxLength,h-map[n-1].second);
    return maxWidth*maxLength;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int test;
    cin>> test;
    while(test--)
    {
        int w;
        int h;
        int n;
        cin>>w>>h>>n;
        vector<pair<int,int>> mp;
        for(int i=0;i<n;i++)
        {
            int w1,h1;
            cin>>w1>>h1;
            mp.push_back(make_pair(w1,h1));
        }
        cout<<solve(mp,w,h,n);


    }
}