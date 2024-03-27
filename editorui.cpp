#include "editorui.h"

EditorUI::EditorUI(ThemeEditor *parent, ThemeData *themeData)
{
    p = parent;

    // SearchBar still WIP

    InitAskListView(*themeData);

    connect(p->ui->askColorList,
            &QListWidget::itemDoubleClicked,
            this,
            [=]() {
                ColorDialog(themeData);
            });
}

void EditorUI::InitAskListView(ThemeData themeData)
{
    p->ui->askColorList->
        setStyleSheet("padding: 5px; background-color:#2a2a2a; font-size:15px; color:#c0c0c3;");

    for(const auto& value : themeData)
    {
        if(value.type == ThemeData::rgb || value.type == ThemeData::rgba)
        {
            QListWidgetItem *item = new QListWidgetItem;

            //设置子项相关信息
            item->setSizeHint(QSize(p->ui->askColorList->width(),50));
            item->setText(value.name);
            item->setWhatsThis("#" + QString::number(value.i, 16));
            // qDebug() << value.name << value.i;
            int hexValue_withoutAlpha = value.i;
            if(hexValue_withoutAlpha >> 24 != 0)
                hexValue_withoutAlpha /= 0x100;
            if(hexValue_withoutAlpha % 0x1000000 <= 0x888888)
                item->setForeground(Qt::white);
            else
                item->setForeground(Qt::black);

            item->setBackground(Int2QColorRGBA(value.i));
            item->setData(Qt::UserRole, value.i);    //颜色存储，方便调用

            // hint: can I store the Index in the item?

            p->ui->askColorList->addItem(item);
        }
    }
}

QColor EditorUI::Int2QColorRGBA(unsigned int i)
{
    QString hex = QString::number(i, 16);    //转字符串
    // qDebug() << hex;
    QColor color2(hex.toUInt(NULL,16));
    return color2;
}

void EditorUI::ColorDialog(ThemeData *themeData)
{
    QListWidgetItem *item = p->ui->askColorList->currentItem();
    int index = themeData->Find(item->text());

    QColor color = QColorDialog::getColor(Int2QColorRGBA(item->data(Qt::UserRole).toInt()),
                                          this,
                                          "Select the desired color...",
                                          QColorDialog::ShowAlphaChannel);

    qDebug() << color.isValid();

    if(color.isValid())
    {
        QRgb mRGB = qRgba(color.red(), color.green(), color.blue(), color.alpha());
        QString colorHex = QString::number(mRGB, 16);
        unsigned int hexValue = colorHex.toUInt(nullptr, 16);
        if(hexValue >> 24 == 255)
            hexValue %= 0x1000000;   // 若颜色为完全不透明，则去掉首位的alpha值
        else
        {
            // 若颜色透明，则将hex值由QRgb的AARRGGBB改为xml中的RRGGBBAA
            int alphaValue = hexValue / 0x1000000;
            hexValue %= 0x1000000;
            hexValue = hexValue * 0x100 + alphaValue;
        }
        qDebug() << colorHex << hexValue << QString::number(hexValue, 16);

        item->setBackground(color);

        // 对颜色值进行修改
        qDebug() << themeData->
                          Modify(index, hexValue);
    }
}
