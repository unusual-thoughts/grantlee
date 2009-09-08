/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the either Technology Preview License Agreement or the
** Beta Release License Agreement.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef CHAT_H
#define CHAT_H

#include <QtCore/QStringList>
#include <QtDBus/QtDBus>
#include "ui_chatmainwindow.h"
#include "ui_chatsetnickname.h"

#include <grantlee/mutabletemplate.h>

class ChatItem;

namespace Grantlee
{
class Engine;
}

class ChatMainWindow: public QMainWindow, Ui::ChatMainWindow
{
    Q_OBJECT
    QString m_nickname;
    QStringList m_messages;
    QVariantList m_chatItems;
    QVariantHash m_nameColours;
    QStringList m_availableColours;
    Grantlee::MutableTemplate m_template;
public:
    ChatMainWindow();
    ~ChatMainWindow();

    void rebuildHistory();
    void addItem(ChatItem *item);
    void addColour(const QString &nickname, const QString &colour);

signals:
    void message(const QString &nickname, const QString &text);
    void action(const QString &nickname, const QString &text);

private slots:
    void messageSlot(const QString &nickname, const QString &text);
    void actionSlot(const QString &nickname, const QString &text);
    void textChangedSlot(const QString &newText);
    void sendClickedSlot();
    void changeNickname();
    void changeTheme(const QString &themeName);
    void aboutQt();
    void exiting();

private:
  Grantlee::Engine *m_engine;
};

class NicknameDialog: public QDialog, public Ui::NicknameDialog
{
    Q_OBJECT
public:
    NicknameDialog(QWidget *parent = 0);
};

#endif