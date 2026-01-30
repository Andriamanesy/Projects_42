#ifndef ENGLISH_H
#define ENGLISH_H
#include <iostream>
#include <string>
#include "Someone.hpp"

class English : public Someone
{
    private:

    public:
        English(const std::string& name) noexcept;
        void say_good_bye() const noexcept override;
};

#endif