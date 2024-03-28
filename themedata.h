#ifndef THEMEDATA_H
#define THEMEDATA_H

#include "qheaders.h"

class ThemeData
{
public:
    enum ValueType
    {
        rgb,//RGB
        rgba,//RGBA
        itg,//interger
        bol,//bool
        flt,//float
        hd,//head
        tl,//tail
        cmt,//comment
    };
    struct Tag
    {
        ValueType type;
        QString name;
        union
        {
            unsigned int i;
            float f;
        };
        void ReadTag(QByteArray::iterator bg, QByteArray::iterator ed);
        void WriteTag(QByteArray& dat);
    };

    ThemeData();
    bool LoadData(const QString& fileName);
    bool SaveData(const QString& fileName);

    /*
     * do not call or modify it
     */
    template<typename T> void BindOnModified(T* o, void(T::*f)())
    {
        po = reinterpret_cast<void*>(o);
        pf = reinterpret_cast<void(*)(void*)>(f);
    }

    /*
     *used for iterating through tags
     *'for' example:
     *for(const auto& tag:themeData){}
     */
    QVector<Tag>::const_iterator begin() const;
    QVector<Tag>::const_iterator end() const;

    uint size() const;

    //get element by index
    const Tag& at(uint i) const;

    //modify the tag's value by index
    //return true when successfully modified
    bool Modify(int i,float f);
    bool Modify(int i,unsigned int f);


private:
    QVector<Tag> v;
    bool modified;
    void* po = nullptr;
    void(*pf)(void*) = nullptr;
};

#endif // THEMEDATA_H
