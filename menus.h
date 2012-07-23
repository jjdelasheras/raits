#ifndef MENUS_H
#define MENUS_H

#include <QWidget>

class MainWindow;
class QMenu;
class QAction;

class Menus : public QWidget
{
    Q_OBJECT

private:
    struct fileMenu {
        QMenu* fileMenu;
        QAction* newAct;
        QAction* openAct;
        QAction* saveAct;
        QAction* saveAsAct;
        QAction* quitAct;

    } fileM;
    struct editMenu {
        QMenu* editMenu;
        QAction* copyAct;
        QAction* cutAct;
        QAction* pasteAct;
        QAction* undoAct;
        QAction* redoAct;
    } editM;
/*
    struct viewMenu {
        QMenu* viewMenu;

    } viewM;

    struct toolsMenu {
        QMenu* toolsMenu;

    } toolsM;

    struct projectMenu {
        QMenu* projectMenu;

    } projectM;

    struct helpMenu {
        QMenu* helpMenu;

    } helpM;
*/
    void createFileMenu();
    void createEditMenu();
/*
    void createViewMenu();
    void createToolsMenu();
    void createProjectMenu();
    void createHelpMenu();
*/
private slots:
    void newFile();
    void open();
    void save();
    void saveAs();
    void copy();
    void cut();
    void paste();
    void undo();
    void redo();

public:
    explicit Menus(MainWindow* parent = 0);
    MainWindow* parentMW() const;
signals:
    
public slots:
    
};

#endif // MENUS_H
