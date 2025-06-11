//
// Created by donghao on 25-6-9.
//
#include "recordlist.hpp"
#include <ranges>

namespace pfa {

void RecordList::addRecord(Time transactionTime, double amount, std::string purpose, std::string remarks, Time reviseTime) {
    m_records.emplace_back(transactionTime, amount, std::move(purpose), std::move(remarks), reviseTime);
}

Time RecordList::setTransactionTimeById(const size_t id, const Time &transactionTime) {
    return m_records[getIndexById(id)].setTransactionTime(transactionTime);
}

double RecordList::setAmountById(const size_t id, const double amount) {
    return m_records[getIndexById(id)].setAmount(amount);
}

std::string RecordList::setPurposeById(const size_t id, std::string purpose) {
    return m_records[getIndexById(id)].setPurpose(std::move(purpose));
}

std::string RecordList::setRemarkById(const size_t id, std::string remarks) {
    return m_records[getIndexById(id)].setRemarks(std::move(remarks));
}

size_t RecordList::getIndexById(const size_t id) const {
    // 先用最接近id的index开始搜索，确保不会越界
    size_t index = std::min(id, m_records.size() - 1);
    // 向后寻找
    while (index < m_records.size() && id > m_records[index].getId()) {
        ++index;
    }
    // 向前寻找
    while (index > 0 && id < m_records[index].getId()) {
        --index;
    }
    // 返回找到的索引（假设一定存在）
    return index;
}

Record RecordList::removeRecord(const size_t id) {
    const size_t index = getIndexById(id);
    Record removedRecord = m_records[index];
    m_records.erase(m_records.begin() + static_cast<int>(index));
    return removedRecord;
}

size_t RecordList::getRecordsNumber() const {
    return m_records.size();
}

const std::vector<Record> &RecordList::getRecords() const {
    return m_records;
}

std::vector<Record> RecordList::getRevenueRecords() const {
    auto filtered = m_records | std::views::filter([](const Record &record) -> bool {
        return record.getAmount() > 0;
    });
    return {filtered.begin(), filtered.end()};
}

std::vector<Record> RecordList::getExpenditureRecords() const {
    auto filtered = m_records | std::views::filter([](const Record &record) -> bool {
        return record.getAmount() < 0;
    });
    return {filtered.begin(), filtered.end()};
}

} // namespace pfa
