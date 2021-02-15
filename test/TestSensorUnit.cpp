#include "gtest/gtest.h"
#include "SensorUnit.h"
#include "DecSensorLight.h"
#include "DecSensorTemperature.h"
#include "DecSensorWet.h"
#include "DecSensorRadiation.h"

TEST(SensorUnit, scanDetailSuccess)
{
	//arrange
    ISensorUnit *sens = new SensorUnit(255);

	//act
    bool responce = sens->scanDetail();

	//assert
	ASSERT_NE(sens, nullptr);
	ASSERT_EQ(responce, true);
}

TEST(SensorUnit, scanConditionsLightSuccess)
{
    //arrange
    ISensorUnit *sens = new DecSensorLight(new SensorUnit(255));

	//act
    bool responce = sens->scanConditions();

	//assert
	ASSERT_NE(sens, nullptr);
	ASSERT_EQ(responce, true);
    ASSERT_GT(sens->getLightly(), 0);
}

TEST(SensorUnit, scanConditionsWetTemperatureRadiationsSuccess)
{
    //arrange
    ISensorUnit *sens = new DecSensorWet(new DecSensorRadiation(new DecSensorTemperature(new SensorUnit(255))));

	//act
    bool responce = sens->scanConditions();

	//assert
	ASSERT_NE(sens, nullptr);
	ASSERT_EQ(responce, true);
    ASSERT_GT(sens->getRadiation(), 0);
    ASSERT_GT(sens->getTemperature(), -51);
    ASSERT_GT(sens->getWet(), 0);
}

TEST(SensorUnit, setDetailSuccess)
{
    //arrange
    ISensorUnit *sens = new SensorUnit(255);
    Detail det(1, 2, 3, 4);

	//act
    sens->setDetail(det);

	//assert
	ASSERT_NE(sens, nullptr);
	ASSERT_EQ(det.getWidth(), sens->getDetail()->getWidth());
    ASSERT_EQ(det.getHeight(), sens->getDetail()->getHeight());
    ASSERT_EQ(det.getDepth(), sens->getDetail()->getDepth());
    ASSERT_EQ(det.getMass(), sens->getDetail()->getMass());
}
