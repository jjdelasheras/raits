SOURCES += \
    main.cpp \
    pdf.cpp \
    auxfunctions.cpp \
    mainwindow.cpp \
    imageviewer.cpp \
    pdfviewer.cpp

HEADERS += \
    pdf.h \
    auxfunctions.h \
    mainwindow.h \
    imageviewer.h \
    pdfviewer.h
    
INCLUDEPATH  += /usr/local/include/poppler/qt4
LIBS         += -L/usr/local/lib -lpoppler-qt4
