#ifndef DATE_HPP
#define DATE_HPP

#include <chrono>
#include <string>
#include <iomanip>
#include <sstream>

/**
 * @class Date
 * @brief Manages simulation date and time.
 */
class Date {
public:
    /**
     * @brief Constructs a Date object initialized to the current system time.
     */
    explicit Date();

    /**
     * @brief Sets the simulation date and time.
     * @param year Year component.
     * @param month Month component.
     * @param day Day component.
     * @param hour Hour component (default is 0).
     */
    void setDate(int year, int month, int day, int hour = 0);

    /**
     * @brief Advances the simulation time by a number of hours.
     * @param hours Number of hours to add.
     */
    void addHours(int hours);

    /**
     * @brief Gets the current date as a string.
     * @return Formatted date string.
     */
    std::string getDateString() const;

    /**
     * @brief Stores the current date in a provided string.
     * @param str Reference to the string where the date will be stored.
     */
    void getDateString(std::string& str) const;
private:
    std::chrono::system_clock::time_point current_date; /**< Current date and time. */
};

#endif //DATE_HPP
