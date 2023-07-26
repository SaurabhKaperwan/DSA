#include <bits/stdc++.h> 
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int lb = lower_bound(arr.begin(),arr.end(),k) - arr.begin();

    if(lb == n || arr[lb] != k)
        return {-1,-1};
    int ub = upper_bound(arr.begin(),arr.end(),k) - arr.begin() - 1;

    return {lb,ub};
}