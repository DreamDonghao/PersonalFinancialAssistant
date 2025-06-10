//
// Created by donghao on 25-6-9.
//

#include "Time.hpp"

#include <sstream>
#include <stdexcept>
#include <chrono>

namespace pfa {
    Time::Time(int year, int month, int day, int hour, int minute, int second)
        : m_year(year), m_month(month), m_day(day),
          m_hour(hour), m_minute(minute), m_second(second) {
    }

    void Time::setYear(const int year) { m_year = year; }
    void Time::setMonth(const int month) { m_month = month; }
    void Time::setDay(const int day) { m_day = day; }
    void Time::setHour(const int hour) { m_hour = hour; }
    void Time::setMinute(const int minute) { m_minute = minute; }
    void Time::setSecond(const int second) { m_second = second; }

    int Time::getYear() const { return m_year; }
    int Time::getMonth() const { return m_month; }
    int Time::getDay() const { return m_day; }
    int Time::getHour() const { return m_hour; }
    int Time::getMinute() const { return m_minute; }
    int Time::getSecond() const { return m_second; }

    auto int_to_str = [](const int x) {
        if (x < 10) {
            return "0" + std::to_string(x);
        } else {
            return std::to_string(x);
        }
    };

    std::string Time::toString() const {
        std::stringstream ss;
        ss << m_separators[0] << int_to_str(m_year) << m_separators[1] << int_to_str(m_month) << m_separators[2]
                << int_to_str(m_day) << m_separators[3] << int_to_str(m_hour) << m_separators[4]
                << int_to_str(m_minute) << m_separators[5] << int_to_str(m_second) << m_separators[6];
        return ss.str();
    }


    Time Time::getNowtime() {
        using namespace std::chrono;

        const zoned_time zt{current_zone(), system_clock::now()};
        const auto local = zt.get_local_time();

        const auto ymd = year_month_day{floor<days>(local)};
        const auto hms = hh_mm_ss{local - floor<days>(local)};

        int year = static_cast<int>(ymd.year());
        int month = static_cast<int>(static_cast<unsigned>(ymd.month()));
        int day = static_cast<int>(static_cast<unsigned>(ymd.day()));
        int hour = hms.hours().count();
        int minute = hms.minutes().count();
        int second = static_cast<int>(hms.seconds().count());

        return {year, month, day, hour, minute, second};
    }

    std::vector<std::string> Time::m_separators{"time", "-", "-", "-", "-", "-", "-", "/"};

    void Time::setSeparators(const std::initializer_list<std::string> &separators) {
        if (separators.size() != 7) {
            throw std::invalid_argument("separators must be 7");
        }
        m_separators = separators;
    }
}