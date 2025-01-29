namespace entity{



    struct Animal{
        int id;
        int foodEaten;
        int satiation;
        int age;
        enum AnimalType {Herbivore, Carnivore} type;
    };


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