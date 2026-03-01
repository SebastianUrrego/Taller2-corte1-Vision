cmake_minimum_required(VERSION 2.8)

project(Taller1Vision)

include_directories("/usr/local/include")
find_package( OpenCV REQUIRED )

#add_executable(${PROJECT_NAME} "punto1.cpp")
#add_executable(${PROJECT_NAME} "punto2.cpp")
#add_executable(${PROJECT_NAME} "punto3.cpp")
#add_executable(${PROJECT_NAME} "punto4.cpp")
#add_executable(${PROJECT_NAME} "punto5.cpp")
#add_executable(${PROJECT_NAME} "punto6.cpp")
add_executable(${PROJECT_NAME} "punto7.cpp")
target_link_libraries( ${PROJECT_NAME}  ${OpenCV_LIBS} )
