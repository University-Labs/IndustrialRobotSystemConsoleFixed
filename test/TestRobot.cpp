#include "gtest/gtest.h"
#include "Robot.h"
#include "ExecutiveUnitSpray.h"
#include "ExecutiveUnitHand.h"

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
    int amount = 2;

	//act
    r->setPressureSensor(10);
    r->moveMovingUnit(10, 10, 10, 100);
    r->deactivateExecutiveUnit();

    //удаление команды
    bool successErase = r->undoCommand(1);

	//assert
	ASSERT_NE(r, nullptr);
    ASSERT_EQ(successErase, true);
	ASSERT_EQ(r->isCommandsEmpty(), false);
    ASSERT_EQ(r->getAmountCommands(), amount);
}

TEST(Robot, eraseCommandFailed)
{
    //arrange
    Robot *r = new Robot("123", new ExecutiveUnitSpray(), new MovingUnit(10, 10, 10), new SensorUnit(255));
    int amount = 3;

	//act
    r->setPressureSensor(10);
    r->moveMovingUnit(10, 10, 10, 100);
    r->deactivateExecutiveUnit();

    //удаление команды
    bool failedErase = r->undoCommand(4);

	//assert
	ASSERT_NE(r, nullptr);
    ASSERT_EQ(failedErase, false);
	ASSERT_EQ(r->isCommandsEmpty(), false);
    ASSERT_EQ(r->getAmountCommands(), amount);
}

TEST(Robot, performCommandSuccess)
{
    //arrange
    Robot *r = new Robot("123", new ExecutiveUnitSpray(), new MovingUnit(10, 10, 10), new SensorUnit(255));
    string correctResponce = "1";
    
	//act
    r->setPressureSensor(10);
    r->turnOn();
    string *responce = r->executeOneCommand();

	//assert
	ASSERT_NE(r, nullptr);
    ASSERT_NE(responce, nullptr);
    ASSERT_EQ(responce[0], correctResponce);
	ASSERT_EQ(r->isCommandsEmpty(), true);
}

TEST(Robot, performCommandFailed)
{
    //arrange
    Robot *r = new Robot("123", new ExecutiveUnitHand(), new MovingUnit(10, 10, 10), new SensorUnit(255));
    string wrongResponce = "0";

	//act
    r->activateExecutiveUnit(5);
    r->turnOn();
    string *responce = r->executeOneCommand();

	//assert
	ASSERT_NE(r, nullptr);
    ASSERT_NE(responce, nullptr);
    ASSERT_EQ(responce[0], wrongResponce);
	ASSERT_EQ(r->isCommandsEmpty(), false);
}