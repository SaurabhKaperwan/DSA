//lower bound :  smallest index for which arr[i] >= num 

int lowerBound(vector<int> arr, int n, int x) {
	int low = 0, high = n - 1;
	int ans = n;

	while(low <= high) {
		int mid = (low + high) / 2;

		if(arr[mid] >= x) {
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return ans;

	/*
	Shortcut:
	lb = lower_bound(arr.begin(), arr.end(),x) - arr.begin();
	*/
}
