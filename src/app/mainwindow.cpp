/***********************************************************************************************************************
**
** Copyright (C) 2023 BaseALT Ltd. <org@basealt.ru>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
***********************************************************************************************************************/

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(TreeModel *model, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
    , treeViewModel(model)
    , treeProxyModel(std::make_unique<TreeProxyModel>())
    , runTestWindow(std::make_unique<RunTestsDialog>(treeViewModel))
{
    ui->setupUi(this);
    treeProxyModel->setSourceModel(treeViewModel);
    ui->checkListView->setModel(treeViewModel);

    connect(runTestWindow.get(), &RunTestsDialog::exitPressed, this, &MainWindow::on_exitPushButton_clicked);
    connect(this, &MainWindow::runAllCheckedTests, runTestWindow.get(), &RunTestsDialog::runCheckedTests);

    connect(ui->checkListView->selectionModel(),
            &QItemSelectionModel::selectionChanged,
            this,
            &MainWindow::onSelectionChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitPushButton_clicked()
{
    this->close();
}

void MainWindow::on_runAllPushButton_clicked()
{
    runTestWindow->show();
    emit runAllCheckedTests();
}

void MainWindow::on_browseCheckPushButton_clicked()
{
    runTestWindow->show();
}

void MainWindow::onSelectionChanged(const QItemSelection &newSelection, const QItemSelection &previousSelection)
{
    if (newSelection.isEmpty())
    {
        return;
    }

    QModelIndex currentIndex = newSelection.indexes().at(0);
    TreeItem *currentItem    = static_cast<TreeItem *>(currentIndex.internalPointer());

    if (currentItem)
    {
        runTestWindow->setCategory(currentItem);
    }
}
