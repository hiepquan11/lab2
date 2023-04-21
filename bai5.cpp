//Tạ Huỳnh Đức MSSV 6251071024
#include <iostream>
#include <cstring>
using namespace std;

int n, W;
int A[50];
int dp[101][51];
int selected[50];

void knapsack() {
    memset(dp, 0, sizeof(dp)); // Khởi tạo tất cả giá trị phần tử trong ma trận dp = 0
    for (int i = 1; i <= n; i++) { // tính toán giá trị trong dp
        for (int j = 1; j <= W; j++) {
            if (A[i-1] > j) {
                dp[j][i] = dp[j][i-1];
            } else {
                dp[j][i] = max(dp[j][i-1], dp[j-A[i-1]][i-1] + A[i-1]);
            }
        }
    }

// Lấy ra các món hàng đã được chọn
    int i = n, j = W;
    while (i > 0 && j > 0) {
        if (dp[j][i] != dp[j][i-1]) {
            selected[i-1] = 1;
            j -= A[i-1];
        }
        i--;
    }
}

int main() {
    cout << "Nhap n va W: ";
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    knapsack();

    cout << "Ket qua: "
    cout << dp[W][n] << endl;

    for (int i = 0; i < n; i++) {
        if (selected[i] == 1) {
            cout << i+1 << " ";
        }
    }

    return 0;
}
