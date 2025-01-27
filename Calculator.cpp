#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    #ifdef _WIN32
        system("chcp 65001>nul"); // 设置编码为UTF-8
    #endif
    cout << fixed << setprecision(2);
    cout << "欢迎使用四则计算器！" << endl;
    int num1, num2;
    float _result;
    bool calculate_flag = false;

    // 获取用户输入
    cout << "请输入第一个数字：" << endl;
    if (!(cin >> num1)) {
        cout << "输入错误！请输入一个有效的整数。" << endl;
        return 1;
    }
    cout << "请输入第二个数字：" << endl;
    if (!(cin >> num2)) {
        cout << "输入错误！请输入一个有效的整数。" << endl;
        return 1;
    }

    // 选择运算符
    cout << "请选择运算符（1.加法，2.减法，3.乘法，4.除法）：" << endl;
    cout << "请选择：";
    int _operator;
    if (!(cin >> _operator)) {
        cout << "输入错误！请输入一个有效的运算符编号。" << endl;
        return 1;
    }

    // 进行运算
    switch (_operator) {
        case 1:
            _result = num1 + num2;
            break;
        case 2:
            _result = num1 - num2;
            break;
        case 3:
            _result = num1 * num2;
            break;
        case 4:
            if (num2 == 0) {
                cout << "除数不能为0！" << endl;
                calculate_flag = true;
                break;
            }
            _result = static_cast<float>(num1) / num2;
            break;
        default:
            cout << "输入错误！请选择有效的运算符编号。" << endl;
            return 1;
    }

    // 输出结果
    if (!calculate_flag) {
        cout << "结果为：" << _result << endl;
    }

    cin.ignore(); // 清空输入缓冲区以避免自动回车
    cin.get(); // 等待用户按键

    return 0;
}
