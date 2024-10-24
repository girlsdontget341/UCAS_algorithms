#include <iostream>
using namespace std;
//参考https://www.cnblogs.com/qq136155330/p/11729991.html
//打表找规律
const int MOD = 998244353;
long long f[60][60];
long long g[60][60];
void initF(){
    f[1][1] = 1;
    int x = 1;
    for(int i=2;i<=50;i++){
        f[i][1] = f[i-1][1] + x;
        x+=2;
    }
    for(int j=2;j<=50;j++){
        for(int i = j+1;i<=50;i++){
            f[i][j]= ((f[i - 1][j - 1] % MOD * j % MOD )%MOD + (j % MOD * (j - 1) % MOD * g[i - 2][j - 1] % MOD) % MOD) % MOD;
        }
    }
}
void initG(){
    for(int i=1;i<=50;i++){
        g[i][1]=i;
        g[i+1][2]=i;
    }
    for(int j=3;j<=50;j++){
        for(int i=3;i<=50;i++){
            g[i][j]=(g[i-1][j-1]*(j-1))%MOD;
        }
    }
}
long long int jc(int x){
    long long sum =1;
    for(int i=1;i<=x;i++){
        sum = (sum*i)%MOD;
    }
    return sum;
}
int main(){
    int n,k;
    cin>>n>>k;
    initG();
    initF();  
    if(f[n][k]==0){
        cout<<jc(n)<<endl;
    }else{
        cout<<f[n][k]<<endl;
    }
    return 0;
}