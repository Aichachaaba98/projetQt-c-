QT       += core gui  sql network
#QT       += core gui network



TARGET = smtp
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    affichagepr.cpp \
    afficher.cpp \
    ajout.cpp \
    ajoutpr.cpp \
    alerteqt.cpp \
    connexion.cpp \
    dateex.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    modifier.cpp \
    modifierprod.cpp \
    notification.cpp \
    produitray.cpp \
    rayon.cpp \
    smtp.cpp \
    smtpaff.cpp \
    suppprod.cpp \
    suppression.cpp

HEADERS += \
    affichagepr.h \
    afficher.h \
    ajout.h \
    ajoutpr.h \
    alerteqt.h \
    connexion.h \
    dateex.h \
    login.h \
    mainwindow.h \
    modifier.h \
    modifierprod.h \
    notification.h \
    produitray.h \
    rayon.h \
    smtp.h \
    smtpaff.h \
    suppprod.h \
    suppression.h

FORMS += \
    affichagepr.ui \
    afficher.ui \
    ajout.ui \
    ajoutpr.ui \
    alerteqt.ui \
    dateex.ui \
    login.ui \
    mainwindow.ui \
    modifier.ui \
    modifierprod.ui \
    smtpaff.ui \
    suppprod.ui \
    suppression.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    rssource.qrc
