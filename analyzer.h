#ifndef ANALYZER_H
#define ANALYZER_H

#include <string>
#include <vector>
#include <unordered_map>

struct ZoneRecord {
    std::string zone;
    int count;
};

struct SlotRecord {
    std::string zone;
    int hour;
    int count;
};

class TripAnalyzer {
private:
    std::unordered_map<std::string, int> zoneCounts;
    std::unordered_map<std::string, int> slotCounts;
    bool hasData = false;

    std::string trim(const std::string& str);
    int extractHour(const std::string& dateTimeStr);

public:
    void ingestFile(const std::string& filePath);
    std::vector<ZoneRecord> topZones();
    std::vector<SlotRecord> topBusySlots();
    bool empty() const { return !hasData; }
};

#endif
