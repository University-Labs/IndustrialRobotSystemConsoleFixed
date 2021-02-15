#include "DecSensorLight.h"
#include <iostream>
#include <sstream>
using namespace std;

bool DecSensorLight::scanConditions()
{
	item->setLightly(double(rand() % 100) + 10);
	return item->scanConditions();
}
