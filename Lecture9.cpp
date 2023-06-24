#include<bits/stdc++.h>
using namespace std;

// Question 1: Generate Parentheses
void addingpar(vector<string> &v, string str, int n, int m){
    if(n==0 && m==0) {
        v.push_back(str);
        return;
    }
    if(m > 0){ addingpar(v, str+")", n, m-1); }
    if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    addingpar(res, "", n, 0);
    return res;
}

// Question 2: Letter Combinations of a Phone Number
vector<string> letterCombinations(string digits) {
    if(digits == "") return {};
    vector<string> mappings{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans{""};
    for(auto& digit : digits){
        vector<string> extendCombination;
        for(auto& currentCombination : ans)
            for(auto& newChar : mappings[digit - '2'])
                extendCombination.push_back(currentCombination + newChar);                   
        ans = move(extendCombination);
    }
    return ans;
}

// Question 3: Permutations
vector<vector<int>> ans;
void helper(vector<int>& nums, int idx){
    if (idx >= nums.size()){
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); ++i){
        swap(nums[idx], nums[i]);
        helper(nums,idx+1);
        swap(nums[idx], nums[i]);
    }
}
void permute(vector<int>& nums) {
    helper(nums,0);
    return;
}

// Question 4: Power Set
void sub(vector<int> &nums, int i, vector<int>& temp, vector<vector<int>>& ans) {
    if(i==nums.size()) {
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    sub(nums, i+1, temp, ans);
    temp.pop_back();
    sub(nums, i+1, temp, ans);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;       
    sub(nums, 0, temp, ans);
    return ans;
}

int main() {
    int n = 4;
    vector<string> res = generateParenthesis(n);
    for(auto it : res) {
        cout<<it<<endl;
    }
    cout<<endl;
    
    res = letterCombinations("23");
    for(auto it : res){
        cout<<it<<endl;
    }
    cout<<endl;
    
    vector<int> nums = {1,2,3};
    permute(nums);
    for(auto it : ans) {
        for(auto i : it) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    vector<vector<int>> res1 = subsets(nums);
    for(auto it : res1) {
        for(auto i : it) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    return 0;
}
