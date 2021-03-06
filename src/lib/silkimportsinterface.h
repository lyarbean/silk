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

#ifndef SILKIMPORTSINTERFACE_H
#define SILKIMPORTSINTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QStringList>

#include <QtQml/qqml.h>

class SilkImportsInterface
{
public:
    virtual ~SilkImportsInterface() {}
    virtual void silkRegisterObject() {}
    virtual QString name() const = 0;
    virtual QStringList parents() const { return QStringList(); }

//public slots:
//    virtual void silkRegisterObject(const char *uri, int major, int minor) { Q_UNUSED(uri) Q_UNUSED(major) Q_UNUSED(minor) }

//signals:
//    void registerObject(const char *uri, int major, int minor);
};

#define SilkImportsInterface_iid "me.qtquick.silk.imports"

Q_DECLARE_INTERFACE(SilkImportsInterface, SilkImportsInterface_iid)

#endif // SILKIMPORTSINTERFACE_H
