TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt



SOURCES += \
    test-main.cpp \
    ../main_function/gauss_legendre.cpp \
    ../main_function/gauss_laguerre.cpp \
    ../main_function/integration_function.cpp \
    ../main_function/monte_carlo.cpp \
    test_Monty_Carlo.cpp \
    test_Quadrature.cpp

HEADERS += \
    catch.hpp
