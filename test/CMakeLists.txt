if(MSVC)
    add_compile_options(
        $<$<CONFIG:>:/MT> #---------|
        $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
        $<$<CONFIG:Release>:/MT> #--|
    )
endif()

add_executable(
    unit_tests
    TestMovingUnit.cpp
    TestExecutiveUnitHand.cpp
    TestExecutiveUnitSpray.cpp
    TestRobot.cpp
    TestControlSystem.cpp
    TestActivateExecutiveUnit.cpp
    TestDeactivateExecutiveUnit.cpp
    TestMoveMovingUnit.cpp
    TestSetPressureSensor.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    robotsystem
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
