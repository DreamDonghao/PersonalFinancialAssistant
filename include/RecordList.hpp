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

        void addRecord(Time transactionTime, double amount, std::string purpose, std::string remarks,Time reviseTime) {
            m_records.emplace_back(transactionTime, amount, std::move(purpose), std::move(remarks),reviseTime);
        }

        [[nodiscard]] int getIndexById(const int id) const {
            int index = id;
            while (index < m_records[index].getId()) {
                ++index;
            }
            while (index > m_records[index].getId()) {
                --index;
            }
            return index;
        }

        void removeRecord(const size_t id) {
            size_t index = id;
            while (index < m_records[index].getId()) {
                ++index;
            }
            while (index > m_records[index].getId()) {
                --index;
            }
            m_records.erase(m_records.begin() + static_cast<int>(index));
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
