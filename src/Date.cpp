#include "Date.hpp"

// Constructor initializes current_date to the current system time
Date::Date() {
    current_date = std::chrono::system_clock::now();
}

// Sets the date to the specified year, month, day, and hour
void Date::setDate(const int year, const int month, const int day, const int hour) {
    std::tm time_info = {};
    time_info.tm_year = year - 1900;
    time_info.tm_mon = month - 1;
    time_info.tm_mday = day;
    time_info.tm_hour = hour;

    const std::time_t time_t_date = std::mktime(&time_info);
    current_date = std::chrono::system_clock::from_time_t(time_t_date);
}

// Adds a number of hours to the current_date
void Date::addHours(const int hours) {
    current_date += std::chrono::hours(hours);
}

// Returns the current date as a formatted string
std::string Date::getDateString() const {
    const std::time_t current_time_t = std::chrono::system_clock::to_time_t(current_date);
    const std::tm *time_info = std::localtime(&current_time_t);

    std::stringstream ss;
    ss << std::put_time(time_info, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

// Stores the current date as a formatted string in the provided string reference
void Date::getDateString(std::string& str) const {
    const std::time_t current_time_t = std::chrono::system_clock::to_time_t(current_date);
    const std::tm *time_info = std::localtime(&current_time_t);

    std::stringstream ss;
    ss << std::put_time(time_info, "%Y-%m-%d %H:%M:%S");
    str = ss.str();
}
