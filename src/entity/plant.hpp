#pragma once

namespace entity{
    struct Plant{
        int id;
        int age;
        enum PlantSize {
                        Small,
                        Medium,
                        Big,
                        Huge
                        } size;

        enum PlantSafety {
                            Safe,
                            SlightlyPoisonous,
                            GreatlyPoisonous,
                            Deadly
                            } safety;
    };
};
    
