#ifndef SOMEONE_H
#define SOMEONE_H
#include <iostream>
#include <string>

    class Someone
    {
        protected:
            std :: string _name;
        public:
            Someone() = delete;
            Someone(const std:: string& name)noexcept;
            virtual ~Someone();
            std :: string get_name() const noexcept;
            void set_name(std:: string name);
            virtual void say_good_bye()const noexcept = 0;
    };

#endif