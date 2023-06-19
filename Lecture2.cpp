#include<bits/stdc++.h>
using namespace std;

int firstOccurance(vector<int> &nums, int target) {
    int s = 0;
    int e = nums.size() - 1;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target) {
            ans = mid;
            e = mid - 1;
        } else if (nums[mid] > target) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}
int lastOccurance(vector<int> &nums, int target) {
    int s = 0;
    int e = nums.size() - 1;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target) {
            ans = mid;
            s = mid + 1;
        } else if (nums[mid] > target) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}
vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> range(2);
    range[0] = (firstOccurance(nums, target));
    range[1] = (lastOccurance(nums, target));
    return range;
}

int main() {
    vector<int> nums={1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6};
    int target = 3;
    vector<int> res = searchRange(nums, target);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}