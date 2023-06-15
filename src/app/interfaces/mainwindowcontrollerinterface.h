#ifndef MAINWINDOWCONTROLLERINTERFACE_H
#define MAINWINDOWCONTROLLERINTERFACE_H

#include "../core/adtexecutable.h"
#include "../core/treeitem.h"

class MainWindowControllerInterface : public QObject
{
    Q_OBJECT
public:
    virtual ~MainWindowControllerInterface();

    virtual void runAllToolsWidget() = 0;

    virtual void chooseToolsWidget() = 0;

    virtual void exitToolsWidget() = 0;

    virtual void changeSelectedTool(TreeItem *item) = 0;

    virtual void runTestsWidget(std::vector<ADTExecutable *> tasks) = 0;

    virtual void backTestsWigdet() = 0;

    virtual void exitTestsWidget() = 0;

    virtual void detailsCurrentTest(ADTExecutable *test) = 0;
};

#endif
