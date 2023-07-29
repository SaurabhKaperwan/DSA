class Solution {
public:

    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;

        for(auto it : piles) {
            if(it > maxi) {
                maxi = it;
            }
        }

        return maxi;
    }

    double minEatingSpeedUtil(vector<int>& piles, int k) {
        double totalTime = 0;
        for(auto it : piles) {
            totalTime += ceil(double(it)/double(k));
        }
        return totalTime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0, high = findMax(piles);

        while(low <= high) {
            int mid = (low + high) / 2;
            double totalTime = minEatingSpeedUtil(piles,mid);

            if(h >= totalTime) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }

        }
        return low;
    }
};
