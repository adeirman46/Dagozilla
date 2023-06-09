cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# add another dependencies
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# add executables
add_executable(talker src/pub_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)
add_executable(listener src/sub_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

# install target
install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME})

ament_package()
