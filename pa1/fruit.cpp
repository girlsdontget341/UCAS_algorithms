#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n; //输入水果个数
    priority_queue<int, vector<int>, greater<int>> value;//用最小堆来维护
    for(int i = 0; i < n; i++){
        int v;//输入消耗气力
        cin >> v;
        value.push(v);
    } 

    int energy = 0;//能量
    while (value.size() > 1)
    {
        int a = value.top();//取出最小的两个
        value.pop();
        int b = value.top();
        value.pop();
        energy += a + b;
        value.push(a + b);//放回
    }
    cout << energy << endl; //输出能量
    return 0;  
}