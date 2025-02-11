/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef TREEITEM_H
#define TREEITEM_H

#include <memory>
#include <QList>
#include <QVariant>

#include <QIcon>

#include "adtexecutable.h"

class ADTExecutable;

class TreeItem
{
public:
    enum ItemType
    {
        categoryItem,
        checkItem
    };

public:
    explicit TreeItem(const QList<QVariant> &data, ItemType type = ItemType::checkItem, TreeItem *parent = 0);

    ~TreeItem();

    void appendChild(TreeItem *child);

    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeItem *parent();
    bool isChecked() const;
    void setChecked(bool state);

    ADTExecutable *getExecutable() const;
    void setExecutable(std::unique_ptr<ADTExecutable> executable);
    ItemType getItemType();
    QIcon getIcon();
    void setIcon(QIcon i);
    void setlocaleForExecutable(QString locale);

private:
    QList<TreeItem *> childItems;

    QList<QVariant> itemData;

    TreeItem *parentItem;

    QIcon icon;

    bool checked;

    ItemType itemType;

    std::unique_ptr<ADTExecutable> task;

private:
    TreeItem(const TreeItem &) = delete;
    TreeItem(TreeItem &&)      = delete;
    TreeItem &operator=(const TreeItem &) = delete;
    TreeItem &operator=(TreeItem &&) = delete;
};

#endif
