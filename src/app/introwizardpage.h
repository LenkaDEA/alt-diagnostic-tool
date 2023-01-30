/***********************************************************************************************************************
**
** Copyright (C) 2022 BaseALT Ltd. <org@basealt.ru>
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

#ifndef INTROWIZARDPAGE_H
#define INTROWIZARDPAGE_H

#include <QWizardPage>

namespace Ui
{
class IntroWizardPage;
}

class IntroWizardPage : public QWizardPage
{
    Q_OBJECT

public:
    IntroWizardPage(QWidget *parent = nullptr);

private:
    Ui::IntroWizardPage *ui;

private slots:
    void cancelButtonPressed(int currentPage);

private:
    IntroWizardPage(const IntroWizardPage &) = delete;            // copy ctor
    IntroWizardPage(IntroWizardPage &&)      = delete;            // move ctor
    IntroWizardPage &operator=(const IntroWizardPage &) = delete; // copy assignment
    IntroWizardPage &operator=(IntroWizardPage &&) = delete;      // move assignment
};

#endif // INTROWIZARDPAGE_H
