#include "gtest/gtest.h"
#include "ExecutiveUnitHand.h"

TEST(ExecutiveUnitHand, checkTypeSuccess)
{
	//arrange
    ExecutiveUnitHand *euh = new ExecutiveUnitHand();
    string type = "Executive Unit Hand";

	//act
    string executiveUnitType = euh->getEUnitType();

	//assert
	ASSERT_EQ(executiveUnitType, type);
}

TEST(ExecutiveUnitHand, activateUnitFailed)
{
	//arrange
    ExecutiveUnitHand *euh = new ExecutiveUnitHand();
    string wrongResponce = "0";
	
	//act
    string* responce = euh->activeUnit(10);

	//assert
	ASSERT_NE(responce, nullptr);
	ASSERT_EQ(responce[0], wrongResponce);
	ASSERT_EQ(euh->isDeviceActive(), false);
}

TEST(ExecutiveUnitHand, activateUnitSuccess)
{
	//arrange
    ExecutiveUnitHand *euh = new ExecutiveUnitHand();
    string correctResponce = "1";

    ISensorUnit *sens = new SensorUnit(250);
    sens->setDetail(Detail(1,1,1,1));
	sens->setPressure(100);
    euh->setSensor(sens);
	
	//act
    string* responce = euh->activeUnit(10);

	//assert
	ASSERT_NE(responce, nullptr);
	ASSERT_EQ(responce[0], correctResponce);
	ASSERT_EQ(euh->isDeviceActive(), true);
}

TEST(ExecutiveUnitHand, deactiveUnitSuccess)
{
    //arrange
    ExecutiveUnitHand *euh = new ExecutiveUnitHand();

    ISensorUnit *sens = new SensorUnit(250);
    sens->setDetail(Detail(1,1,1,1));
    euh->setSensor(sens);
    euh->activeUnit(55);
	
	//act
    bool isDeactive = euh->deactiveUnit();

	//assert
	ASSERT_EQ(isDeactive, true);
	ASSERT_EQ(euh->isDeviceActive(), false);
}