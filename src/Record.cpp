//
// Created by donghao on 25-6-9.
//

#include <record.hpp>
#include <sstream>

namespace pfa {
    int Record::count = 1;


    Record::Record(const Time &transactionTime, const double amount, std::string purpose, std::string remarks,
                   const Time &reviseTime)
        : m_id(count++), m_transactionTime(transactionTime), m_amount(amount),
          m_purpose(std::move(purpose)), m_remarks(std::move(remarks)),
          m_reviseTime(reviseTime) {
    }

    Time Record::setTransactionTime(Time transactionTime) {
        m_reviseTime = Time::getNowtime();
        std::swap(m_transactionTime, transactionTime);
        return transactionTime;
    }

    double Record::setAmount(double amount) {
        m_reviseTime = Time::getNowtime();
        std::swap(m_amount, amount);
        return amount;
    }

    std::string Record::setPurpose(std::string purpose) {
        m_reviseTime = Time::getNowtime();
        std::swap(m_purpose, purpose);
        return purpose;
    }

    std::string Record::setRemarks(std::string remarks) {
        m_reviseTime = Time::getNowtime();
        std::swap(m_remarks, remarks);
        return remarks;
    }

    [[nodiscard]] int Record::getId() const { return m_id; }
    [[nodiscard]] const Time &Record::getTransactionTime() const { return m_transactionTime; }
    [[nodiscard]] double Record::getAmount() const { return m_amount; }
    [[nodiscard]] const std::string &Record::getPurpose() const { return m_purpose; }
    [[nodiscard]] const std::string &Record::getRemarks() const { return m_remarks; }
    [[nodiscard]] const Time &Record::getAddedTime() const { return m_reviseTime; }

    [[nodiscard]] std::string Record::toFileDataString() const {
        Time::setSeparators({"", " ", " ", " ", " ", " ", ""});
        std::stringstream ss;
        ss << m_transactionTime.toString()
                << " " << m_amount << " " << m_purpose << " " << m_remarks << " " << m_reviseTime.toString();
        return ss.str();
    }

    [[nodiscard]] std::string Record::toString() const {
        std::stringstream ss;
        ss << (m_amount > 0 ? "[+]" : "[-]") << " " << m_transactionTime.toString()
                << " " << m_amount << " " << m_purpose << " " << m_remarks;
        return ss.str();
    }

    [[nodiscard]] std::string Record::toStringShowID() const {
        std::stringstream ss;
        ss << (m_amount > 0 ? "[+]" : "[-]") << " " "ID" << "[" << m_id << "]" << " " << m_transactionTime.
                toString()
                << " " << m_amount << " " << m_purpose << " " << m_remarks;
        return ss.str();
    }
} // pfa
