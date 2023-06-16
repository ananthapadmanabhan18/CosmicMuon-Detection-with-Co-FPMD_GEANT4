cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(Simulation)

option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)

add_executable(sim sim.cc ${sources})
target_link_libraries(sim ${Geant4_LIBRARIES})
add_custom_target(Simulation DEPENDS sim)
