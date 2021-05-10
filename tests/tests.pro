include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += INPUTDIR=\\\"$$PWD/input/\\\"

HEADERS +=      \
    ../app/common.h \
    ../app/text.h \
    ../app/_text.h \
    m.h \
    save.h\
    mwef.h\
    rn.h\
    showfirstwords.h



SOURCES +=     main.cpp \
    ../app/save.cpp \
    ../app/load.cpp \
    ../app/create_text.cpp \
    ../app/process_forward.cpp \
    ../app/remove_all.cpp \
    ../app/append_line.cpp \
    ../app/m.cpp \
    ../app/show.cpp\
    ../app/mwef.cpp\
    ../app/rn.cpp\
    ../app/show_first_words.cpp

INCLUDEPATH += ../app

DISTFILES += \
    input/TestSTDOut_output.txt
