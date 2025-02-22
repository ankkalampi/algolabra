

#include "../../src/world/population.hpp"
#include "../../src/entity/carnivore.hpp"
#include "../../src/entity/herbivore.hpp"
#include "../../src/entity/plant.hpp"
#include "gtest/gtest.h"
#include <array>
#include <cstddef>
#include <gtest/gtest.h>
#include <vector>


namespace population_test{

    template <typename T>
    class PopulationTest : public ::testing::Test {
        public:
        // using statements are used for implicit template parameter propagation of T
        using Population = population::Population<T>;
        using Entity = entity::Entity<T>;
        protected:
            // test instances

            std::vector<world::Cell*>* cells = new std::vector<world::Cell*>;


            Population stackPop = Population(cells); // stack version
            Population* heapPop = nullptr; // heap version

            void SetUp() override {
                heapPop = new Population(cells);
                
            }

            void TearDown() override {
                delete heapPop;
                delete cells;
                heapPop = nullptr;
            }
    } ;

    // TESTS

    // define types to be tested
    using TestTypes = ::testing::Types<entity::Plant, entity::Carnivore, entity::Herbivore>;
    TYPED_TEST_SUITE(PopulationTest, TestTypes);




    // ADD FUNCTION TESTS

    // test add function (add one entity, stack version)
    TYPED_TEST(PopulationTest, StackAddWorks_OneEntityAdded){
        typename TestFixture::Entity entity = typename TestFixture::Entity(1, 20, 20);
        

        // use the function being tested
        this->stackPop.add(entity);

        // itercontainer should be size()==1
        EXPECT_EQ(this->stackPop.iterContainer.size(), 1);

        // idtoindexmap should be size()==1 and contain item (1, 0)
        EXPECT_EQ(this->stackPop.idToIndexMap.size(), 1);
        EXPECT_EQ(this->stackPop.idToIndexMap[entity.id], 0);

    }

    // test add function (add many entities, stack version)
    TYPED_TEST(PopulationTest, StackAddWorks_ManyEntitiesAdded){
        
        // create 100 entities for testing
        int runningId = 1;
        std::array<typename TestFixture::Entity, 100> entities;
        for (int i=0; i <100; ++i){
            entities[i] = typename TestFixture::Entity(runningId, 20, 20);
            this->stackPop.add(entities[i]);
            runningId++;
        }


        // itercontainer should be size()==100
        EXPECT_EQ(this->stackPop.iterContainer.size(), 100);

        // idtoindexmap should be size()==100 and 
        EXPECT_EQ(this->stackPop.idToIndexMap.size(), 100);

        // idtoindexmap should find correct index
        EXPECT_EQ(this->stackPop.idToIndexMap[this->stackPop.iterContainer[10].id], 10);


    }

    // test add function (add one entity, heap version)
    TYPED_TEST(PopulationTest, HeapAddWorks_OneEntityAdded){

        typename TestFixture::Entity* entity = new typename TestFixture::Entity(1, 20, 20);

        // use the function being tested
        this->heapPop->add(*entity);

        // itercontainer should be size()==1
        EXPECT_EQ(this->heapPop->iterContainer.size(), 1);

        // idtoindexmap should be size()==1 and contain item (1, 0)
        EXPECT_EQ(this->heapPop->idToIndexMap.size(), 1);
        EXPECT_EQ(this->heapPop->idToIndexMap[entity->id], 0);


        // release memory of entity
        delete entity;
    }

    
    // test add function (add many entities, heap version)
    TYPED_TEST(PopulationTest, HeapAddWorks_ManyEntitiesAdded){

        // create 100 entities for testing
        int runningId = 1;
        std::array<typename TestFixture::Entity*, 100> entities;
        for (int i=0; i <100; ++i){
            entities[i] = new typename TestFixture::Entity(runningId, 20, 20);
            this->heapPop->add(*entities[i]);
            runningId++;
        }


        // itercontainer should be size()==100
        EXPECT_EQ(this->heapPop->iterContainer.size(), 100);

        // idtoindexmap should be size()==100 and 
        EXPECT_EQ(this->heapPop->idToIndexMap.size(), 100);

        // idtoindexmap should find correct index
        EXPECT_EQ(this->heapPop->idToIndexMap[this->heapPop->iterContainer[10].id], 10);

        for (int i = 0; i < 100; ++i){
            delete entities[i];
        }
    }

    // REMOVE FUNCTION TESTS

    // test if removal works correctly when one entity is removed (stack version)
    TYPED_TEST(PopulationTest, StackRemoveWorks_RemoveOne){

        // create 100 entities for testing
        int runningId = 1;
        std::array<typename TestFixture::Entity, 100> entities;
        for (int i=0; i <100; ++i){
            entities[i] = typename TestFixture::Entity(runningId, 20, 20);
            this->stackPop.add(entities[i]);
            runningId++;
        }

        this->stackPop.remove(10);

        // containers should be size()==99
        EXPECT_EQ(this->stackPop.iterContainer.size(), 99);
        EXPECT_EQ(this->stackPop.idToIndexMap.size(), 99);

        // check if last entity is swapped to replace the removed entity in itercontainer (id:100)
        EXPECT_EQ(this->stackPop.iterContainer[9].id, 100);

    }

    // test if removal works correctly when several entities are removed 
    // non-consecutively and then more are added (stack version)
    TYPED_TEST(PopulationTest, StackRemoveWorks_RemoveSeveralAndAdd){

        // create 100 entities for testing
        int runningId = 1;
        std::array<typename TestFixture::Entity, 100> entities;
        for (int i=0; i <100; ++i){
            entities[i] = typename TestFixture::Entity(runningId, 20, 20);
            this->stackPop.add(entities[i]);
            runningId++;
        }

        // remove entities from arbitrary positions (16 removals in total)
        this->stackPop.remove(10);  // [09] = 100, [99] = null
        this->stackPop.remove(18);  // [17] = 99, [98] = null
        this->stackPop.remove(12);  // [11] = 98, [97] = null
        this->stackPop.remove(2);   // [1] = 97, [96] = null
        this->stackPop.remove(19);  // [18] = 96, [95] = null
        this->stackPop.remove(57);  // [56] = 95, [94] = null
        this->stackPop.remove(60);  // [59] = 94, [93] = null
        this->stackPop.remove(88);  // [87] = 93, [92] = null
        this->stackPop.remove(42);  // [41] = 92, [91] = null
        this->stackPop.remove(44);  // [43] = 91, [90] = null
        this->stackPop.remove(43);  // [42] = 90, [89] = null
        this->stackPop.remove(90);  // [42] = 89, [88] = null
        this->stackPop.remove(45);  // [44] = 88, [87] = null
        this->stackPop.remove(65);  // [64] = 87, [86] = null
        this->stackPop.remove(66);  // [65] = 86, [85] = null
        this->stackPop.remove(11);  // [10] = 85, [84] = null

        // create 10 new entities and add them
        for (int i=0; i <10; ++i){
            entities[i] = typename TestFixture::Entity(runningId, 20, 20);
            this->stackPop.add(entities[i]);
            runningId++;
        }

        /*
        Last ten should be:
        [84] = 101
        [85] = 102
        [86] = 103
        [87] = 104
        [88] = 105
        [89] = 106
        [90] = 107
        [91] = 108
        [92] = 109
        [93] = 110
        */

        // containers should be size()==99
        EXPECT_EQ(this->stackPop.iterContainer.size(), 94);
        EXPECT_EQ(this->stackPop.idToIndexMap.size(), 94);

        // check if last entity is swapped to replace the removed entity in itercontainer
        // see comments above for explanation of expected values
        EXPECT_EQ(this->stackPop.iterContainer[42].id, 89);
        EXPECT_EQ(this->stackPop.iterContainer[10].id, 85);
        EXPECT_EQ(this->stackPop.iterContainer[1].id, 97);
        EXPECT_EQ(this->stackPop.iterContainer[64].id, 87);
        EXPECT_EQ(this->stackPop.iterContainer[65].id, 86);
        EXPECT_EQ(this->stackPop.iterContainer[84].id, 101);
        EXPECT_EQ(this->stackPop.iterContainer[90].id, 107);
        EXPECT_EQ(this->stackPop.iterContainer[92].id, 109);
        EXPECT_EQ(this->stackPop.iterContainer[93].id, 110);


    }


    // test if removal works correctly when one entity is removed (heap version)
    TYPED_TEST(PopulationTest, HeapRemoveWorks_RemoveOne){

        // create 100 entities for testing
        int runningId = 1;
        std::array<typename TestFixture::Entity*, 100> entities;
        for (int i=0; i <100; ++i){
            entities[i] = new typename TestFixture::Entity(runningId, 20, 20);
            this->heapPop->add(*entities[i]);
            runningId++;
        }

        this->heapPop->remove(10);

        // containers should be size()==99
        EXPECT_EQ(this->heapPop->iterContainer.size(), 99);
        EXPECT_EQ(this->heapPop->idToIndexMap.size(), 99);

        // check if last entity is swapped to replace the removed entity in itercontainer (id:100)
        EXPECT_EQ(this->heapPop->iterContainer[9].id, 100);

        // delete created entities
        for (int i = 0; i < 100; ++i){
            delete entities[i];
        }

    }

    // test if removal works correctly when several entities are removed 
    // non-consecutively and then more are added (heap version)
    TYPED_TEST(PopulationTest, HeapRemoveWorks_RemoveSeveralAndAdd){

        // create 100 entities for testing
        int runningId = 1;
        std::array<typename TestFixture::Entity*, 100> entities;
        for (int i=0; i <100; ++i){
            entities[i] = new typename TestFixture::Entity(runningId, 20, 20);
            this->heapPop->add(*entities[i]);
            runningId++;
        }

        // remove entities from arbitrary positions (16 removals in total)
        this->heapPop->remove(10);  // [09] = 100, [99] = null
        this->heapPop->remove(18);  // [17] = 99, [98] = null
        this->heapPop->remove(12);  // [11] = 98, [97] = null
        this->heapPop->remove(2);   // [1] = 97, [96] = null
        this->heapPop->remove(19);  // [18] = 96, [95] = null
        this->heapPop->remove(57);  // [56] = 95, [94] = null
        this->heapPop->remove(60);  // [59] = 94, [93] = null
        this->heapPop->remove(88);  // [87] = 93, [92] = null
        this->heapPop->remove(42);  // [41] = 92, [91] = null
        this->heapPop->remove(44);  // [43] = 91, [90] = null
        this->heapPop->remove(43);  // [42] = 90, [89] = null
        this->heapPop->remove(90);  // [42] = 89, [88] = null
        this->heapPop->remove(45);  // [44] = 88, [87] = null
        this->heapPop->remove(65);  // [64] = 87, [86] = null
        this->heapPop->remove(66);  // [65] = 86, [85] = null
        this->heapPop->remove(11);  // [10] = 85, [84] = null

        // create 10 new entities and add them
        for (int i=0; i <10; ++i){
            entities[i] = new typename TestFixture::Entity(runningId, 20, 20);
            this->heapPop->add(*entities[i]);
            runningId++;
        }

        /*
        Last ten should be:
        [84] = 101
        [85] = 102
        [86] = 103
        [87] = 104
        [88] = 105
        [89] = 106
        [90] = 107
        [91] = 108
        [92] = 109
        [93] = 110
        */

        // containers should be size()==99
        EXPECT_EQ(this->heapPop->iterContainer.size(), 94);
        EXPECT_EQ(this->heapPop->idToIndexMap.size(), 94);

        // check if last entity is swapped to replace the removed entity in itercontainer
        // see comments above for explanation of expected values
        EXPECT_EQ(this->heapPop->iterContainer[42].id, 89);
        EXPECT_EQ(this->heapPop->iterContainer[10].id, 85);
        EXPECT_EQ(this->heapPop->iterContainer[1].id, 97);
        EXPECT_EQ(this->heapPop->iterContainer[64].id, 87);
        EXPECT_EQ(this->heapPop->iterContainer[65].id, 86);
        EXPECT_EQ(this->heapPop->iterContainer[84].id, 101);
        EXPECT_EQ(this->heapPop->iterContainer[90].id, 107);
        EXPECT_EQ(this->heapPop->iterContainer[92].id, 109);
        EXPECT_EQ(this->heapPop->iterContainer[93].id, 110);

        // delete all created entities
        for (auto entity : entities){
            delete entity;
        }



    }
    
    
};




