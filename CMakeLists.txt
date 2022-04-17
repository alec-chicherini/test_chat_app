cmake_minimum_required(VERSION 3.16)
project(test_chat_app)

#C++ init
set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)
#

#system init
message("### system is ${CMAKE_SYSTEM_NAME}")
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	set(LINUX ON)
	set(QT_VERSION_STRING "Qt5")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	set(WINDOWS ON)
	set(QT_VERSION_STRING "Qt6")
endif()
#

#Qt init
function(init_qt)
	find_package(${QT_VERSION_STRING} COMPONENTS Core Widgets Gui REQUIRED )
    set(CMAKE_AUTOMOC ON)
	set(CMAKE_AUTORCC ON)
	set(CMAKE_AUTOUIC ON)
endfunction()

if(WINDOWS)
	set(MESSAGE_GOOD_PATH "\"C:\\Qt\\6.2.2\\msvc2019_64\"")
	option(CMAKE_PREFIX_PATH "Set CMAKE_PREFIX_PATH like: ${MESSAGE_GOOD_PATH}" OFF)
    string(COMPARE EQUAL "${CMAKE_PREFIX_PATH}" "OFF" IS_QT_PATH_EMPTY)
	if(IS_QT_PATH_EMPTY)
                message(FATAL_ERROR "### CMAKE_PREFIX_PATH is empty! Set CMAKE_PREFIX_PATH like: 'cmake . -D CMAKE_PREFIX_PATH=${MESSAGE_GOOD_PATH}'")
                return()
	else()
		message("### -D CMAKE_PREFIX_PATH is ${CMAKE_PREFIX_PATH}")
	endif()
elseif(LINUX)
	message("### If qt5-default installed, build in linux should be ok")
endif(WINDOWS)

init_qt()
#

file(GLOB IN_PROJECT_CPP_FILES
     ${SOURCE_DIR}*.cpp *.h)
message(" ### IN_PROJECT_CPP_FILES = ${IN_PROJECT_CPP_FILES}")
add_executable(${PROJECT_NAME} ${IN_PROJECT_CPP_FILES})
target_link_libraries(${PROJECT_NAME} 
	${QT_VERSION_STRING}::Widgets 
	${QT_VERSION_STRING}::Gui
	${QT_VERSION_STRING}::Core )

#post build actions #1  #2
set(FULL_PATH_TO_EXECUTABLE $<TARGET_FILE:${PROJECT_NAME}>)
set(FULL_PATH_TO_EXECUTABLE_DIR $<TARGET_FILE_DIR:${PROJECT_NAME}>)

#1
if(WINDOWS)
message(" ### Add post build event : windeployqt.exe")
add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E echo "POST_BUILD: Using windeployqt to copy all depends to executable path"
	COMMAND ${CMAKE_PREFIX_PATH}/bin/windeployqt.exe 
			${FULL_PATH_TO_EXECUTABLE}
			--no-quick-import 
		    --no-translations 
)

#2 - windows 
#message(" ### Add post build event : ./${PROJECT_NAME}.exe")
#add_custom_command(
#	TARGET ${PROJECT_NAME} POST_BUILD
#	COMMAND ${CMAKE_COMMAND} -E echo "POST_BUILD:Launch an app after build."
#	COMMAND ${FULL_PATH_TO_EXECUTABLE} 
#)
endif(WINDOWS)

#2 - linux 
#if(LINUX)
#message(" ### Add post build event : ./${PROJECT_NAME}")
#add_custom_command(
#	TARGET ${PROJECT_NAME} POST_BUILD
#	COMMAND ${CMAKE_COMMAND} -E echo "POST_BUILD:Launch an app after build."
#	COMMAND ${FULL_PATH_TO_EXECUTABLE} 
#)
#endif(LINUX)
