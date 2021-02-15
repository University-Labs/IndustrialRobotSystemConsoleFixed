#include "DecSensorRadiation.h"

bool DecSensorRadiation::scanConditions()
{
	item->setRadiation(double(rand() % 10) + 0.1);
	return item->scanConditions();
}
