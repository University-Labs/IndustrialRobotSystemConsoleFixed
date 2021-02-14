#include "gtest/gtest.h"
#include "Robot.h"
#include "ExecutiveUnitSpray.h"

TEST(Robot, turnOnSuccess)
{
	//arrange
    Robot *r = new Robot("123", new ExecutiveUnitSpray(), new MovingUnit(10, 10, 10), new SensorUnit(255));

	//act
    r->turnOn();

	//assert
	ASSERT_NE(r, nullptr);
	ASSERT_EQ(r->isRobotOn(), true);
}

TEST(Robot, add3CommandsSuccess)
{
	//arrange
    Robot *r = new Robot("123", new ExecutiveUnitSpray(), new MovingUnit(10, 10, 10), new SensorUnit(255));
    int amount = 3;

	//act
    r->setPressureSensor(10);
    r->moveMovingUnit(10, 10, 10, 100);
    r->deactivateExecutiveUnit();

	//assert
	ASSERT_NE(r, nullptr);
	ASSERT_EQ(r->isCommandsEmpty(), false);
    ASSERT_EQ(r->getAmountCommands(), amount);
}

TEST(Robot, eraseCommandSuccess)
{
    //arrange
    Robot *r = new Robot("123", new ExecutiveUnitSpray(), new MovingUnit(10, 10, 10), new SensorUnit(255));
    int amount = 3;

	//act
    r->setPressureSensor(10);
    r->moveMovingUnit(10, 10, 10, 100);
    r->deactivateExecutiveUnit();

	//assert
	ASSERT_NE(r, nullptr);
	ASSERT_EQ(r->isCommandsEmpty(), false);
    ASSERT_EQ(r->getAmountCommands(), amount);
}

TEST(Robot, eraseCommandFailed)
{

}