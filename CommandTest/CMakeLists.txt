cmake_minimum_required(VERSION 3.1.0)
project(commandTest)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5Widgets CONFIG REQUIRED)
set(sources main.cpp
	MainWindow.cpp
	MainWidget.cpp
	ImagesFactory.cpp
	Invoker.cpp
	CommandWidget.cpp
	ContentWidget.cpp
	GlobalSetting.cpp
	CommandButton.cpp
	WidgetAssistant.cpp
	Logger.cpp
	Shifter.cpp
	images.qrc
	)
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
