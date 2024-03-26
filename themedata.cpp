#include "themedata.h"

// 读取标签数据
void ThemeData::Tag::ReadTag(QByteArray::iterator begin, QByteArray::iterator end)
{
    if (*(end - 1) == '/')
    {
        // 处理自闭合标签
        end = begin;
        while (*(++end) != ' ');
        // 提取标签名
        name.assign(begin, end);

        // 定位到 Value 属性的值
        while (*(begin++) != '"');
        QByteArray::iterator valueBegin = begin;
        while (*(++end) != '"');

        // 提取属性值
        QString value;
        value.assign(valueBegin, end);

        // 根据属性值类型进行赋值
        if (value[0] == '#')
        {
            if (value.length() == 7)
                type = rgb;
            else
                type = rgba;
            i = value.mid(1).toUInt(nullptr, 16);
        }
        else if (value.contains('e'))
        {
            type = bol;
            i = (value[0] == 't') ? 1 : 0;
        }
        else if (value.contains('.'))
        {
            type = flt;
            f = value.toFloat();
        }
        else
        {
            type = itg;
            i = value.toUInt();
        }
    }
    else
    {
        // 处理起始和结束标签
        type = (*begin == '/') ? end : beg;
        // 提取标签名
        name.assign(begin + (type == end ? 1 : 0), end);
    }
}

// 写入标签数据
void ThemeData::Tag::WriteTag(QByteArray& data)
{
    if (type == beg || type == end)
    {
        data.push_back((type == end) ? '/' : '>');
        data += name.toUtf8();
        return;
    }

    // 添加标签名和 Value 属性
    data += (name + " Value=\"").toUtf8();

    // 根据属性类型添加值
    switch (type)
    {
    case rgb:
        data += ("#" + QString("%1").arg(i, 6, 16, QChar('0'))).toUtf8();
        break;
    case rgba:
        data += ("#" + QString("%1").arg(i, 8, 16, QChar('0'))).toUtf8();
        break;
    case itg:
        data += QString::number(i, 10).toUtf8();
        break;
    case bol:
        data += (i ? "true" : "false");
        break;
    case flt:
        data += QString::number(f).toUtf8();
        break;
    }
    data += "\" /";
}

// 加载主题数据
bool ThemeData::LoadData(const QByteArray& fileName)
{
    QFile file(fileName);
    if (!file.exists() || !file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    // 读取文件内容
    QByteArray data = file.readAll();
    file.close();

    // 解析数据
    QByteArray::iterator iter = std::find(data.begin(), data.end(), '\n');
    while (++iter != data.end())
    {
        iter = std::find(iter, data.end(), '<');
        if (iter == data.end())
            break;
        QByteArray::iterator tagEnd = std::find(iter, data.end(), '>');
        if (tagEnd == data.end())
            break;

        // 创建标签并读取数据
        v.push_back({});
        v.back().ReadTag(iter + 1, tagEnd);
    }

    return true;
}

// 保存主题数据
bool ThemeData::SaveData(const QByteArray& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    // 写入 XML 头部
    QByteArray data = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    int tabs = 0;

    // 遍历标签数据并写入文件
    for (auto& tag : v)
    {
        if (tag.type == Tag::end)
            --tabs;

        // 添加缩进
        for (int i = 0; i < tabs; ++i)
            data.push_back('\t');

        // 写入标签内容
        data.push_back('<');
        tag.WriteTag(data);
        data.push_back('>');
        data.push_back('\n');

        if (tag.type == Tag::beg)
            ++tabs;
    }

    // 写入文件
    file.write(data);
    file.close();
    return true;
}

// 构造函数
ThemeData::ThemeData()
{
    // 初始化函数体为空
}
