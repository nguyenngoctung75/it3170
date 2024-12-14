/*
Một công ty sữa muốn tri ân khách hàng, công ty in vào mỗi hộp sữa tươi một số tự nhiên được lấy từ một danh sách các số tự nhiên bí mật khác nhau cho trước. Người tiêu dùng nếu như thu thập một tập các hộp sữa tươi sao cho các số tự nhiên trong các hộp sữa này khác nhau và tổng của chúng lớn hơn hoặc bằng năm thành lập công ty sẽ được tặng thêm 1 hộp sữa tươi. Hỏi có bao nhiêu cách khác nhau có thể đổi được quà. Hai cách được gọi là khác nhau, nếu tập hợp các số tự nhiên trên các hộp sữa là khác nhau.
Dữ liệu
· Dòng 1: Chứa 1 số nguyên n ( 1 <= n <= 20) số lượng phần tử trong danh sách số tự nhiên bí mật
· Dòng 2: Chứa n số tự nhiên, cách nhau bởi dấu cách, có giá trị nhỏ hơn 2000, là các số tự nhiên bí mật in trên các hộp sữa;
· Dòng 3: Chứa 1 số tự nhiên là năm thành lập công ty, số này có giá trị nhỏ hơn 2023;
Kết quả
· Một số tự nhiên duy nhất là số lượng các cách khác nhau thu thập các tập số trên các hộp sữa tươi có thể đổi được quà.
Ví dụ
Đầu vào
4
1000 1601 100 200
1901
Đầu ra
5
*/

#include <bits/stdc++.h>
using namespace std;

int n, year, cnt = 0;
vector<int> numbers;

void Try(int index, int currentSum) {
    if (index == n) {
        if (currentSum >= year) {
            cnt++;
        }
        return;
    }

    Try(index + 1, currentSum + numbers[index]);
    Try(index + 1, currentSum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    cin >> year;
    Try(0, 0);
    cout << cnt;
}
