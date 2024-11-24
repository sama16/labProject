QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FeedbackDialog.cpp \
    addbookdialog.cpp \
    addseminardialog.cpp \
    adduserdialog.cpp \
    adminList.cpp \
    adminview.cpp \
    book.cpp \
    datahandler.cpp \
    loginview.cpp \
    main.cpp \
    mainwindow.cpp \
    seminar.cpp \
    user.cpp \
    userpanel.cpp \
    userview.cpp \
    welcomeview.cpp

HEADERS += \
    FeedbackDialog.h \
    addbookdialog.h \
    addseminardialog.h \
    adduserdialog.h \
    adminList.h \
    adminview.h \
    book.h \
    datahandler.h \
    loginview.h \
    mainwindow.h \
    seminar.h \
    user.h \
    userpanel.h \
    userview.h \
    welcomeview.h

FORMS += \
    adminview.ui \
    loginview.ui \
    mainwindow.ui \
    welcomeview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    storeBooks.qrc \
    storeSeminar.qrc \
    storeUers.qrc

DISTFILES += \
    books.txt \
    borrowHistory.txt \
    feedback.txt \
    randomID.txt
