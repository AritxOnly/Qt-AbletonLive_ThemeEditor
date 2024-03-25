#include "themedata.h"




void ThemeData::Tag::ReadTag(QByteArray::iterator bg, QByteArray::iterator ed)
{
    if(*(ed-1)=='/')
    {
        ed = bg;
        while(*(++ed)!=' ');
        name.resize(ed-bg);
        std::copy(bg,ed,name.begin());

        while(*(bg++)!='"');
        ed=bg;
        while(*(++ed)!='"');

        QString str;str.resize(ed-bg);
        std::copy(bg,ed,str.begin());

        if(str[0]=='#')
        {
            if(str.length()==7)type = rgb;
            else type = rgba;
            i = str.sliced(1).toUInt(nullptr,16);
        }
        else if(str.contains('e'))
        {
            type = bol;
            if(str[0]=='t')i=1;
            else i=0;
        }
        else if(str.contains('.'))
        {
            type = flt;
            f = str.toFloat();
        }
        else
        {
            type = itg;
            i = str.toUInt();
        }
    }
    else
    {
        if(*bg=='/')type = end, ++bg;
        else type = beg;
        name.resize(ed-bg);
        std::copy(bg,ed,name.begin());
    }
}
void ThemeData::Tag::WriteTag(QByteArray& dat)
{
    if(type==beg||type==end)
    {
        if(type==end)dat.push_back('/');
        dat+=name.toUtf8();
        return;
    }
    dat+=(name + " Value=\"").toUtf8();
    switch(type)
    {
    case rgb:
        dat+=("#"+QString("%1").arg(i, 6, 16, QChar('0'))).toUtf8();
        break;
    case rgba:
        dat+=("#"+QString("%1").arg(i, 8, 16, QChar('0'))).toUtf8();
        break;
    case itg:
        dat += QString::number(i,10).toUtf8();
        break;
    case bol:
        if(i)dat += "true";
        else dat += "false";
        break;
    case flt:
        dat += QString::number(f).toUtf8();
        break;
    }
    dat+="\" /";
}

ThemeData::ThemeData()
{

}

bool ThemeData::LoadData(const QByteArray& fileName)
{
    QFile file(fileName);
    if(!file.exists())return false;
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))return false;
    auto dat = file.readAll();
    file.close();
    v.clear();
    auto bg = dat.begin(),ded = dat.end();
    while(*(bg++)!='\n');
    while(true)
    {
        while(*(bg++)!='<')if(bg==ded)return true;
        auto ed=bg;
        while(*(++ed)!='>');
        v.push_back({});
        v.back().ReadTag(bg,ed);
    }
}
bool ThemeData::SaveData(const QByteArray& fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))return false;
    QByteArray dat = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    int tabs = 0;
    for(auto& tag:v)
    {
        if(tag.type==Tag::end)--tabs;
        for(int i=0;i<tabs;++i)dat.push_back('\t');
        dat.push_back('<');
        tag.WriteTag(dat);
        dat.push_back('>');
        dat.push_back('\n');
        if(tag.type==Tag::beg)++tabs;

    }
    file.write(QByteArray(dat));
    file.close();
    return true;
}
