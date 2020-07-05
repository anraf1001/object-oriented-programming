#include "globaltime.hpp"
#include "gtest/gtest.h"
#include "store.hpp"
#include "time.hpp"

TEST(StoreTest, shouldCreateShopsWithoutSegFault) {
    auto time = std::make_shared<Time>();
    // Store store(time.get());
}
