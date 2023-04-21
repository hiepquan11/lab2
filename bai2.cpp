//Tạ Huỳnh Đức MSSV 6251071024
#include <iostream>
#include <algorithm>
using namespace std;

struct Meeting {
    int start, end;
};

// Sắp xếp cuộc họp theo thời điểm kết thúc của cuộc họp
bool cmp(const Meeting& a, const Meeting& b) {
    return a.end < b.end;
}

int main() {
    int n;
    cout<<"Nhap n: ";
    cin >> n;
    Meeting meetings[n];
    for (int i = 0; i < n; i++) {
        cout<<"Cuoc hop thu "<<i+1<<endl;
        cin >> meetings[i].start >> meetings[i].end;
    }

    //Sắp xếp cuộc họp theo thời điểm kết thúc tăng dần
    sort(meetings, meetings + n, cmp);

    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            //Kiểm tra xem cuộc họp j có thể phục vụ cùng cuộc họp i
            if (meetings[j].end <= meetings[i].start) {
                // cập nhật lại dp[i] nếu có thể phục vụ cuộc họp i cùng với cuộc họp trước đó
                dp[i] = max(dp[i], dp[j] + 1);
                break;
            }
        }
        // Nếu không phục vụ được cập nhật lại bằng giá trị tối đa giửa dp[i] và dp[i-1]
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout <<"Phong hop thu: "<< dp[n - 1] << endl;
    return 0;
}
