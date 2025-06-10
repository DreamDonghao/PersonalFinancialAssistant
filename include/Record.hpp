//
// Created by donghao on 25-6-9.
//

#ifndef RECORD_HPP
#define RECORD_HPP
#include <sstream>
#include <Time.hpp>

namespace pfa {
    class Record {
    public:
        static int count;

        Record(const Time &transactionTime, const double amount, std::string purpose, std::string remarks,
               const Time &reviseTime)
            : m_id(count++), m_transactionTime(transactionTime), m_amount(amount),
              m_purpose(std::move(purpose)), m_remarks(std::move(remarks)),
              m_reviseTime(reviseTime) {
        }

        void setTransactionTime(const Time &transactionTime) {
            m_reviseTime = Time::getNowtime();
            m_transactionTime = transactionTime;
        }

        void setAmount(const int amount) {
            m_reviseTime = Time::getNowtime();
            m_amount = amount;
        }

        void setPurpose(std::string purpose) {
            m_reviseTime = Time::getNowtime();
            m_purpose = std::move(purpose);
        }

        void setRemarks(std::string remarks) {
            m_reviseTime = Time::getNowtime();
            m_remarks = std::move(remarks);
        }

        [[nodiscard]] int getId() const { return m_id; }
        [[nodiscard]] const Time &getTransactionTime() const { return m_transactionTime; }
        [[nodiscard]] double getAmount() const { return m_amount; }
        [[nodiscard]] const std::string &getPurpose() const { return m_purpose; }
        [[nodiscard]] const std::string &getRemarks() const { return m_remarks; }
        [[nodiscard]] const Time &getAddedTime() const { return m_reviseTime; }

        [[nodiscard]] std::string toFileDataString() const {
            Time::setSeparators({"", " ", " ", " ", " ", " ", ""});
            std::stringstream ss;
            ss << m_transactionTime.toString()
                    << " " << m_amount << " " << m_purpose << " " << m_remarks << " " << m_reviseTime.toString();
            return ss.str();
        }

        [[nodiscard]] std::string toString() const {
            std::stringstream ss;
            ss << (m_amount > 0 ? "[+]" : "[-]") << " " << m_transactionTime.toString()
                    << " " << m_amount << " " << m_purpose << " " << m_remarks;
            return ss.str();
        }

        [[nodiscard]] std::string toStringShowID() const {
            std::stringstream ss;
            ss << (m_amount > 0 ? "[+]" : "[-]") << " " "ID"<<"["<<m_id<<"]"<<" "<< m_transactionTime.toString()
                    << " " << m_amount << " " << m_purpose << " " << m_remarks;
            return ss.str();
        }

    private:
        int m_id;
        Time m_transactionTime; ///< 交易时间
        double m_amount;        ///< 交易金额
        std::string m_purpose;  ///< 用途/来源
        std::string m_remarks;  ///< 备注
        Time m_reviseTime;      ///< 修改时间
    };
} // pfa

#endif //RECORD_HPP
