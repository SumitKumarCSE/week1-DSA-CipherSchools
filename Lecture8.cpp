#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    if(n==2) return min(nums[0],nums[1]);
    int low = 1, high = n-2;
    int mid = 0;
    while(low <= high) {
        mid = (low+high) / 2;
        if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]) return nums[mid];
        if(nums[low] <= nums[mid]) {
            if(nums[low] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } else {
            if(nums[low] < nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return min(nums[0],nums[n-1]);
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin() , nums.end());
    if(nums.size() < 3){
        return {};
    }
    if(nums[0] > 0){
        return {};
    }
    vector<vector<int>> answer;
    for(int i = 0 ; i < nums.size() ; ++i){
        if(nums[i] > 0){
            break;
        }
        if(i > 0 && nums[i] == nums[i - 1]){
            continue;
        }
        int low = i + 1 , high = nums.size() - 1;
        int sum = 0;
        while(low < high){
            sum = nums[i] + nums[low] + nums[high];
            if(sum > 0){
                high--;
            } else if(sum < 0){
                low++;
            } else {
                answer.push_back({nums[i] , nums[low] , nums[high]});
                int last_low_occurence = nums[low] , last_high_occurence = nums[high];
                while(low < high && nums[low] == last_low_occurence){
                    low++;
                }
                while(low < high && nums[high] == last_high_occurence){
                    high--;
                }
            }
        }
    }
    return answer;
}

int main() {
    vector<int> nums = {3,4,5,6,7,2};
    cout<<findPivot(nums)<<endl;
    cout<<endl;
    
    nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(nums);
    for(auto it : res) {
        for(auto i : it) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
