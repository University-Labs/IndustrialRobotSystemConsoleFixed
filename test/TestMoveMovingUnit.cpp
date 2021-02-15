#include "gtest/gtest.h"
#include "MoveMovingUnit.h"


TEST(MoveMovingUnit, doWorkSuccess)
{
    MoveMovingUnit *command = new MoveMovingUnit(new MovingUnit(3, 3, 3), 2, 2, 2, 100);
    string successResponce = "1";

    string* responce = command->doWork();

    ASSERT_NE(responce, nullptr);
    ASSERT_EQ(responce[0], successResponce);
}

TEST(MoveMovingUnit, doWorkFailed)
{
    MoveMovingUnit *command = new MoveMovingUnit(new MovingUnit(5, 5, 5), -10, -10, -10, 100);
    string wrongResponce = "0";

    string* responce = command->doWork();

    ASSERT_NE(responce, nullptr);
    ASSERT_EQ(responce[0], wrongResponce);
}
