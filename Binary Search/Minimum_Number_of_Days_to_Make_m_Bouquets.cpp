class Solution {
public:

    pair<int,int> findMinMax(vector<int>& bloomDay) {
        int mini = INT_MAX, maxi = INT_MIN;
        for(auto it : bloomDay) {
            if(mini > it) {
                mini = it;
            }
            if(maxi < it) {
                maxi = it;
            }
        }
        return {mini,maxi};
    }

    bool isPossible(vector<int>& bloomDay, int mid, int m, int k) {
        int cnt = 0;
        int bouquet = 0;
        for(auto it : bloomDay) {
            if(it <= mid) {
                cnt++;
            }
            else {
                bouquet += cnt/k;
                cnt = 0;
            }
        }
        bouquet += cnt/k;

        return (bouquet >= m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = long(m)*k;
        if(val > n) return -1;

        pair<int,int> time = findMinMax(bloomDay);
        int low = time.first;
        int high = time.second;

        while(low <= high) {
            int mid = (low+high)/2;
            if(isPossible(bloomDay, mid,m,k)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
