//Similar to find Lower Bound

int searchInsert(vector<int>& arr, int m) {
	int lb = lower_bound(arr.begin() , arr.end(), m) - arr.begin();
	return lb; 
}