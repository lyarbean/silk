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

#ifndef HTTPOBJECT_H
#define HTTPOBJECT_H

#include <silkabstracthttpobject.h>

#include <QtCore/QTemporaryFile>
#include <QtCore/QUrl>

class QHttpFileData;

class HttpFileData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName NOTIFY fileNameChanged)
    SILK_ADD_PROPERTY(const QString &, fileName, QString)
    Q_PROPERTY(QString filePath READ filePath NOTIFY filePathChanged)
    SILK_ADD_PROPERTY(const QString &, filePath, QString)
    Q_PROPERTY(QString contentType READ contentType NOTIFY contentTypeChanged)
    SILK_ADD_PROPERTY(const QString &, contentType, QString)
public:
    HttpFileData(QHttpFileData *data, QObject *parent = 0);

    Q_INVOKABLE bool save(const QString &fileName);

signals:
    void fileNameChanged(const QString &fileName);
    void filePathChanged(const QString &filePath);
    void contentTypeChanged(const QString &contentType);

private:
    QTemporaryFile m_file;
};

class HttpObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString remoteAddress READ remoteAddress NOTIFY remoteAddressChanged)
    SILK_ADD_PROPERTY(const QString &, remoteAddress, QString)
    Q_PROPERTY(QString method READ method NOTIFY methodChanged)
    SILK_ADD_PROPERTY(const QString &, method, QString)
    Q_PROPERTY(QString scheme READ scheme NOTIFY schemeChanged)
    SILK_ADD_PROPERTY(const QString &, scheme, QString)
    Q_PROPERTY(QString host READ host NOTIFY hostChanged)
    SILK_ADD_PROPERTY(const QString &, host, QString)
    Q_PROPERTY(int port READ port NOTIFY portChanged)
    SILK_ADD_PROPERTY(int, port, int)
    Q_PROPERTY(QString path READ path NOTIFY pathChanged)
    SILK_ADD_PROPERTY(const QString &, path, QString)
    Q_PROPERTY(QString query READ query NOTIFY queryChanged)
    SILK_ADD_PROPERTY(const QString &, query, QString)
    Q_PROPERTY(QString data READ data NOTIFY dataChanged)
    SILK_ADD_PROPERTY(const QString &, data, QString)
    Q_PROPERTY(QQmlListProperty<HttpFileData> files READ files)
    Q_PROPERTY(QVariant requestHeader READ requestHeader NOTIFY requestHeaderChanged)
    SILK_ADD_PROPERTY(const QVariant &, requestHeader, QVariant)
    Q_PROPERTY(QVariantMap requestCookies READ requestCookies NOTIFY requestCookiesChanged)
    SILK_ADD_PROPERTY(const QVariantMap &, requestCookies, QVariantMap)
    Q_PROPERTY(QString message READ message NOTIFY messageChanged)
    SILK_ADD_PROPERTY(const QString &, message, QString)

    Q_PROPERTY(bool loading READ loading WRITE loading NOTIFY loadingChanged)
    SILK_ADD_PROPERTY(bool, loading, bool)
    Q_PROPERTY(int status READ status WRITE status NOTIFY statusChanged)
    SILK_ADD_PROPERTY(int, status, int)
    Q_PROPERTY(QVariantMap responseHeader READ responseHeader WRITE responseHeader NOTIFY responseHeaderChanged)
    SILK_ADD_PROPERTY(const QVariantMap &, responseHeader, QVariantMap)
    Q_PROPERTY(QVariantMap responseCookies READ responseCookies WRITE responseCookies NOTIFY responseCookiesChanged)
    SILK_ADD_PROPERTY(const QVariantMap &, responseCookies, QVariantMap)
    Q_PROPERTY(bool escapeHTML READ escapeHTML WRITE escapeHTML NOTIFY escapeHTMLChanged)
    SILK_ADD_PROPERTY(bool, escapeHTML, bool)
public:
    explicit HttpObject(QObject *parent = 0);

    QQmlListProperty<HttpFileData> files();
    void setFiles(const QList<HttpFileData *> &files);
signals:
    void remoteAddressChanged(const QString &remoteAddress);
    void methodChanged(const QString &method);
    void schemeChanged(const QString &scheme);
    void hostChanged(const QString &host);
    void portChanged(int port);
    void pathChanged(const QString &path);
    void queryChanged(const QString &query);
    void dataChanged(const QString &data);
    void filesChanged(const QList<HttpFileData *> &files);
    void requestHeaderChanged(const QVariant &requestHeader);
    void requestCookiesChanged(const QVariantMap &requestHeader);
    void messageChanged(const QString &message);
    void loadingChanged(bool loading);
    void statusChanged(int status);
    void responseHeaderChanged(const QVariantMap &responseHeader);
    void responseCookiesChanged(const QVariantMap &responseHeader);
    void escapeHTMLChanged(bool escapeHTML);

private:
    QList<HttpFileData *> m_files;
};

#endif // HTTPOBJECT_H
