QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dfs_algo_widget.cpp \
    dijkstra_algo_widget.cpp \
    main.cpp \
    main_window.cpp \
    warshall_algo_widget.cpp

HEADERS += \
    dfs_algo_widget.h \
    dijkstra_algo_widget.h \
    main_window.h \
    warshall_algo_widget.h

FORMS += \
    dfs_algo_widget.ui \
    dijkstra_algo_widget.ui \
    main_window.ui \
    warshall_algo_widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resources.qrc
