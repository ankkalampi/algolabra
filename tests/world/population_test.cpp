#include "../../src/world/population.hpp"
#include "../../src/entity/carnivore.hpp"
#include "../../src/entity/herbivore.hpp"
#include "../../src/entity/plant.hpp"
#include "gtest/gtest.h"
#include <array>
#include <cstddef>
#include <gtest/gtest.h>

namespace population_test{

    template <typename T>
    class PopulationTest : public ::testing::Test {
        public:
        // using statements are used for implicit template parameter propagation of T
        using Population = population::Population<T>;
        using Entity = entity::Entity<T>;
        protected:
            // test instances
            Population stackPop; // stack version
            Population* heapPop = nullptr; // heap version

            void SetUp() override {
                heapPop = new Population();
            }

            void TearDown() override {
                delete heapPop;
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

        // searchcontainer should be size()==1 and contain item (1, &entity)
        // check if the pointer points to entity
        EXPECT_EQ(this->stackPop.searchContainer.size(), 1);
        EXPECT_EQ(this->stackPop.searchContainer[entity.id], &entity);
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

        // searchcontainer should be size()==100 
        EXPECT_EQ(this->stackPop.searchContainer.size(), 100);

        // idtoindexmap should find correct index
        EXPECT_EQ(this->stackPop.idToIndexMap[this->stackPop.iterContainer[10].id], 10);

        // searchcontainer should have the correct pointer
        EXPECT_EQ(this->stackPop.searchContainer[this->stackPop.iterContainer[10].id], this->stackPop.searchContainer[11]);

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

        // searchcontainer should be size()==1 and contain item (1, &entity)
        // check if the pointer points to entity
        EXPECT_EQ(this->heapPop->searchContainer.size(), 1);
        EXPECT_EQ(this->heapPop->searchContainer[entity->id], entity);

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

        // searchcontainer should be size()==100 
        EXPECT_EQ(this->heapPop->searchContainer.size(), 100);

        // idtoindexmap should find correct index
        EXPECT_EQ(this->heapPop->idToIndexMap[this->heapPop->iterContainer[10].id], 10);

        // searchcontainer should have the correct pointer
        EXPECT_EQ(this->heapPop->searchContainer[this->heapPop->iterContainer[10].id], this->heapPop->searchContainer[11]);

        for (int i = 0; i < 100; ++i){
            delete entities[i];
        }
    }
    
    
};




