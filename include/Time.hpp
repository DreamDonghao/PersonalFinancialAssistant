//
// Created by donghao on 25-6-9.
//

#ifndef TIME_HPP
#define TIME_HPP

#include <string>
#include <vector>
#include <initializer_list>

namespace pfa {
    /**
     * @class Time
     * @brief 表示一个具体的时间点，包含年、月、日、时、分、秒
     *
     * 提供基本的设置、获取时间字段的方法，并支持格式化输出与当前系统时间获取
     */
    class Time {
    public:
        /**
         * @brief 构造一个时间对象。
         * @param year 年份（例如：2025）
         * @param month 月份（1-12）
         * @param day 日期（1-31，取决于月份）
         * @param hour 小时（0-23）
         * @param minute 分钟（0-59）
         * @param second 秒数（0-59）
         */
        Time(int year, int month, int day, int hour, int minute, int second);

        /// @name 设置时间字段
        ///@{

        /**
         * @brief 设置年份。
         * @param year 年份
         */
        void setYear(int year);

        /**
         * @brief 设置月份。
         * @param month 月份（1-12）
         */
        void setMonth(int month);

        /**
         * @brief 设置日期。
         * @param day 日期（1-31）
         */
        void setDay(int day);

        /**
         * @brief 设置小时。
         * @param hour 小时（0-23）
         */
        void setHour(int hour);

        /**
         * @brief 设置分钟。
         * @param minute 分钟（0-59）
         */
        void setMinute(int minute);

        /**
         * @brief 设置秒数。
         * @param second 秒（0-59）
         */
        void setSecond(int second);

        ///@}

        /// @name 获取时间字段
        ///@{

        /**
         * @brief 获取年份
         * @return 年份
         */
        [[nodiscard]] int getYear() const;

        /**
         * @brief 获取月份
         * @return 月份（1-12）
         */
        [[nodiscard]] int getMonth() const;

        /**
         * @brief 获取日期
         * @return 日期（1-31）
         */
        [[nodiscard]] int getDay() const;

        /**
         * @brief 获取小时
         * @return 小时（0-23）
         */
        [[nodiscard]] int getHour() const;

        /**
         * @brief 获取分钟
         * @return 分钟（0-59）
         */
        [[nodiscard]] int getMinute() const;

        /**
         * @brief 获取秒数
         * @return 秒数（0-59）
         */
        [[nodiscard]] int getSecond() const;

        ///@}

        /**
         * @brief 获取格式化后的时间字符串
         * @return 形如 "YYYY-MM-DD HH:MM:SS" 的字符串，分隔符可配置
         */
        [[nodiscard]] std::string toString() const;

        /**
         * @brief 获取当前系统时间
         * @return 当前时间对应的 Time 对象
         */
        static Time getNowtime();

        /**
        * @brief 设置时间字段之间的分隔符
        *
        * 该方法为 const，允许在逻辑 const 上修改分隔符（使用 mutable 成员）
        *
        * @param separators 分隔符列表，按顺序依次应用于年月日和时分秒之间
        */
        static void setSeparators(const std::initializer_list<std::string> &separators);

        static std::vector<std::string> m_separators;
    private:
        int m_year;   ///< 年份
        int m_month;  ///< 月份（1-12）
        int m_day;    ///< 日期（1-31）
        int m_hour;   ///< 小时（0-23）
        int m_minute; ///< 分钟（0-59）
        int m_second; ///< 秒数（0-59）

        /**
         * @brief 用户自定义的时间格式分隔符。
         *
         * 例如：{"/", "-", "-", " ", ":", ":", "/"} 表示格式 "/YYYY-MM-DD HH:MM:SS/"
         */
    };
} // namespace pfa

#endif // TIME_HPP
