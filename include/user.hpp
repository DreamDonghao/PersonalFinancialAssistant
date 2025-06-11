//
// Created by donghao on 25-6-9.
//

#ifndef USER_HPP
#define USER_HPP

#include <fstream>
#include <sstream>
#include <recordlist.hpp>
#include <iostream>
#include <utility>

namespace pfa {

    /**
     * @class User
     * @brief 用户类，管理用户的收支数据及对应的交易记录
     *
     * 负责从文件读取用户收支和交易记录，提供增删改查接口，
     * 并在析构时自动将数据写回文件，实现简单持久化。
     */
    class User {
    public:
        /**
         * @brief 构造函数，从文件加载用户数据和交易记录
         *
         * 文件路径固定为 "../data/user/user1"。
         * 文件第一行为总收入和总支出，之后为多条交易记录数据。
         */
        User();

        /**
         * @brief 析构函数，将用户数据和交易记录保存到文件
         *
         * 文件路径固定为 "../data/user/user1"。
         */
        ~User();

        /**
         * @brief 添加一条新的交易记录
         *
         * 会更新用户总收入或总支出。
         *
         * @param transactionTime 交易时间
         * @param amount 交易金额，正为收入，负为支出
         * @param purpose 用途/来源
         * @param remarks 备注
         */
        void addRecord(const Time &transactionTime, const double amount, std::string purpose, std::string remarks);

        /**
         * @brief 删除指定ID的交易记录
         *
         * 会更新用户总收入或总支出。
         *
         * @param id 交易记录唯一ID
         */
        void removeRecord(const size_t id);

        /**
         * @brief 通过ID修改交易时间
         *
         * @param id 交易记录唯一ID
         * @param transactionTime 新的交易时间
         */
        void setTransactionTimeById(const size_t id, const Time &transactionTime);

        /**
         * @brief 通过ID修改交易金额
         *
         * 会相应调整总收入和总支出。
         *
         * @param id 交易记录唯一ID
         * @param amount 新的交易金额
         */
        void setAmountById(const size_t id, const double amount);

        /**
         * @brief 通过ID修改用途/来源
         *
         * @param id 交易记录唯一ID
         * @param purpose 新用途/来源字符串
         */
        void setPurposeById(const size_t id, const std::string &purpose);

        /**
         * @brief 通过ID修改备注
         *
         * @param id 交易记录唯一ID
         * @param remarks 新备注字符串
         */
        void setRemarkById(const size_t id, const std::string &remarks);

        /**
         * @brief 通过ID获取对应记录在容器中的索引
         *
         * @param id 交易记录唯一ID
         * @return 索引值
         */
        [[nodiscard]] size_t getIndexById(const int id) const;

        /**
         * @brief 获取用户总收入
         * @return 总收入金额
         */
        [[nodiscard]] double getRevenue() const;

        /**
         * @brief 获取用户总支出
         * @return 总支出金额
         */
        [[nodiscard]] double getExpenditure() const;

        /**
         * @brief 获取所有交易记录（常量引用）
         * @return 记录列表常量引用
         */
        [[nodiscard]] const std::vector<Record> &getRecords() const;

        /**
         * @brief 获取所有收入记录的副本
         * @return 收入记录列表
         */
        [[nodiscard]] std::vector<Record> getRevenueRecords() const;

        /**
         * @brief 获取所有支出记录的副本
         * @return 支出记录列表
         */
        [[nodiscard]] std::vector<Record> getExpenditureRecords() const;

    private:
        double m_revenue = 0;        ///< 用户总收入
        double m_expenditure = 0;    ///< 用户总支出
        RecordList m_recordList;     ///< 用户交易记录列表
    };

} // namespace pfa

#endif // USER_HPP
