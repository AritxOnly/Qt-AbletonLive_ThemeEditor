#ifndef THEMEDATA_H
#define THEMEDATA_H

#include <QFile>
#include <QDebug>

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


        void ReadTag(QByteArray::iterator bg, QByteArray::iterator ed);
        void WriteTag(QByteArray& dat);
    };

    QVector<Tag> v;
    ThemeData();
    bool LoadData(const QByteArray& fileName);
    bool SaveData(const QByteArray& fileName);

};

#endif // THEMEDATA_H
