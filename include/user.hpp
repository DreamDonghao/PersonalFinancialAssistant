//
// Created by donghao on 25-6-9.
//

#ifndef USER_HPP
#define USER_HPP
#include <fstream>
#include <sstream>
#include<recordList.hpp>
#include <iostream>
#include <utility>

namespace pfa {
    class User {
    public:
        User() {
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
                m_recordList.addRecord(
                    Time(year, month, day, hour, minute, second),
                    amount, purpose, remarks,
                    Time(rYear, rMonth, rDay, rHour, rMinute, rSecond)
                );
            }
            file.close();
        }

        ~User() {
            std::ofstream file("../data/user/user1");
            file << m_revenue << " " << m_expenditure << "\n";
            for (size_t i = 0; i < m_recordList.getRecords().size()-1; ++i) {
                file << m_recordList.getRecords()[i].toFileDataString() << "\n";
            }
            file<<m_recordList.getRecords().back().toFileDataString();
            file.close();
        }

        void addRecord(const Time &transactionTime, const double amount, std::string purpose, std::string remarks) {
            m_recordList.addRecord(transactionTime, amount, std::move(purpose), std::move(remarks),
                                   Time::getNowtime());
            if (amount>0) {
                m_revenue+=amount;
            }else {
                m_expenditure-=amount;
            }
        }

        void removeRecord(const size_t id) {
            m_recordList.removeRecord(id);
        }

        [[nodiscard]] int getIndexById(const int id) const {
            return m_recordList.getIndexById(id);
        }

        [[nodiscard]] double getRevenue() const { return m_revenue; }

        [[nodiscard]] double getExpenditure() const { return m_expenditure; }

        [[nodiscard]] const std::vector<Record> &getRecords() const {
            return m_recordList.getRecords();
        }

        [[nodiscard]] std::vector<Record> getRevenueRecords() const {
            return m_recordList.getRevenueRecords();
        }

        [[nodiscard]] std::vector<Record> getExpenditureRecords() const {
            return m_recordList.getExpenditureRecords();
        }

    private:
        double m_revenue = 0;
        double m_expenditure = 0;
        RecordList m_recordList;
    };
} // pfa

#endif //USER_HPP
