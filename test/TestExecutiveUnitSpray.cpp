#include "gtest/gtest.h"
#include "ExecutiveUnitSpray.h"

TEST(ExecutiveUnitSpray, checkTypeSuccess)
{
	//arrange
    ExecutiveUnitSpray *eus = new ExecutiveUnitSpray();
    string type = "Executive Unit Spray";

	//act
    string executiveUnitType = eus->getEUnitType();

	//assert
	ASSERT_EQ(executiveUnitType, type);
}

TEST(ExecutiveUnitSpray, activateUnitFailed)
{
	//arrange
    ExecutiveUnitSpray *eus = new ExecutiveUnitSpray();
    string wrongResponce = "0";
	
	//act
    string* responce = eus->activeUnit(10);

	//assert
	ASSERT_NE(responce, nullptr);
	ASSERT_EQ(responce[0], wrongResponce);
	ASSERT_EQ(eus->isDeviceActive(), false);
}

TEST(ExecutiveUnitSpray, activateUnitSuccess)
{
	//arrange
    ExecutiveUnitSpray *eus = new ExecutiveUnitSpray();
    string correctResponce = "1";
    eus->setSensor(new SensorUnit(250));
	
	//act
    string* responce = eus->activeUnit(10);

	//assert
	ASSERT_NE(responce, nullptr);
	ASSERT_EQ(responce[0], correctResponce);
	ASSERT_EQ(eus->isDeviceActive(), true);
}

TEST(ExecutiveUnitSpray, deactiveUnitSuccess)
{
    //arrange
    ExecutiveUnitSpray *eus = new ExecutiveUnitSpray();
    eus->setSensor(new SensorUnit(250));
    eus->activeUnit(25);
	
	//act
    bool isDeactive = eus->deactiveUnit();

	//assert
	ASSERT_EQ(isDeactive, true);
	ASSERT_EQ(eus->isDeviceActive(), false);
}