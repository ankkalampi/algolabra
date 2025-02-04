#pragma once

namespace entity{



    struct Animal{
        int id;
        int foodEaten;
        int satiation;
        int age;
        enum AnimalType {Herbivore, Carnivore} type;
    };

};