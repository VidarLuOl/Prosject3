TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt



SOURCES += \
    test-main.cpp \
    test_legendre.cpp \
    ../main_function/gauss_legendre.cpp \
    ../main_function/integration_function.cpp \

HEADERS += \
    catch.hpp
