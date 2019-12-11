
QT       += core gui network sql printsupport serialport charts \
            multimedia multimediawidgets

QT+= widgets
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
    abonne.cpp \
    aicha.cpp \
    badis.cpp \
    carte.cpp \
    client.cpp \
    connexion.cpp \
    employe.cpp \
    gestion_des_employe.cpp \
    gestion_produits.cpp \
    gestion_reclamation.cpp \
    historique.cpp \
    main.cpp \
    login.cpp \
    notifiacation.cpp \
    notificationaicha.cpp \
    notificationfourat.cpp \
    paie.cpp \
    parkingint.cpp \
    place.cpp \
    pr_commande.cpp \
    produit.cpp \
    produit_livrer.cpp \
    produitray.cpp \
    qcustomplot.cpp \
    rayon.cpp \
    reclamationclass.cpp \
    smtp.cpp \
    statamira.cpp \
    statarbi.cpp \
    statistiques.cpp

HEADERS += \
    abonne.h \
    aicha.h \
    badis.h \
    carte.h \
    client.h \
    connexion.h \
    employe.h \
    gestion_des_employe.h \
    gestion_produits.h \
    gestion_reclamation.h \
    historique.h \
    login.h \
    notifiacation.h \
    notificationaicha.h \
    notificationfourat.h \
    paie.h \
    parkingint.h \
    place.h \
    pr_commande.h \
    produit.h \
    produit_livrer.h \
    produitray.h \
    qcustomplot.h \
    rayon.h \
    reclamationclass.h \
    smtp.h \
    statamira.h \
    statarbi.h \
    statistiques.h

FORMS += \
    aicha.ui \
    badis.ui \
    gestion_des_employe.ui \
    gestion_produits.ui \
    gestion_reclamation.ui \
    login.ui \
    parkingint.ui \
    statamira.ui \
    statarbi.ui \
    statistiques.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressourceeee.qrc

SUBDIRS += \
    ../../RAYON100/RAYON.pro
