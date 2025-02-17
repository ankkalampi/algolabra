#include "../../src/world/population.hpp"
#include "../../src/entity/carnivore.hpp"
#include "../../src/entity/herbivore.hpp"
#include "../../src/entity/plant.hpp"
#include "gtest/gtest.h"
#include <cstddef>
#include <gtest/gtest.h>

namespace population_test{

    template <typename T>
    class PopulationTest : public ::testing::Test {
        public:
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
};




