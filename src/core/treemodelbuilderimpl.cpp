﻿#include "treemodelbuilderimpl.h"
#include "adtexecutable.h"
#include "adtjsonconverter.h"
#include "treeitem.h"

#include <QJsonArray>

std::unique_ptr<TreeModel> TreeModelBuilderImpl::buildModel(QJsonDocument *document)
{
    if (!document->isArray())
    {
        return nullptr;
    }

    QJsonArray tasksArray = document->array();

    if (tasksArray.isEmpty())
    {
        return nullptr;
    }

    std::unique_ptr<TreeModel> model = std::make_unique<TreeModel>();

    QModelIndex rootIndex = model->parent(QModelIndex());

    TreeItem *rootItem = static_cast<TreeItem *>(rootIndex.internalPointer());

    QMap<QString, TreeItem *> categoriesMap;

    for (int i = 0; i < tasksArray.size(); i++)
    {
        auto task = std::make_unique<ADTExecutable>();

        QJsonObject obj = tasksArray[i].toObject();

        ADTJsonConverter::JSonToObject(*task.get(), &obj);

        auto it = categoriesMap.find(task->m_category);
        if (it == categoriesMap.end())
        {
            TreeItem *categoryItem = new TreeItem(QList<QVariant>{},
                                                  TreeItem::categoryItem,
                                                  rootItem);

            rootItem->appendChild(categoryItem);

            categoriesMap[task->m_category] = categoryItem;

            auto categoryTask = std::make_unique<ADTExecutable>();

            categoryTask->m_name = task->m_category;

            categoryItem->setExecutable(std::move(categoryTask));

            TreeItem *checkItem = new TreeItem(QList<QVariant>{}, TreeItem::checkItem, categoryItem);

            checkItem->setExecutable(std::move(task));

            categoryItem->appendChild(checkItem);
        }
        else
        {
            TreeItem *categoryItem = categoriesMap[task->m_category];

            if (categoryItem)
            {
                TreeItem *checkItem = new TreeItem(QList<QVariant>{},
                                                   TreeItem::checkItem,
                                                   categoryItem);

                categoryItem->appendChild(checkItem);

                checkItem->setExecutable(std::move(task));
            }
        }
    }

    return model;
}