SOURCES += \
    main.cpp \
    auxfunctions.cpp \
    mainwindow.cpp \
    imageviewer.cpp \
    pdf.cpp \
    pdfviewer.cpp


HEADERS += \
    auxfunctions.h \
    mainwindow.h \
    imageviewer.h \
    pdf.h \
    pdfviewer.h

    
INCLUDEPATH  += /usr/local/include/poppler/qt4
LIBS         += -L/usr/local/lib -lpoppler-qt4
