cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(ParticleGun)

# option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})
# include_directories(${PROJECT_SOURCE_DIR})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)




add_executable(simulation simulation.cc ${sources})    #in the bracctet (name source_code.cc    )
target_link_libraries(simulation ${Geant4_LIBRARIES})
add_custom_target(Simulation DEPENDS simulation)
