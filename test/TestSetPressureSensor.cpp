#include "gtest/gtest.h"
#include "SetPressureSensor.h"
#include "ExecutiveUnitSpray.h"


TEST(SetPressureSensor, doWorkSuccess)
{
    SetPressureSensor *command = new SetPressureSensor(new SensorUnit(255), 100);
    string successResponce = "1";

    string* responce = command->doWork();

    ASSERT_NE(responce, nullptr);
    ASSERT_EQ(responce[0], successResponce);
}

TEST(SetPressureSensor, doWorkFailed)
{
    SetPressureSensor *command = new SetPressureSensor(nullptr, 100);
    string wrongResponce = "0";

    string* responce = command->doWork();

    ASSERT_NE(responce, nullptr);
    ASSERT_EQ(responce[0], wrongResponce);
}
