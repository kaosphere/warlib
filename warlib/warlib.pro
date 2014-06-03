#-------------------------------------------------
#
# Project created by QtCreator 2014-01-19T14:50:11
#
#-------------------------------------------------

QT       += widgets network printsupport

TARGET = warlib


TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    game/stats/statsmodel.cpp \
    game/model/modelabstract.cpp \
    game/option/optionmodel.cpp \
    warlibinitializer.cpp \
    game/paramsfromUI/paramsfromuimodel.cpp \
    Utilities/QLogger/QLogger.cpp \
    Utilities/DiceRoller/DiceRoller.cpp \ 
    Utilities/PdfExporter/pdfexporter.cpp \
    Utilities/SaveManager/filesaver.cpp \
    core/serializableobject.cpp
	
HEADERS += \
    game/stats/statsmodel.h \
    game/model/modelabstract.h \
    game/option/optionmodel.h \
    warlibinitializer.h \
    defines.h \
    game/paramsfromUI/paramsfromuimodel.h \
    Utilities/QLogger/QLogger.h \
    Utilities/DiceRoller/DiceRoller.h \ 
    Utilities/PdfExporter/pdfexporter.h \
    Utilities/SaveManager/filesaver.h \
    core/serializableobject.h

INSTALLS += target

