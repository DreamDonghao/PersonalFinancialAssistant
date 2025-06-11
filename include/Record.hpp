//
// Created by donghao on 25-6-9.
//

#ifndef RECORD_HPP
#define RECORD_HPP


#include <Time.hpp>

namespace pfa {

    /**
     * @class Record
     * @brief 表示一条财务交易记录
     *
     * 包含交易时间、金额、用途、备注及修改时间等信息。
     * 提供对各字段的访问和修改接口，修改时自动更新时间戳。
     */
    class Record {
    public:
        /**
         * @brief 记录对象计数，用于生成唯一ID
         */
        static int count;

        /**
         * @brief 构造一个新的交易记录对象
         *
         * @param transactionTime 交易时间
         * @param amount 交易金额
         * @param purpose 用途或来源描述
         * @param remarks 备注信息
         * @param reviseTime 修改时间
         */
        Record(const Time &transactionTime, const double amount, std::string purpose, std::string remarks,
               const Time &reviseTime);

        /// @name 修改字段接口（修改后更新修改时间）
        /// @{

        /**
         * @brief 设置交易时间
         *
         * 设置后自动更新修改时间为当前时间。
         * @param transactionTime 新的交易时间
         * @return 旧的交易时间
         */
        Time setTransactionTime(Time transactionTime);

        /**
         * @brief 设置交易金额
         *
         * 设置后自动更新修改时间为当前时间。
         * @param amount 新的交易金额
         * @return 旧的交易金额
         */
        double setAmount(double amount);

        /**
         * @brief 设置用途/来源
         *
         * 设置后自动更新修改时间为当前时间。
         * @param purpose 新用途/来源字符串
         * @return 旧的用途/来源字符串
         */
        std::string setPurpose(std::string purpose);

        /**
         * @brief 设置备注信息
         *
         * 设置后自动更新修改时间为当前时间。
         * @param remarks 新备注字符串
         * @return 旧的备注字符串
         */
        std::string setRemarks(std::string remarks);

        /// @}

        /// @name 获取字段接口
        /// @{

        /**
         * @brief 获取记录唯一ID
         * @return 记录ID
         */
        [[nodiscard]] int getId() const;

        /**
         * @brief 获取交易时间
         * @return 交易时间对象的常量引用
         */
        [[nodiscard]] const Time &getTransactionTime() const;

        /**
         * @brief 获取交易金额
         * @return 交易金额
         */
        [[nodiscard]] double getAmount() const;

        /**
         * @brief 获取用途/来源
         * @return 用途/来源字符串的常量引用
         */
        [[nodiscard]] const std::string &getPurpose() const;

        /**
         * @brief 获取备注信息
         * @return 备注字符串的常量引用
         */
        [[nodiscard]] const std::string &getRemarks() const;

        /**
         * @brief 获取修改时间
         * @return 修改时间对象的常量引用
         */
        [[nodiscard]] const Time &getAddedTime() const;

        /// @}

        /**
         * @brief 获取用于文件存储的字符串格式
         *
         * 时间字段之间无分隔符，字段用空格分隔，方便文件解析。
         * @return 适合写入文件的字符串
         */
        [[nodiscard]] std::string toFileDataString() const;

        /**
         * @brief 获取交易记录的字符串表示（不含ID）
         *
         * 格式示例："[+] 2025-06-09 100.0 用途 备注"
         * @return 格式化字符串
         */
        [[nodiscard]] std::string toString() const;

        /**
         * @brief 获取交易记录的字符串表示（含ID）
         *
         * 格式示例："[+] ID[3] 2025-06-09 100.0 用途 备注"
         * @return 格式化字符串
         */
        [[nodiscard]] std::string toStringShowID() const;

    private:
        int m_id;                    ///< 记录唯一ID
        Time m_transactionTime;      ///< 交易时间
        double m_amount;             ///< 交易金额
        std::string m_purpose;       ///< 用途或来源
        std::string m_remarks;       ///< 备注信息
        Time m_reviseTime;           ///< 最后修改时间
    };

} // namespace pfa

#endif // RECORD_HPP
