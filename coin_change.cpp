#include <iostream>
#include <vector>
using namespace std;

const int MAX_AMOUNT = 7489;
const int COINS[] = {1, 5, 10, 25, 50}; // เหรียญที่ใช้

vector<long long> dp(MAX_AMOUNT + 1, 0);

void precompute() {
    dp[0] = 1; // กรณีที่เงินเป็น 0 มี 1 วิธี (ไม่ใช้เหรียญเลย)

    // วนลูปแต่ละเหรียญ
    for (int coin : COINS) {
        for (int i = coin; i <= MAX_AMOUNT; i++) {
            dp[i] += dp[i - coin]; // วิธีสะสมเหรียญ
        }
    }
}

int main() {
    precompute(); // คำนวณค่าทั้งหมดล่วงหน้า

    int amount;
    while (cin >> amount) {
        cout << dp[amount] << endl;
    }

    return 0;
}
