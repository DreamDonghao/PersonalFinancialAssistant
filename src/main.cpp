//
// Created by donghao on 25-6-9.
//

#include <algorithm>
#include <main.hpp>
#include <iostream>

int main() {
    pfa::Time::setSeparators({"", "/", "/", " ", ":", ":", ""});
    pfa::User user;
    int input = -1;
    std::unordered_map<int, std::function<void()> > commands;

    auto showRecords = [&](std::vector<pfa::Record> list) {
        int input_f = 0;
        std::unordered_map<int, std::function<void()> > commands_f;
        commands_f[1] = [&]() {
            std::ranges::sort(list, [](const pfa::Record &a, const pfa::Record &b) {
                return a.getAmount() > b.getAmount();
            });
        };
        commands_f[2] = [&]() {
            std::ranges::sort(list, [](const pfa::Record &a, const pfa::Record &b) {
                return a.getAmount() < b.getAmount();
            });
        };
        commands_f[3] = [&]() {
            system("cls");
            std::println("进入删除模式,输入ID选择要删除的账单");
            std::println("0.退出");
            for (const auto &i: list) {
                std::cout << i.toStringShowID() << std::endl;
            }
            int id;
            std::cin >> id;
            if (id != 0) {
                std::println("确定删除该账单吗?");
                std::cout << list[user.getIndexById(id)].toString() << std::endl;
                std::println("1.删除 0.取消");
                std::cin >> input_f;
            }
        };
        do {
            system("cls");
            std::println("收入账单:");
            std::println("1.按交易金额升序");
            std::println("2.按交易金额降序");
            std::println("3.删除模式");
            std::println("0.返回主菜单");
            for (size_t i = 0; i < list.size(); ++i) {
                std::cout << "[" << i + 1 << "]" << list[i].toStringShowID() << std::endl;
            }

            std::cin >> input_f;
            if (input_f == 0) {
                return;
            }
            commands_f[input_f]();
        } while (input_f != 0);
    };

    commands[1] = [&]() {
        showRecords(user.getRecords());
    };

    commands[2] = [&]() {
        showRecords(user.getRevenueRecords());
    };

    commands[3] = [&]() {
        showRecords(user.getExpenditureRecords());
    };

    commands[4] = [&]() {
        system("cls");
        std::println("添加账单,请输入账单数据:");
        std::println("1.开始输入");
        std::println("0.退出");
        int input_f = 0;
        std::cin >> input_f;
        if (input_f == 0) {
            return;
        }
        system("cls");
        int year, month, day, hour, minute, second;
        std::println("请输入交易时间:");
        std::print("年:");
        std::cin >> year;
        std::print("月:");
        std::cin >> month;
        std::print("日:");
        std::cin >> day;
        std::print("时:");
        std::cin >> hour;
        std::print("分:");
        std::cin >> minute;
        std::print("秒:");
        std::cin >> second;
        double amount = 0;
        std::print("请输入交易金额(正数收入,负数支出):");
        std::cin >> amount;
        std::string purpose, remarks;
        std::print("交易类型:");
        std::cin >> purpose;
        std::print("备注:");
        std::cin >> remarks;
        system("cls");
        std::println("输入完成,您确定要添加吗?");
        std::println("1.添加");
        std::println("0.取消");
        std::cout << pfa::Record(pfa::Time(year, month, day, hour, minute, second), amount, purpose, remarks,
                                 pfa::Time::getNowtime()).toString() << "\n";
        std::cin >> input;
        if (input == 1) {
            system("cls");
            user.addRecord(pfa::Time(year, month, day, hour, minute, second), amount, purpose, remarks);
            std::println("添加成功");
            std::cout << pfa::Record(pfa::Time(year, month, day, hour, minute, second), amount, purpose, remarks,
                                     pfa::Time::getNowtime()).toString() << "\n";
            std::println("0.退出");
        } else {
            std::println("您已取消");
            std::println("0.退出");
        }
        std::cin >> input_f;
        if (input_f == 0) {
            return;
        }
    };
    do {
        system("cls");
        std::println("总收入:{:.2f} \n总支出:{:.2f} \n收支差:{:.2f}",
                     user.getRevenue(), user.getExpenditure(), user.getRevenue() - user.getExpenditure());
        std::println("1> 查看所有账单");
        std::println("2> 查看收入账单");
        std::println("3> 查看支出账单");
        std::println("4> 添加账单");
        std::println("0> 退出");
        std::println("请输入功能前的序号:");
        if (std::cin >> input) {
            if (input == 0) {
                break;
            }
            commands[input]();
        } else {
            std::println("输入无效,请重新输入");
        }
    } while (input != 0);
    return 0;
}
