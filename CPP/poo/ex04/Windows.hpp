#ifndef WINDOWS_H
#define WINDOWS_H
#include <string>
#include <iostream>

    class Windows
    {
        private:
            std :: string title;
        
        public:
            Windows(std :: string title);
            ~Windows();
            std::string get_title() const;
            void set_title(std:: string title);
    };

#endif