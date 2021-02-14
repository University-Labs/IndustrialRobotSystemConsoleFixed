add_library(robotsystem "")

target_sources(
    robotsystem
    PRIVATE
        ActivateExecutiveUnit.cpp
        ControlSystem.cpp
        DeactivateExecutiveUnit.cpp
        DecoratorSensorUnit.cpp
        DecSensorLight.cpp
        DecSensorRadiation.cpp
        DecSensorTemperature.cpp
        DecSensorWet.cpp
        Detail.cpp
        EUnitHandCreator.cpp
        EUnitSprayCreator.cpp
        ExecutiveUnitHand.cpp
        ExecutiveUnitSpray.cpp
        FacadeSystem.cpp
        MoveMovingUnit.cpp
        MovingUnit.cpp
        Robot.cpp
        RobotSystem.cpp
        ScanSensorUnit.cpp
        SensorUnit.cpp
        SetPressureSensor.cpp


    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/ActivateExecutiveUnit.h
        ${CMAKE_CURRENT_LIST_DIR}/ControlSystem.h
        ${CMAKE_CURRENT_LIST_DIR}/DeactivateExecutiveUnit.h
        ${CMAKE_CURRENT_LIST_DIR}/DecoratorSensorUnit.h
        ${CMAKE_CURRENT_LIST_DIR}/DecSensorLight.h
        ${CMAKE_CURRENT_LIST_DIR}/DecSensorRadiation.h
        ${CMAKE_CURRENT_LIST_DIR}/DecSensorTemperature.h
        ${CMAKE_CURRENT_LIST_DIR}/DecSensorWet.h
        ${CMAKE_CURRENT_LIST_DIR}/Detail.h
        ${CMAKE_CURRENT_LIST_DIR}/EUnitCreator.h
        ${CMAKE_CURRENT_LIST_DIR}/EUnitHandCreator.h
        ${CMAKE_CURRENT_LIST_DIR}/EUnitSprayCreator.h
        ${CMAKE_CURRENT_LIST_DIR}/ExecutiveUnit.h
        ${CMAKE_CURRENT_LIST_DIR}/ExecutiveUnitHand.h
        ${CMAKE_CURRENT_LIST_DIR}/ExecutiveUnitSpray.h
        ${CMAKE_CURRENT_LIST_DIR}/FacadeSystem.h
        ${CMAKE_CURRENT_LIST_DIR}/IRobot.h
        ${CMAKE_CURRENT_LIST_DIR}/ISensorUnit.h
        ${CMAKE_CURRENT_LIST_DIR}/MoveMovingUnit.h
        ${CMAKE_CURRENT_LIST_DIR}/MovingUnit.h
        ${CMAKE_CURRENT_LIST_DIR}/ProgramUnit.h
        ${CMAKE_CURRENT_LIST_DIR}/Robot.h
        ${CMAKE_CURRENT_LIST_DIR}/RobotSystem.h
        ${CMAKE_CURRENT_LIST_DIR}/ScanSensorUnit.h
        ${CMAKE_CURRENT_LIST_DIR}/SensorUnit.h
        ${CMAKE_CURRENT_LIST_DIR}/SetPressureSensor.h

    )

target_include_directories(
   robotsystem
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
