QT += quick

SOURCES += \
        Operator.cpp \
        basetheme.cpp \
        enum.cpp \
        indicatorproperty.cpp \
        main.cpp \
        processcsv.cpp


HEADERS += \
    Operator.h \
    basetheme.h \
    enum.h \
    indicatorproperty.h \
    processcsv.h

resources.files = main.qml
resources.prefix = /$${TARGET}
RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = main.qml


# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

