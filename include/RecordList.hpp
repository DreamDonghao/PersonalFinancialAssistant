//
// Created by donghao on 25-6-9.
//

#ifndef RECORDLIST_HPP
#define RECORDLIST_HPP
#include <iostream>
#include <record.hpp>
#include <ranges>

namespace pfa {
    class RecordList {
    public:
        RecordList() = default;

        void addRecord(Time transactionTime, double amount, std::string purpose, std::string remarks, Time reviseTime) {
            m_records.emplace_back(transactionTime, amount, std::move(purpose), std::move(remarks), reviseTime);
        }

        Time setTransactionTimeById(const size_t id, const Time &transactionTime) {
            return m_records[getIndexById(id)].setTransactionTime(transactionTime);
        }

        double setAmountById(const size_t id, const double amount) {
            return m_records[getIndexById(id)].setAmount(amount);
        }

        std::string setPurposeById(const size_t id, std::string purpose) {
            return  m_records[getIndexById(id)].setPurpose(std::move(purpose));
        }

        std::string setRemarkById(const size_t id, std::string remarks) {
            return m_records[getIndexById(id)].setRemarks(std::move(remarks));
        }

        [[nodiscard]] size_t getIndexById(const size_t id) const {
            size_t index = std::min(id, m_records.size() - 1);
            while (id > m_records[index].getId()) {
                ++index;
            }
            while (id < m_records[index].getId()) {
                --index;
            }
            return index;
        }

        Record removeRecord(const size_t id) {
            const size_t index = getIndexById(id);
            Record removedRecord = m_records[index];
            m_records.erase(m_records.begin() + static_cast<int>(index));
            return removedRecord;
        }

        [[nodiscard]] size_t getRecordsNumber() const { return m_records.size(); }

        [[nodiscard]] const std::vector<Record> &getRecords() const { return m_records; }

        [[nodiscard]] std::vector<Record> getRevenueRecords() const {
            auto filtered = m_records | std::views::filter([](const Record &record)-> bool {
                return record.getAmount() > 0;
            });
            return {filtered.begin(), filtered.end()};
        }

        [[nodiscard]] std::vector<Record> getExpenditureRecords() const {
            auto filtered = m_records | std::views::filter([](const Record &record)-> bool {
                return record.getAmount() < 0;
            });
            return {filtered.begin(), filtered.end()};
        }

    private:
        std::vector<Record> m_records;
    };
} // pfa

#endif //RECORDLIST_HPP
