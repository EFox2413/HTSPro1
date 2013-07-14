TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    read.cpp \
    unscramble.cpp

OTHER_FILES     += wordlist.txt

HEADERS += \
    read.h \
    unscramble.h

FORMS +=

