#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        vector<int> idx(N);
        for (int i=0;i<N;i++) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int id1,int id2){return nums[id1] < nums[id2];});
        int L = 0, R = N - 1;
        for (L=0;L<N;L++) {
            while(R >= 0 && nums[idx[L]] + nums[idx[R]] > target) {
                R--;
            }
            if (nums[idx[L]] + nums[idx[R]] == target) {
                vector<int> ans(2);
                ans[0] = idx[L];
                ans[1] = idx[R];
                return ans;
            }
        }
    }
}sol;

int main() {
    vector<int> a(3);
    a[0] = 1;
    a[1] = 7;
    a[2] = -1;
    auto ret = sol.twoSum(a,0);
    for (auto t:ret) {
        printf("%d\n",t);
    }
}