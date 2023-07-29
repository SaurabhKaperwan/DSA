class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int maxi = INT_MAX;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] >= nums[low]) {
                maxi = (maxi > nums[low]) ? nums[low] : maxi;
                low = mid + 1;
            }
            else {
                maxi = (maxi > nums[mid]) ? nums[mid] : maxi;
                high = mid - 1;
            }
        }
        return maxi;
    }
};
