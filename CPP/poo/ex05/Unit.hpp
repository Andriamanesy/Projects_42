#ifndef UNIT_H
#define UNIT_H
#include <iostream>

class Unit
{
    private:
        int _id;
        std :: string _name;
    
    public:
        Unit() = delete;
        Unit(int id, const std :: string& name) noexcept;
        ~Unit();
        int get_id()const noexcept;
        std :: string get_name()const noexcept;
        void set_id(int id);
        void set_name(std::string name);
};
#endif