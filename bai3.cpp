//Tạ Huỳnh Đức MSSV 6251071024
#include<iostream>
#include<algorithm>
using namespace std;

struct Orders{
    int start,end,cost;
};

bool cmp (Orders a, Orders b){
    return a.start < b.start;
}
int main(){
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    Orders orders[n];
    for(int i =0; i<n; i++){
        cin >> orders[i].start >> orders[i].end >> orders[i].cost;    
    }
    sort(orders, orders+n, cmp );

    int dp[n];
    dp[0] = orders[0].cost;

    for(int i=0; i<n;i++){
        int j = i-1;
        while(j>=0 && orders[j].end > orders[i].start){
            j--;
        }
        if(j>=0){
            dp[i] = max(dp[i-1], dp[i]+orders[i].cost);
        }else {
            dp[i] = max(dp[i-1], orders[i].cost);
        }
    }

    cout<<dp[n-1];
    return 0;
}