#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxRectangle(vector<int> &heights){
    stack<int> s;
    heights.insert(heights.begin(), 0); //防止递增或递减数组
    heights.push_back(0); 
    s.push(0);
    int res = 0;
    for(int i=1; i<heights.size();i++) {
        if(heights[i] >=  heights[s.top()]){
            s.push(i);
        }else{
            while(!s.empty() && heights[i] < heights[s.top()]){
                int mid = s.top();
                s.pop();
                if(!s.empty())
                {
                    int right = i;
                    int left = s.top();
                    int width = right - left - 1;
                    res = max(res, width*heights[mid]);
                }
        }
        s.push(i);
    }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }
    cout<< maxRectangle(heights) << endl;
}