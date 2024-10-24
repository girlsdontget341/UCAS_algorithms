#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//纯暴力 oj超时
const int MOD = 998244353;

int subSize(vector<int> &nums){
    vector<int> sub;
    for(int num:nums){
        auto it = lower_bound(sub.begin(), sub.end(), num);
        if(it != sub.end()){
            *it = num;
        }else{
            sub.push_back(num);
        }
    }
    return sub.size();
}

void insertSort(vector<int> &nums, int k){
    for(int i=1; i<nums.size()&&i<k; i++){
        int j=i;
        while(j>0 && nums[j-1]>nums[j]){
            swap(nums[j], nums[j-1]);
            j--;
        }
    }
}

int  main(){
    int n, k;
    cin >> n >> k;
    int res = 0;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        nums[i] = i+1;
    }
    do{
        vector<int> temp = nums;
        insertSort(temp, k);
        if(subSize(temp) >= n-1){
            res = (res + 1) % MOD;
        }
    }while(next_permutation(nums.begin(), nums.end()));
    cout<<res<<endl;
}