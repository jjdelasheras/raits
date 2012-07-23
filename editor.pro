SOURCES += \
    main.cpp \
    pdf.cpp \
    mainwindow.cpp \
    viewer.cpp \
    auxfunctions.cpp

HEADERS += \
    pdf.h \
    mainwindow.h \
    viewer.h \
    auxfunctions.h
    
INCLUDEPATH  += /usr/local/include/poppler/qt4
LIBS         += -L/usr/local/lib -lpoppler-qt4
