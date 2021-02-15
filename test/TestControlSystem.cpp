#include "gtest/gtest.h"
#include "ControlSystem.h"
#include "Robot.h"
#include "ExecutiveUnitSpray.h"

TEST(ControlSystem, addRobotSuccess)
{
    //arrange
    ControlSystem sys;
    IRobot* newRobot = new Robot("1", new ExecutiveUnitSpray(), new MovingUnit(10,10,10), new SensorUnit(255));

    //act
    bool insertRes = sys.addRobot(newRobot);

    //assert
    ASSERT_EQ(insertRes, true);
    ASSERT_EQ(sys.getRobotMap().size(), 1);
    ASSERT_EQ(sys.getRobot("1"), newRobot);
}

TEST(ControlSystem, addRobotFailed)
{
    //arrange
    ControlSystem sys;
    IRobot* newRobot = new Robot("1", new ExecutiveUnitSpray(), new MovingUnit(10,10,10), new SensorUnit(255));
    IRobot* anotherRobot = new Robot("1" , new ExecutiveUnitSpray(), new MovingUnit(10,10,10), new SensorUnit(2));

    //act
    sys.addRobot(newRobot);
    bool insertRes = sys.addRobot(anotherRobot);

    //assert
    ASSERT_EQ(insertRes, false);
    ASSERT_EQ(sys.getRobotMap().size(), 1);
    ASSERT_NE(sys.getRobot("1"), anotherRobot);
}

TEST(ControlSystem, eraseRobotSuccess)
{
    //arrange
    ControlSystem sys;
    IRobot* newRobot = new Robot("1", new ExecutiveUnitSpray(), new MovingUnit(10,10,10), new SensorUnit(255));

    //act
    sys.addRobot(newRobot);
    bool eraseRes = sys.eraseRobot("1");

    //assert
    ASSERT_EQ(eraseRes, true);
    ASSERT_EQ(sys.getRobotMap().size(), 0);
}

TEST(ControlSystem, eraseRobotFailed)
{
    //arrange
    ControlSystem sys;
    IRobot* newRobot = new Robot("1", new ExecutiveUnitSpray(), new MovingUnit(10,10,10), new SensorUnit(255));

    //act
    sys.addRobot(newRobot);
    bool eraseRes = sys.eraseRobot("2");

    //assert
    ASSERT_EQ(eraseRes, false);
    ASSERT_NE(sys.getRobotMap().size(), 0);
}

TEST(ControlSystem, executeOnebyoneSuccess)
{
    //arrange
    ControlSystem sys;
    IRobot* newRobot = new Robot("1", new ExecutiveUnitSpray(), new MovingUnit(10,10,10), new SensorUnit(255));
    newRobot->setPressureSensor(255);
    newRobot->turnOn();

    //act
    sys.addRobot(newRobot);
    string *res = sys.executeOnebyone();

    //assert
    ASSERT_EQ(res, nullptr);
    ASSERT_NE(sys.getRobot("1")->isCommandsEmpty(), true);
}

TEST(ControlSystem, executeOneToAnotherSuccess)
{
    //arrange
    ControlSystem sys;
    IRobot* newRobot = new Robot("1", new ExecutiveUnitSpray(), new MovingUnit(10,10,10), new SensorUnit(255));
    newRobot->setPressureSensor(255);
    newRobot->turnOn();

    //act
    sys.addRobot(newRobot);
    string *res = sys.executeOneToAnother();

    //assert
    ASSERT_EQ(res, nullptr);
    ASSERT_NE(sys.getRobot("1")->isCommandsEmpty(), true);
}