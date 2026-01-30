#ifndef _CHARACTER_H
#define _CHARACTER_H
#include <string>
#include "Unit.hpp"
#include <iostream>

class Character : public Unit
{
    using Unit::Unit;
    private:
        int _level;
    public:
        Character() = delete;
        Character(int id, const std :: string& name, int level) noexcept;
        ~Character();
        int get_level()const noexcept;
        void set_level(int level);
};

#endif