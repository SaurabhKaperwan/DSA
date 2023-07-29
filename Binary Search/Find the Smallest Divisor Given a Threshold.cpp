class Solution {
public:

    int findMax(vector<int>& nums) {
        int maxi = INT_MIN;

        for(auto it : nums) {
            if(it > maxi) {
                maxi = it;
            }
        }
        return maxi;
    }

    int smallestDivisorUtil(vector<int>& nums,int mid) {
        int sum = 0;
        for(auto it : nums) {
            sum += ceil(double(it)/double(mid));
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int high = findMax(nums);
        int low = 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            int val = smallestDivisorUtil(nums,mid);
            if(val <= threshold) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
