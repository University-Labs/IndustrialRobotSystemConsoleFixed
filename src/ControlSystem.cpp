#include "ControlSystem.h"

#include <iostream>

using namespace std;


map<string, IRobot*> ControlSystem::getRobotMap()
{
	return robots;
}

/*Добавление робота в систему*/
bool ControlSystem::addRobot(IRobot* newRobot)
{
	//Пытаемся занести нового робота в массив роботов
	if (robots.find(newRobot->getSerialNumber()) == robots.end())
	{
		robots.insert(make_pair(newRobot->getSerialNumber(), newRobot));
		return true;
	}
	else
	{
		return false;
	}
}

/*Удаление робота по заданному серийному номеру*/
bool ControlSystem::eraseRobot(string index)
{
	//Проверка на корректность индекса
	if (robots.find(index) != robots.end())
	{
		robots.erase(index);
		return true;
	}
	else
		return false;
}

/*Получение робота(группы) по заданному серийному номеру*/
IRobot* ControlSystem::getRobot(string index)
{
	//Проверка на корректность индекса
	if (robots.find(index) != robots.end())
		return robots[index];
	else
		return nullptr;
}

string* ControlSystem::executeRobotCommands(string robotNumber)
{
    return robots.find(robotNumber)->second->executeCommands();
}

string* ControlSystem::executeRobotOneCommand(string robotNumber)
{
    return robots.find(robotNumber)->second->executeOneCommand();
}

vector<string* > ControlSystem::executeParallel() { vector<string*> todoVector; return todoVector; }


string* ControlSystem::executeOneToAnother()
{
	//Флаг окончания выполнения команд
	bool flagIsFinish = false;

	//Пока не все команды выполнены
	while (flagIsFinish == false)
	{
		flagIsFinish = true;

		//Проход по каждому роботу и выполнение им одной команды
		for (auto curRobot = robots.begin(); curRobot != robots.end(); ++curRobot)
		{
            if (curRobot->second->isCommandsEmpty() == false && curRobot->second->isRobotOn())
			{
				flagIsFinish = false;
				string* result = executeRobotOneCommand(curRobot->first);
                if(result[0] == "0")
                {
                    result[0] = curRobot->first;
                    return result;
                }
            }
		}
	}
    return nullptr;
}

/*Выполнение команд последовательно*/
string* ControlSystem::executeOnebyone()
{
	//Проход по каждому роботу и выполнение каждым всех имеющихся команд
	for (auto curRobot = robots.begin(); curRobot != robots.end(); ++curRobot)
    {
        string *result = executeRobotCommands(curRobot->first);

        if(result[0] == "0")
        {
            result[0] = curRobot->first;
            return result;
        }

    }
    return nullptr;
}
