#ifndef STATUSCOMMONWIDGET_H
#define STATUSCOMMONWIDGET_H

#include <../core/treeitem.h>
#include <QWidget>

namespace Ui
{
class StatusCommonWidget;
}

class StatusCommonWidget : public QWidget
{
    Q_OBJECT

public:
    StatusCommonWidget(TreeItem *item, QWidget *parent = nullptr);

    ADTExecutable *getExecutable();

    void setText(QString text);

    void setIcon(QIcon &icon);

signals:
    void detailsButtonClicked(StatusCommonWidget *widget);

    void runButtonCLicked(StatusCommonWidget *widget);

private slots:
    void on_detailsPushButton_clicked();

    void on_runPushButton_clicked();

private:
    Ui::StatusCommonWidget *ui;

    TreeItem *treeItem;

private:
    StatusCommonWidget(const StatusCommonWidget &) = delete;
    StatusCommonWidget(StatusCommonWidget &&)      = delete;
    StatusCommonWidget &operator=(const StatusCommonWidget &) = delete;
    StatusCommonWidget &operator=(StatusCommonWidget &&) = delete;
};

#endif // STATUSCOMMONWIDGET_H
