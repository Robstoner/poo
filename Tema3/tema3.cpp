#include "headers/inventoryManager.h"
#include "headers/inventoryItem.h"
#include "headers/idGenerator.h"

// link markdown diagrama UML
// https://mermaid.ink/img/pako:eNqdVk1v2zAM_SuEd2mQuMCww9Cs7WErOuTQw9bsZiBQLNoVZkueLHfwsvz3yZ-RbMve5kti8omPIh8ln7xQUPS2XpiQPH9gJJYkDTjop7YAo5-RoyRKyFNjrx4_VW9vbt69B8ljMMwFZ5GQ6YFxdaAsV5IdC8UEh-rFAK7jJiju6NUKKhyPG-854BY9f0WuucudwvQxKX8ii1-UmUmzGFSZ4dias18IY3MoEiEv5mkSndgdUIxIkahFrJHFBgzy_qWmXC3GmTaDUC9oro5R7TXVoHat51nzTns-VUn8T8EfSVjZTlarhaQokR5SkkHUIXOryeqfK-RIoM_VXbs2R_D9e2cQc6dHkuPOxIGxvTdtUowa-_k4XHG1mvX2MVZ2UXYPE-1ZZ_pddRHnumLm6TsEE9mFq6E_CsIVU6XB6d6NYycbWCKsEAo6LndIu_RDga9F1hw6d0tAS2Tz8unwX9rkarh1LIWJ4NXsWJzjHoF4RSkZRbcs4fa37481NoX8W8H2mCfCSYwS3OPIdJR8USXdxEQDwwdjx4RSUwEL4-tuvsRUF21-LGwn7O0LQ30lnIq0USrsx2tzbbbKMGwsGzJ8uyAM7BFjxisRqEaChgs5HTmG3e-6c319P39SOdaN5DCHu9zODSrg3sZLUaaEUX2r1woJPD0zKQbeVv-lRH4PvICfNY4USjyXPPS2EUly3HhFRvWd3H4F9FakTMd_ar8Tqp_zH1H1uAM?type=png)](https://mermaid.live/edit#pako:eNqdVk1v2zAM_SuEd2mQuMCww9Cs7WErOuTQw9bsZiBQLNoVZkueLHfwsvz3yZ-RbMve5kti8omPIh8ln7xQUPS2XpiQPH9gJJYkDTjop7YAo5-RoyRKyFNjrx4_VW9vbt69B8ljMMwFZ5GQ6YFxdaAsV5IdC8UEh-rFAK7jJiju6NUKKhyPG-854BY9f0WuucudwvQxKX8ii1-UmUmzGFSZ4dias18IY3MoEiEv5mkSndgdUIxIkahFrJHFBgzy_qWmXC3GmTaDUC9oro5R7TXVoHat51nzTns-VUn8T8EfSVjZTlarhaQokR5SkkHUIXOryeqfK-RIoM_VXbs2R_D9e2cQc6dHkuPOxIGxvTdtUowa-_k4XHG1mvX2MVZ2UXYPE-1ZZ_pddRHnumLm6TsEE9mFq6E_CsIVU6XB6d6NYycbWCKsEAo6LndIu_RDga9F1hw6d0tAS2Tz8unwX9rkarh1LIWJ4NXsWJzjHoF4RSkZRbcs4fa37481NoX8W8H2mCfCSYwS3OPIdJR8USXdxEQDwwdjx4RSUwEL4-tuvsRUF21-LGwn7O0LQ30lnIq0USrsx2tzbbbKMGwsGzJ8uyAM7BFjxisRqEaChgs5HTmG3e-6c319P39SOdaN5DCHu9zODSrg3sZLUaaEUX2r1woJPD0zKQbeVv-lRH4PvICfNY4USjyXPPS2EUly3HhFRvWd3H4F9FakTMd_ar8Tqp_zH1H1uAM)

int main()
{
    InventoryManager<InventoryItem> manager;

    manager.addItem("T-shirt", "M", "red", 10);
    manager.addItem("T-shirt", "M", "red", 10);
    manager.addItem("T-shirt", "M", "blue", 30);
    manager.addItem("T-shirt", "M", "red", 50);
    manager.addItem("T-shirt", "S", "red", 10);
    manager.addItem("T-shirt", "S", "red", 30);
    manager.addItem("T-shirt", "S", "red", 20);
    manager.addItem("T-shirt", "L", "red", 10);
    manager.addItem("T-shirt", "L", "red", 10);
    manager.addItem("T-shirt", "L", "red", 10);
    int i = 0;
    for (auto &item : manager)
    {
        i++;
        std::cout << i << std::endl;
        item.print();
        std::cout << std::endl;
    }

    std::cout << "Clone: " << std::endl;
    InventoryItem clone = manager.getRandomItem().clone();
    clone.print();
    std::cout << std::endl;

    std::unordered_map<std::string, InventoryItem> items = manager.getItems();

    std::cout << "Items: " << std::endl;
    for (auto &item : items)
    {
        item.second.print();
        std::cout << std::endl;
    }

    std::cout << "Clone item template: " << std::endl;

    manager.cloneItem<InventoryItem>(manager.getRandomItem().getID()).print();

    return 0;

}