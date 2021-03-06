#ifndef SILKCONFIG_H
#define SILKCONFIG_H

#include "silkglobal.h"

#include <QtCore/QVariant>

class SILK_EXPORT SilkConfig
{
public:
    static void initialize(int argc, char **argv);
    static const QVariantMap &config();
    static QVariant value(const QString &key);
    static const QString &file();

private:
    SilkConfig() {}

    static QVariantMap readConfigFile(const QString &fileName);
    static QVariant value(const QVariant &v, const QString &key);

    static QVariantMap m_config;
    static QString m_file;
};

#endif // SILKCONFIG_H
