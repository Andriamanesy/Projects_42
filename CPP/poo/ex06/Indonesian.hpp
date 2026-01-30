#ifndef INDONESIAN_H
#define INDONESIAN_H
#include <iostream>
#include <string>
#include "Someone.hpp"

class Indonesian : public Someone
{
    private:

    public:
        Indonesian(const std::string& name) noexcept;
        void say_good_bye() const noexcept override;
};

#endif