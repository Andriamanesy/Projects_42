#ifndef WINDOWS_H
#define WINDOWS_H
#include <string>

    class Windows
    {
        private:
            std :: string title;
            int width;
            int height;
        
        public:
            Windows() = default;
            Windows(std :: string title, int w, int h) noexcept;
            ~Windows();
            void run() const noexcept;
    };

#endif