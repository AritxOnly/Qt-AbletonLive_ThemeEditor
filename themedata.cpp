#include "themedata.h"

// pull request by Yuziki
// 读取标签数据
void ThemeData::Tag::ReadTag(QByteArray::iterator bg, QByteArray::iterator ed)
{
    QString s = QString::fromUtf8(bg,ed-bg);
    if (*(ed - 1) == '/')
    {
        // 处理自闭合标签
        ed = bg;
        while (*(++ed) != ' ');
        // 提取标签名
        name = QString::fromUtf8(bg,ed-bg);

        // 定位到 Value 属性的值
        while (*(bg++) != '"');
        ed = bg;
        while (*(++ed) != '"');

        // 提取属性值
        QString str = QString::fromUtf8(bg,ed-bg);

        // 根据属性值类型进行赋值
        if (str[0] == '#')
        {
            if (str.length() == 7)
                type = rgb;
            else
                type = rgba;
            i = str.mid(1).toUInt(nullptr, 16);
        }
        else if (str.contains('e'))
        {
            type = bol;
            i = (str[0] == 't') ? 1 : 0;
        }
        else if (str.contains('.'))
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
        // 处理起始和结束标签
        if(*bg=='!')type=cmt,bg+=3,ed-=2;
        else if(*bg=='/')type=tl,++bg;
        else type=hd;
        // 提取标签名
        name = QString::fromUtf8(bg,ed-bg);
    }
}

// 写入标签数据
void ThemeData::Tag::WriteTag(QByteArray& dat)
{
    if (type == hd || type == tl || type == cmt)
    {
        if(type==tl)dat+='/';
        else if(type==cmt)dat+="!--";
        dat += name.toUtf8();
        if(type==cmt)dat+="--";
        return;
    }


    // 添加标签名和 Value 属性
    dat += (name + " Value=\"").toUtf8();

    // 根据属性类型添加值
    switch (type)
    {
    case rgb:
        dat += ("#" + QString("%1").arg(i, 6, 16, QChar('0'))).toUtf8();
        break;
    case rgba:
        dat += ("#" + QString("%1").arg(i, 8, 16, QChar('0'))).toUtf8();
        break;
    case itg:
        dat += QString::number(i, 10).toUtf8();
        break;
    case bol:
        dat += (i ? "true" : "false");
        break;
    case flt:
        dat += QString::number(f,'f',6).toUtf8();
        break;
    }
    dat += "\" /";
}

// 加载主题数据
bool ThemeData::LoadData(const QString& fileName)
{
    QFile file(fileName);
    if (!file.exists() || !file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    // 读取文件内容
    QByteArray dat = file.readAll();
    file.close();
    // 解析数据
    v.clear();
    auto bg = std::find(dat.begin(), dat.end(), '\n');
    while ((bg = std::find(bg, dat.end(), '<')) != dat.end())
    {
        // 创建标签并读取数据
        v.push_back({});
        v.back().ReadTag(++bg, std::find(bg, dat.end(), '>'));
    }
    return true;
}

// 保存主题数据
bool ThemeData::SaveData(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    // 写入 XML 头部
    QByteArray dat = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    int tabs = 0;

    // 遍历标签数据并写入文件
    for (auto& tag : v)
    {
        if (tag.type == tl)--tabs;

        // 添加缩进
        for (int i = 0; i < tabs; ++i)dat+='\t';

        // 写入标签内容
        tag.WriteTag(dat+='<');
        dat+=">\n";

        if (tag.type == hd)++tabs;
    }

    // 写入文件
    file.write(dat);
    file.close();

    modified=false;

    return true;
}



// 构造函数
ThemeData::ThemeData()
{
    // 初始化函数体为空
}

QVector<ThemeData::Tag>::const_iterator ThemeData::begin() const
{
    return v.cbegin();
}

QVector<ThemeData::Tag>::const_iterator ThemeData::end() const
{
    return v.cend();
}

const ThemeData::Tag& ThemeData::operator[](int i) const
{
    return v[i];
}

bool ThemeData::Modify(int i,float f)
{
    if(v[i].type!=4)return false;
    v[i].f=f;
    if(!modified)if(modified=true&&pf)pf(po);
    return true;
}
bool ThemeData::Modify(int i,unsigned int u)
{
    if(v[i].type>=4)return false;
    v[i].i=u;
    if(!modified)if(modified=true&&pf)pf(po);
    return true;
}

int ThemeData::Find(const QString& name) const
{
    int cnt=0;
    for(auto& tag:v)
    {
        if(tag.name==name&&tag.type<5)
        {
            return cnt;
        }
        ++cnt;
    }
    return -1;
}
