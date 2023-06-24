#include<bits/stdc++.h>
using namespace std;

// Question 1: Sort 0s, 1s, 2s
void sortColors(vector<int>& nums) {
    int n=nums.size();
    int low=0, high=n-1,mid=0;
    while(mid<=high){
        if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
        } else if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            if(nums[mid]==0){
                mid++;
            }
        } else {
            mid++;
        }
    }
}

// Question 2: Set matrix zeros
void setZeros(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    vector<pair<int,int>> onesPos;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(matrix[i][j] == 0){
                onesPos.push_back({i,j});
            }
        }
    }
            
    int n = onesPos.size();
    for(int i = 0; i < n; i++){
        int row = onesPos[i].first;
        int col = onesPos[i].second;
        for(int j = 0; j < c; j++)
            matrix[row][j] = 0;
        for(int j = 0; j < r; j++)
            matrix[j][col] = 0; 
    }
}

// Question 3: Search a 2d matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m=matrix.size(),n=matrix[0].size();
    int l=0,r=m*n-1;

    while(l<=r){
        int mid= l + (r-l)/2;
        if(matrix[mid/n][mid%n]==target) return true;
        else if(matrix[mid/n][mid%n]>target) r=mid-1;
        else l=mid+1;
    }
    return false;
}

// Question 4: Search in a rotated sorted array
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1;
    while(low<=high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[low] <= nums[mid]) {
            if(target < nums[mid] && target >= nums[low]) {
                high = mid-1;
            } else {
                low = mid + 1;
            }
        } else {
            if(target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {1,2,1,2,0,1,0,2,0,1,1,1,2,2,0,0,0};
    sortColors(nums);
    for(int i=0;i<nums.size();i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    
    vector<vector<int>> nums1 = {{1,1,1},{1,0,1},{1,1,1}};
    setZeros(nums1);
    for(int i=0;i<nums1.size();i++) {
        for(int j=0;j<nums1[0].size();j++) {
            cout<<nums1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    nums1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<searchMatrix(nums1, 30)<<endl;
    cout<<endl;
    
    nums = {3,4,5,6,1,2};
    cout<<search(nums, 1)<<endl;
    return 0;
}
