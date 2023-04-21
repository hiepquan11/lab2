// Tạ Huỳnh Đức MSSV 6251071024
#include <iostream>
using namespace std;

void timDayConTangDaiNhat(int a[], int n) {
    int L[n], prev[n], maxLen = 1, endIdx = 0;
    // duyệt từ i->n
        for (int i = 0; i < n; i++) {
             //dãy con tăng đơn điệu nhất kết thúc tại một vị trí i luôn có độ dài là 1.
            L[i] = 1;
            prev[i] = i;
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i]) {
                    if (L[j] + 1 > L[i]) {
                        L[i] = L[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (L[i] > maxLen) {
                maxLen = L[i];
                endIdx = i;
            }
        }
        int lis[maxLen], idx = maxLen - 1;
        lis[idx] = a[endIdx];
        while (idx > 0) {
            endIdx = prev[endIdx];
            lis[--idx] = a[endIdx];
        }
        for (int i = 0; i < maxLen; i++) {
            cout << lis[i] << " ";
        }
}

int main() {
   int n;
   cout<<"Nhap n: ";
   cin>>n;
   cout<<"Nhap mang";
   int a[n];
   for (int i=0; i<n;i++){
    cin>>a[i];
   }
   timDayConTangDaiNhat(a,n);
    return 0;
}
