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

#include "statuscommonwidget.h"
#include "ui_statuscommonwidget.h"

#include <QStyle>

StatusCommonWidget::StatusCommonWidget(TreeItem *item, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StatusCommonWidget)
    , treeItem(item)
{
    ui->setupUi(this);

    QIcon icon = style()->standardIcon(QStyle::SP_ComputerIcon);

    ui->testIconLabel->setPixmap(icon.pixmap(16, 16));

    ui->testNameLabel->setText(treeItem->getExecutable()->m_name.trimmed());
}

StatusCommonWidget::~StatusCommonWidget()
{
    delete ui;
}

ADTExecutable *StatusCommonWidget::getExecutable()
{
    return treeItem->getExecutable();
}

void StatusCommonWidget::setText(QString text)
{
    ui->testNameLabel->setText(text);
}

void StatusCommonWidget::setIcon(QIcon &icon)
{
    ui->testIconLabel->setPixmap(icon.pixmap(QSize(16, 16)));
}

void StatusCommonWidget::setEnabledRunButton(bool isEnabled)
{
    ui->runPushButton->setEnabled(isEnabled);
}

void StatusCommonWidget::on_detailsPushButton_clicked()
{
    emit detailsButtonClicked(this);
}

void StatusCommonWidget::on_runPushButton_clicked()
{
    emit runButtonCLicked(this);
}