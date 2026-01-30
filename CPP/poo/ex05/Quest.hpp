#ifndef QUEST_H
#define QUEST_H
#include <iostream>
#include <string>
#include "Quest_status.hpp"

class Quest
{
    private:
        std:: string _name;
        std:: string _description;
        Quest_status _status;

    public:
        Quest() = delete;
        Quest(const std:: string& name, const std::string& description, int unitId) noexcept;
        ~Quest();
        std:: string get_name()const noexcept;
        std:: string get_description()const noexcept;
        void set_name(std:: string name);
        void set_description(std:: string description);
        void show() const noexcept;
};

#endif