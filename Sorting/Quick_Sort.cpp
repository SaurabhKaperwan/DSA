class Solution 
{
    public:

        int quickSortUtil(vector<int>& nums, int low, int high)
        {
            int pivot = nums[low];
            int i = low;
            int j = high;

            while(i < j)
            {
                while(i <= high and nums[i] <=  pivot)
                    i++;
                while(j >= low and nums[j] > pivot)
                    j--;
                if(i < j)
                    swap(nums[i] , nums[j]);
            }
            swap(nums[low] , nums[j]);
            return j;
        }

        void quickSort(vector<int>& nums, int low, int high)
        {
            if(low < high)
            {
                int pivot = quickSortUtil(nums, low, high);
                quickSort(nums, low, pivot - 1);
                quickSort(nums, pivot + 1 , high);
            }
        }

        vector<int> sortArray(vector<int>& nums) 
        {
            int n = nums.size();
            quickSort(nums, 0, n-1);
            return nums;
        }
};
