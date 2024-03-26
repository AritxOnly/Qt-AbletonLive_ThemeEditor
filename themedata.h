#ifndef THEMEDATA_H
#define THEMEDATA_H

#include "qheaders.h"
class ThemeData
{
public:
    struct Tag
    {
        enum
        {
            rgb,
            rgba,
            itg,
            bol,
            flt,
            beg,
            end,
        }type;
        QString name;
        union
        {
            unsigned int i;
            float f;
        };


        void ReadTag(QByteArray::iterator iBegin, QByteArray::iterator iEnd);
        void WriteTag(QByteArray& dat);
    };

    QVector<Tag> v;
    ThemeData();
    bool LoadData(const QString& fileName);
    bool SaveData(const QString& fileName);
    bool HasModified();
private:

    bool modified;
};

#endif // THEMEDATA_H
