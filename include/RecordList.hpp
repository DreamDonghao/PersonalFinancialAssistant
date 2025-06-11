//
// Created by donghao on 25-6-9.
//

#ifndef RECORDLIST_HPP
#define RECORDLIST_HPP

#include <iostream>
#include <record.hpp>
#include <vector>
#include <string>

namespace pfa {

    /**
     * @class RecordList
     * @brief 交易记录列表管理类
     *
     * 管理多个 Record 对象，支持添加、删除、按ID查找及筛选收入和支出记录。
     */
    class RecordList {
    public:
        /**
         * @brief 默认构造函数，初始化空记录列表
         */
        RecordList() = default;

        /**
         * @brief 添加一条新的交易记录
         *
         * @param transactionTime 交易时间
         * @param amount 交易金额
         * @param purpose 用途/来源
         * @param remarks 备注
         * @param reviseTime 修改时间
         */
        void addRecord(Time transactionTime, double amount, std::string purpose, std::string remarks, Time reviseTime);

        /**
         * @brief 通过记录ID设置交易时间
         *
         * @param id 记录唯一ID
         * @param transactionTime 新交易时间
         * @return 旧交易时间
         */
        Time setTransactionTimeById(const size_t id, const Time &transactionTime);

        /**
         * @brief 通过记录ID设置交易金额
         *
         * @param id 记录唯一ID
         * @param amount 新交易金额
         * @return 旧交易金额
         */
        double setAmountById(const size_t id, const double amount);

        /**
         * @brief 通过记录ID设置用途/来源
         *
         * @param id 记录唯一ID
         * @param purpose 新用途/来源字符串
         * @return 旧用途/来源字符串
         */
        std::string setPurposeById(const size_t id, std::string purpose);

        /**
         * @brief 通过记录ID设置备注
         *
         * @param id 记录唯一ID
         * @param remarks 新备注字符串
         * @return 旧备注字符串
         */
        std::string setRemarkById(const size_t id, std::string remarks);

        /**
         * @brief 通过记录ID获取其在容器中的索引
         *
         * @param id 记录唯一ID
         * @return 该记录在内部容器中的索引
         */
        [[nodiscard]] size_t getIndexById(const size_t id) const;

        /**
         * @brief 删除指定ID的记录
         *
         * 删除记录并返回被删除的 Record 对象副本。
         *
         * @param id 记录唯一ID
         * @return 被删除的 Record 对象
         */
        Record removeRecord(const size_t id);

        /**
         * @brief 获取当前记录数目
         * @return 记录数量
         */
        [[nodiscard]] size_t getRecordsNumber() const;

        /**
         * @brief 获取所有记录的常量引用
         * @return 记录向量常量引用
         */
        [[nodiscard]] const std::vector<Record> &getRecords() const;

        /**
         * @brief 获取所有收入（金额大于0）的记录列表副本
         * @return 收入记录列表副本
         */
        [[nodiscard]] std::vector<Record> getRevenueRecords() const;

        /**
         * @brief 获取所有支出（金额小于0）的记录列表副本
         * @return 支出记录列表副本
         */
        [[nodiscard]] std::vector<Record> getExpenditureRecords() const;

    private:
        std::vector<Record> m_records; ///< 内部存储的交易记录列表
    };

} // namespace pfa

#endif // RECORDLIST_HPP
