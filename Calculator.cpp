#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#ifdef WIN32
    #include <windows.h>
#endif
using namespace std;

int main() {
    // 设置编码
    #ifdef _WIN32
        system("chcp 65001>nul"); // 设置为UTF-8（65501）
    #endif

    // 输出欢迎信息
    cout << fixed << setprecision(2);
    cout << "欢迎使用四则计算器！" << endl;

    // 定义变量
    double num1, num2;
    double _result;
    bool calculate_flag = false;
    string equation;

    // 获取数字1
    cout << "请输入第一个数字：" << endl;
    while (!(cin >> _result)) {
        cin.clear();
        while (cin.get()!= '\n') {
            continue;
        }
        cout << "输入错误！请输入一个有效的数。" << endl;
        cout << "请输入第一个数字：" << endl;
    }

    // 编辑算式
    equation.append(to_string(_result));

    while (true) {
        // 选择运算符
        cout << "请选择运算符（1.+，2.-，3.×，4.÷）：" << endl;
        cout << "请选择：";
        int _operator;
        while (!(cin >> _operator) || _operator < 1 || _operator > 4) {
            cin.clear();
            while (cin.get() != '\n') {
                continue;
            }
            cout << "输入错误！请输入一个有效的运算符编号。" << endl;
            cout << "请选择：";
        }

        // 输入数字
        cout << "请输入下一个数字：" << endl;
        while (!(cin >> num2)) {
            cin.clear();
            while (cin.get() != '\n') {
                continue;
            }
            cout << "输入错误！请输入一个有效的数。" << endl;
            cout << "请输入下一个数字：" << endl;
        }


        // 进行运算
        switch (_operator) {
            case 1:
                _result = _result + num2;
                // 编辑算式
                equation.append("+" + std::to_string(num2) + "→");
                break;
            case 2:
                _result = _result - num2;
                // 编辑算式
                equation.append("-" + std::to_string(num2) + "→");
                break;
            case 3:
                _result = _result * num2;
                equation.append("×" + std::to_string(num2) + "→");
                break;
            case 4:
                if (num2 == 0) {
                    cout << "除数不能为0！" << endl;
                    calculate_flag = true;
                    continue;
                }
                _result = _result / num2;
                // 编辑算式
                equation.append("÷" + std::to_string(num2) + "→");
                break;
            default:
                // 只有在正常策略失效时才会执行
                cout << "输入错误！请选择有效的运算符编号。" << endl;
                break;
        }

        // 输出目前算式
        cout << "算式：" << equation << _result << endl;

        // 询问是否输出结果
        cout << "是否输出结果？（Y/y表示是）" << endl;
        if (cin.get() == 'Y' || cin.get() == 'y') {
            break;
        }
    }

    // 输出结果
    cout << "结果为：" << _result << endl;

    // 等待退出
    cin.ignore();
    cin.clear();
    while (cin.get() != '\n') {
        continue;
    }

    return 0;
}
