#include <bitset>
#include <iostream>
#include <string>

using namespace std;

const int MAX_BITS = 10000;  // 题目中二进制字符串最长为10000位

int main() {
    string s1, s2, op;
    cin >> s1 >> s2 >> op;

    int len1 = s1.size();
    int len2 = s2.size();

    // 初始化bitset（默认全0）
    bitset<MAX_BITS> b1, b2, res;

    // 将s1转换为bitset：s1的第i位（左到右）对应bitset的第（len1-1 -i）位（从0开始）
    for (int i = 0; i < len1; ++i) {
        if (s1[i] == '1') {
            b1.set(len1 - 1 - i);  // 设置对应位为1
        }
    }

    // 将s2转换为bitset，同理
    for (int i = 0; i < len2; ++i) {
        if (s2[i] == '1') {
            b2.set(len2 - 1 - i);
        }
    }

    // 执行位运算
    if (op == "and") {
        res = b1 & b2;
    } else if (op == "or") {
        res = b1 | b2;
    } else if (op == "xor") {
        res = b1 ^ b2;
    }

    // 找到res中最高位的1（从最高位往下遍历）
    int high_bit = -1;
    for (int i = MAX_BITS - 1; i >= 0; --i) {
        if (res.test(i)) {  // 测试该位是否为1
            high_bit = i;
            break;
        }
    }

    // 输出结果：全0则输出"0"，否则输出从最高位到最低位的位
    if (high_bit == -1) {
        cout << "0" << endl;
    } else {
        string result;
        for (int i = high_bit; i >= 0; --i) {  // 从最高位到最低位取位，保证字符串高位在前
            result += (res.test(i) ? '1' : '0');
        }
        cout << result << endl;
    }

    return 0;
}