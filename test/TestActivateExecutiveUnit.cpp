#include "gtest/gtest.h"
#include "ActivateExecutiveUnit.h"
#include "ExecutiveUnitSpray.h"


TEST(ActivateExecutiveUnit, doWorkSuccess)
{
    ExecutiveUnit *unit = new ExecutiveUnitSpray();
    unit->setSensor(new SensorUnit(100));
    ActivateExecutiveUnit *command = new ActivateExecutiveUnit(unit, 25);
    string successResponce = "1";

    string* responce = command->doWork();

    ASSERT_NE(unit, nullptr);
    ASSERT_NE(responce, nullptr);
    ASSERT_EQ(responce[0], successResponce);
    ASSERT_EQ(unit->isDeviceActive(), true);
}

TEST(ActivateExecutiveUnit, doWorkFailed)
{
    ExecutiveUnit *unit = new ExecutiveUnitSpray();
    ActivateExecutiveUnit *command = new ActivateExecutiveUnit(unit, 25);
    string failedResponce = "0";

    string* responce = command->doWork();

    ASSERT_NE(unit, nullptr);
    ASSERT_NE(responce, nullptr);
    ASSERT_EQ(responce[0], failedResponce);
    ASSERT_EQ(unit->isDeviceActive(), false);
}
