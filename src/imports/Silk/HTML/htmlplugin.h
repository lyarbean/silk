/* Copyright (c) 2012 Silk Project.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Silk nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL SILK BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef HTMLPLUGIN_H
#define HTMLPLUGIN_H

#include <QtCore/QDebug>
#include <QtCore/QObject>
#include <QtCore/QtPlugin>
#include <silkimportsinterface.h>

class HtmlPlugin : public QObject, SilkImportsInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "me.qtquick.silk.imports")
    Q_INTERFACES(SilkImportsInterface)
public:
    virtual QString name() const { return QStringLiteral("html"); }
    virtual QStringList parents() const { return QStringList() << QStringLiteral("xml"); }
    virtual void silkRegisterObject() {
        silkRegisterObject("Silk.HTML", 4, 01);
        silkRegisterObject("Silk.HTML", 5, 0);
    }

public slots:
    virtual void silkRegisterObject(const char *uri, int major, int minor) {
        emit registerObject(uri, major, minor);
    }

signals:
    void registerObject(const char *uri, int major, int minor);
};

#endif // HTMLPLUGIN_H
