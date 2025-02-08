cmake_minimum_required(VERSION 3.10)
project(SimpleSpice)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DSTYLES_DIR=${CMAKE_SOURCE_DIR}/styles")
#add_definitions(-DSTYLES_DIR="/home/SimpleSpice-master/styles")
#add_definitions(-DSTYLES_DIR="/home/SimpleSpice-master/styles" -DQT_NO_DEBUG -DQT_PRINTSUPPORT_LIB -DQT_SVG_LIB -DQT_CHARTS_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_QML_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB)
#find_package(Qt5 COMPONENTS Widgets PrintSupport Core Gui Qml Svg Charts REQUIRED)
#find_package(Qt5 COMPONENTS PrintSupport Svg Charts Widgets Gui Qml Network Core REQUIRED)

find_package(OpenGL REQUIRED)
find_package(Threads REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/src/calc)
include_directories(${CMAKE_SOURCE_DIR}/src/chart)
include_directories(${CMAKE_SOURCE_DIR}/src/circuit)
include_directories(${CMAKE_SOURCE_DIR}/src/cmds)
include_directories(${CMAKE_SOURCE_DIR}/src/console)
include_directories(${CMAKE_SOURCE_DIR}/src/devices)
include_directories(${CMAKE_SOURCE_DIR}/src/global)
include_directories(${CMAKE_SOURCE_DIR}/src/parser)
#include_directories(${CMAKE_SOURCE_DIR}/src/qss)
include_directories(${CMAKE_SOURCE_DIR}/src/ui)
include_directories(${CMAKE_SOURCE_DIR}/src/utils)
include_directories(${CMAKE_SOURCE_DIR}/src/devices/item)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/win)
#include_directories(/usr/include/eigen3)
include_directories(${CMAKE_SOURCE_DIR}/src/eigen3)
set(SOURCES
${CMAKE_SOURCE_DIR}/src/main.cpp  
${CMAKE_SOURCE_DIR}/src/console/helper.cpp 
${CMAKE_SOURCE_DIR}/src/calc/analyze_ac.cpp
${CMAKE_SOURCE_DIR}/src/calc/analyze_context.cpp
${CMAKE_SOURCE_DIR}/src/calc/analyze_dc.cpp
${CMAKE_SOURCE_DIR}/src/calc/analyze_op.cpp
${CMAKE_SOURCE_DIR}/src/calc/analyze_tran.cpp
${CMAKE_SOURCE_DIR}/src/chart/mychart.cpp
${CMAKE_SOURCE_DIR}/src/chart/plot_context.cpp
${CMAKE_SOURCE_DIR}/src/chart/plot_manager.cpp
${CMAKE_SOURCE_DIR}/src/chart/print_manager.cpp
${CMAKE_SOURCE_DIR}/src/circuit/circuit.cpp
${CMAKE_SOURCE_DIR}/src/console/myconsole.cpp
${CMAKE_SOURCE_DIR}/src/devices/item/capacitor.cpp
${CMAKE_SOURCE_DIR}/src/devices/item/cccs.cpp
${CMAKE_SOURCE_DIR}/src/devices/item/ccvs.cpp
${CMAKE_SOURCE_DIR}/src/devices/item/diode.cpp
${CMAKE_SOURCE_DIR}/src/devices/item/inductor.cpp
${CMAKE_SOURCE_DIR}/src/devices/item/isource.cpp
${CMAKE_SOURCE_DIR}/src/devices/item/mosfet.cpp
${CMAKE_SOURCE_DIR}/src/devices/item/resistor.cpp
${CMAKE_SOURCE_DIR}/src/devices/item/vccs.cpp
${CMAKE_SOURCE_DIR}/src/devices/item/vcvs.cpp
${CMAKE_SOURCE_DIR}/src/devices/item/vsource.cpp
${CMAKE_SOURCE_DIR}/src/devices/nonlinear_device.cpp
${CMAKE_SOURCE_DIR}/src/devices/base_device.cpp
${CMAKE_SOURCE_DIR}/src/devices/dynamic_device.cpp
${CMAKE_SOURCE_DIR}/src/devices/source_device.cpp
${CMAKE_SOURCE_DIR}/src/global/global.cpp 
${CMAKE_SOURCE_DIR}/src/ui/aboutwindow.cpp
${CMAKE_SOURCE_DIR}/src/ui/mymainwindow.cpp
${CMAKE_SOURCE_DIR}/src/parser/parser.cpp
${CMAKE_SOURCE_DIR}/src/parser/scanner.cpp
${CMAKE_SOURCE_DIR}/src/linux/qrc_mainwindow.cpp
${CMAKE_SOURCE_DIR}/src/linux/moc_mychart.cpp
${CMAKE_SOURCE_DIR}/src/linux/moc_aboutwindow.cpp
${CMAKE_SOURCE_DIR}/src/linux/moc_mymainwindow.cpp
${CMAKE_SOURCE_DIR}/src/linux/moc_QtAdvancedStylesheet.cpp
${CMAKE_SOURCE_DIR}/src/qss/QmlStyleUrlInterceptor.cpp
${CMAKE_SOURCE_DIR}/src/qss/QtAdvancedStylesheet.cpp
)


set(QT_PATH /opt/Qt5.12.12/5.12.12/gcc_64)
include_directories(    
    ${QT_PATH}/include
    ${QT_PATH}/include/QtPrintSupport
    ${QT_PATH}/include/QtSvg
    ${QT_PATH}/include/QtCharts
    ${QT_PATH}/include/QtWidgets
    ${QT_PATH}/include/QtGui
    ${QT_PATH}/include/QtQml
    ${QT_PATH}/include/QtNetwork
    ${QT_PATH}/include/QtCore
    #/usr/include/libdrm
    #${QT_PATH}/mkspecs/linux-g++
)


set(QT_SOURCES
${QT_PATH}/lib/libQt5PrintSupport.so 
${QT_PATH}/lib/libQt5Svg.so 
${QT_PATH}/lib/libQt5Charts.so 
${QT_PATH}/lib/libQt5Widgets.so 
${QT_PATH}/lib/libQt5Gui.so 
${QT_PATH}/lib/libQt5Qml.so 
${QT_PATH}/lib/libQt5Network.so 
${QT_PATH}/lib/libQt5Core.so
)

# 为每个Qt库文件添加自定义命令和目�?#foreach(QT_LIB ${QT_SOURCES2})
#    get_filename_component(QT_LIB_NAME ${QT_LIB} NAME)	
#	set(SOURCE_FILE_PATH ${QT_LIB})
#	file(COPY ${SOURCE_FILE_PATH} DESTINATION /home/SimpleSpice-master/install/bin)	
#endforeach()

add_executable(${PROJECT_NAME} ${SOURCES} )
#target_link_libraries(${PROJECT_NAME} Qt5::PrintSupport Qt5::Svg Qt5::Charts Qt5::Widgets Qt5::Gui Qt5::Qml Qt5::Network Qt5::Core)
target_link_libraries(${PROJECT_NAME} ${QT_SOURCES})
#install(TARGETS ${PROJECT_NAME} DESTINATION bin)  