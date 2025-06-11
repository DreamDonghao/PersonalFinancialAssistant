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
     * @brief 表示一个具体的时间点，包含年、月、日、时、分、秒。
     *
     * 提供设置与获取时间字段的接口，支持格式化字符串输出以及从系统时间获取当前时间。
     */
    class Time {
    public:
        /**
         * @brief 构造一个时间对象。
         * @param year 年份（如：2025）
         * @param month 月份（范围：1-12）
         * @param day 日期（范围：1-31，取决于月份）
         * @param hour 小时（范围：0-23）
         * @param minute 分钟（范围：0-59）
         * @param second 秒数（范围：0-59）
         */
        Time(int year, int month, int day, int hour, int minute, int second);

        /// @name 设置时间字段
        /// @{

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
         * @param second 秒数（0-59）
         */
        void setSecond(int second);

        /// @}

        /// @name 获取时间字段
        /// @{

        /**
         * @brief 获取年份。
         * @return 年份
         */
        [[nodiscard]] int getYear() const;

        /**
         * @brief 获取月份。
         * @return 月份（1-12）
         */
        [[nodiscard]] int getMonth() const;

        /**
         * @brief 获取日期。
         * @return 日期（1-31）
         */
        [[nodiscard]] int getDay() const;

        /**
         * @brief 获取小时。
         * @return 小时（0-23）
         */
        [[nodiscard]] int getHour() const;

        /**
         * @brief 获取分钟。
         * @return 分钟（0-59）
         */
        [[nodiscard]] int getMinute() const;

        /**
         * @brief 获取秒数。
         * @return 秒数（0-59）
         */
        [[nodiscard]] int getSecond() const;

        /// @}

        /**
         * @brief 获取格式化后的时间字符串。
         *
         * 格式形如 "YYYY-MM-DD HH:MM:SS"，其中分隔符可通过 @ref setSeparators 配置。
         *
         * @return 格式化时间字符串
         */
        [[nodiscard]] std::string toString() const;

        /**
         * @brief 获取当前系统时间。
         *
         * 调用系统时间 API 获取当前时间并返回对应的 @c Time 对象。
         *
         * @return 当前系统时间
         */
        static Time getNowtime();

        /**
         * @brief 设置格式化输出时各时间字段之间的分隔符。
         *
         * 用于自定义 @ref toString 的输出格式。分隔符按以下顺序应用：
         * 年月之间、月日之间、日时之间、时分之间、分秒之间、字符串末尾。
         *
         * @param separators 分隔符列表，长度应为 6 或 7。
         */
        static void setSeparators(const std::initializer_list<std::string> &separators);

        /**
         * @brief 用户设置的分隔符集合。
         *
         * 示例：{"/", "-", "-", " ", ":", ":", "/"} 会生成 "/YYYY-MM-DD HH:MM:SS/"
         */
        static std::vector<std::string> m_separators;

    private:
        int m_year;   ///< 年份
        int m_month;  ///< 月份（1-12）
        int m_day;    ///< 日期（1-31）
        int m_hour;   ///< 小时（0-23）
        int m_minute; ///< 分钟（0-59）
        int m_second; ///< 秒数（0-59）
    };

} // namespace pfa

#endif // TIME_HPP
