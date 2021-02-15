#include "DecSensorWet.h"
using namespace std;


bool DecSensorWet::scanConditions()
{
	item->setWet(double(rand() % 100) + 1);
	return item->scanConditions();
}
