//
// Created by donghao on 25-6-9.
//

#include "user.hpp"

namespace pfa {
    User::User() {
        std::ifstream file("../data/user/user1");
        file >> m_revenue >> m_expenditure;
        while (!file.eof()) {
            int year, month, day, hour, minute, second;
            double amount;
            std::string purpose, remarks;
            int rYear, rMonth, rDay, rHour, rMinute, rSecond;
            file >> year >> month >> day >> hour >> minute >> second;
            file >> amount >> purpose >> remarks;
            file >> rYear >> rMonth >> rDay >> rHour >> rMinute >> rSecond;
            if (file.fail()) break; // 防止读取失败导致死循环
            m_recordList.addRecord(
                Time(year, month, day, hour, minute, second),
                amount, purpose, remarks,
                Time(rYear, rMonth, rDay, rHour, rMinute, rSecond)
            );
        }
        file.close();
    }

    User::~User() {
        std::ofstream file("../data/user/user1");
        file << m_revenue << " " << m_expenditure << "\n";
        const auto &records = m_recordList.getRecords();
        for (size_t i = 0; i < records.size(); ++i) {
            file << records[i].toFileDataString();
            if (i + 1 != records.size()) file << "\n";
        }
        file.close();
    }

    void User::addRecord(const Time &transactionTime, const double amount, std::string purpose, std::string remarks) {
        m_recordList.addRecord(transactionTime, amount, std::move(purpose), std::move(remarks), Time::getNowtime());
        if (amount > 0) {
            m_revenue += amount;
        } else {
            m_expenditure -= amount;
        }
    }

    void User::removeRecord(const size_t id) {
        if (const Record removedRecord = m_recordList.removeRecord(id); removedRecord.getAmount() > 0) {
            m_revenue -= removedRecord.getAmount();
        } else {
            m_expenditure += removedRecord.getAmount();
        }
    }

    void User::setTransactionTimeById(const size_t id, const Time &transactionTime) {
        m_recordList.setTransactionTimeById(id, transactionTime);
    }

    void User::setAmountById(const size_t id, const double amount) {
        if (amount > 0) {
            m_revenue += amount;
        } else {
            m_expenditure -= amount;
        }
        if (const auto oldAmount = m_recordList.setAmountById(id, amount); oldAmount > 0) {
            m_revenue -= oldAmount;
        } else {
            m_expenditure += oldAmount;
        }
    }

    void User::setPurposeById(const size_t id, const std::string &purpose) {
        m_recordList.setPurposeById(id, purpose);
    }

    void User::setRemarkById(const size_t id, const std::string &remarks) {
        m_recordList.setRemarkById(id, remarks);
    }

    size_t User::getIndexById(const int id) const {
        return m_recordList.getIndexById(id);
    }

    double User::getRevenue() const {
        return m_revenue;
    }

    double User::getExpenditure() const {
        return m_expenditure;
    }

    const std::vector<Record> &User::getRecords() const {
        return m_recordList.getRecords();
    }

    std::vector<Record> User::getRevenueRecords() const {
        return m_recordList.getRevenueRecords();
    }

    std::vector<Record> User::getExpenditureRecords() const {
        return m_recordList.getExpenditureRecords();
    }
} // namespace pfa
