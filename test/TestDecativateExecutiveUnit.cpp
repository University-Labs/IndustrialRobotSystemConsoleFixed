#include "gtest/gtest.h"
#include "DeactivateExecutiveUnit.h"
#include "ExecutiveUnitSpray.h"


TEST(DeactivateExecutiveUnit, doWorkSuccess)
{
    ExecutiveUnit *unit = new ExecutiveUnitSpray();
    unit->setSensor(new SensorUnit(100));
    DeactivateExecutiveUnit *command = new DeactivateExecutiveUnit(unit);
    string successResponce = "1";

    string* responce = command->doWork();

    ASSERT_NE(unit, nullptr);
    ASSERT_NE(responce, nullptr);
    ASSERT_EQ(unit->isDeviceActive(), false);
    ASSERT_EQ(responce[0], successResponce);
}