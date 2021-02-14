#include "gtest/gtest.h"
#include "MovingUnit.h"

TEST(MovingUnit, moveDeviceSuccess)
{
	//arrange
	MovingUnit* movingDevice = new MovingUnit(10, 10, 10);
	string correctResponce = "1";

	//act
	string* responce = movingDevice->moveDevice(8, 9, 1, 100);

	//assert
	ASSERT_EQ(responce[0], correctResponce);
	ASSERT_EQ(movingDevice->getPositionX(), 8);
	ASSERT_EQ(movingDevice->getPositionY(), 9);
	ASSERT_EQ(movingDevice->getPositionZ(), 1);
}


TEST(MovingUnit, moveDeviceFailed)
{
	//arrange
	MovingUnit* movingDevice = new MovingUnit(10, 10, 10);
	string wrongResponce0 = "0";
	string wrongResponce1 = "Destination point is out of range";
	
	//act
	string* responce = movingDevice->moveDevice(15, 15, 15, 100);

	//assert
	ASSERT_NE(responce, nullptr);
	ASSERT_EQ(responce[0], wrongResponce0);
	ASSERT_EQ(responce[1], wrongResponce1);
	ASSERT_EQ(movingDevice->getPositionX(), 10);
	ASSERT_EQ(movingDevice->getPositionY(), 10);
	ASSERT_EQ(movingDevice->getPositionZ(), 10);
}