#include "Windows.hpp"

int main(void)
{
    Windows app{"Title taloha !!!"};
    std :: cout << app.get_title() << std :: endl;
    app.set_title("Title vaovao !!! Title vaovao !!! Title vaovao !!! Title vaovao !!!");
    std :: cout << app.get_title() << std :: endl;
    return (0);
}