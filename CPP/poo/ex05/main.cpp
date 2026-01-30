#include "Unit.hpp"
#include "Character.hpp"
#include "Quest.hpp"

#include <iostream>

int main(void)
{
    Unit npc{114, "Forgeron Gibbons"};

    Character c{122, "Jason", 40};

    Quest q{"Tourte au sanglier", "Rapporte 5 morceaux de viande", npc.get_id()};

    q.show();
    return (0);
}