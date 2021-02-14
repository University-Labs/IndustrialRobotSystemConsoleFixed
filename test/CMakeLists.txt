add_executable(
    unit_tests
    TestMovingUnit.cpp
    TestExecutiveUnitHand.cpp
    TestExecutiveUnitSpray.cpp
    TestRobot.cpp
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
