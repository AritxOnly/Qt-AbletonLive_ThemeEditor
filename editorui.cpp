#include "editorui.h"
#include "redohandler.h"
#include "themeeditor.h"

EditorUI::EditorUI(QWidget *parent)
{
    transPix.load(":/pics/resources/pics/transparent.png");

    searchBar = new QLineEdit(this);
    searchBar->setHidden(true);
    searchBar->setStyleSheet("color: #adadad;"
                             "border-color: #3f3f3f;"
                             "selection-color: #535353;"
                             "border-radius:10px;"
                             "background-color:#202022");
    searchBar->setPlaceholderText("Search...");
    searchBar->setFixedHeight(40);

    dataList = new QListView(this);
    dataList->setHidden(true);
    dataList->setStyleSheet("background-color:#2a2a2a;"
                            "color: #c0c0c3; "
                            "font-size:15px; color:#c0c0c3;"
                            "border-radius:20px;");
    dataList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    dataList->setModel(itemModel = new QStandardItemModel);
    dataList->setEditTriggers(QAbstractItemView::NoEditTriggers);



    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(searchBar);
    vLayout->addWidget(dataList);

    // 初始化控件
    //searchBar->installEventFilter(this); // 设置eventFilter



    // 信号与槽
    connect(searchBar,&QLineEdit::textChanged,
            this,&EditorUI::TextChanged);

    connect(dataList,&QListView::doubleClicked,
            this,&EditorUI::ItemDoubleClicked);


}

void EditorUI::ThemeDataChanged(ThemeData* td)
{

    themeData = td;
    itemModel->clear();

    if(!td)
    {
        searchBar->setHidden(true);
        dataList->setHidden(true);
        return;
    }
    searchBar->setHidden(false);
    dataList->setHidden(false);

    for(uint i=0,s = themeData->size();i<s;++i)
    {
        auto& tag = themeData->at(i);
        if(tag.type!=ThemeData::rgb && tag.type != ThemeData::rgba)
        {
            continue;
        }
        auto item = new QStandardItem;
        //设置子项相关信息

        item->setSizeHint(QSize(0, 48));

        item->setText(tag.name);


        uint c = tag.i;
        if(tag.type==ThemeData::rgba)c = (c>>8)|((c&0xff)<<24);
        else c|=0xff000000;

        if((c&0xff)+((c>>8)&0xff)+((c>>16)&0xff)>300)item->setForeground(Qt::black);
        else item->setForeground(Qt::white);

        SetItemColor(item,c);
        item->setData(i);

        itemModel->appendRow(item);

    }
}

void EditorUI::TextChanged(const QString &text)
{
    auto match = itemModel->findItems(text, Qt::MatchContains);

    for(uint i=0,s=itemModel->rowCount();i<s;++i)
    {
        auto it = itemModel->item(i);
        it->setFlags(it->flags() & ~Qt::ItemIsEnabled);

        // 实现搜索隐藏不相关条目的功能
        if(!match.contains(it))
            it->setSizeHint(QSize(0, 0));   // 曲线救国：将w和h直接设置为0
        else
            it->setSizeHint(QSize(0, 48));
    }
    for(auto& item:match)
    {
        item->setFlags(item->flags() | Qt::ItemIsEnabled);
    }
}

void EditorUI::ItemDoubleClicked(const QModelIndex &modelIndex)
{
    QStandardItem *item = itemModel->itemFromIndex(modelIndex);
    uint index = item->data().toUInt();

    auto& tag = themeData->at(index);
    uint c = tag.i;

    QColorDialog colorDiag(this);
    colorDiag.setStyleSheet("color:#c0c0c3;");

    colorDiag.setWindowTitle(tag.name);
    if(tag.type==ThemeData::rgba)
    {
        colorDiag.setOption(QColorDialog::ShowAlphaChannel);
        colorDiag.setCurrentColor(QColor((c>>24)&0xff,(c>>16)&0xff,(c>>8)&0xff,c&0xff));
        colorDiag.exec();

        if (colorDiag.result() == QDialog::Accepted) {
            if (editor != nullptr) {
                editor->getRedoHandler()->pushFileSnapshot(themeData);
            }
            uint c  = colorDiag.currentColor().rgba();
            themeData->Modify(index, c = (c>>8)|((c&0xff)<<24));
            SetItemColor(item,c);
        }
    }
    else
    {
        colorDiag.setCurrentColor(c);
        colorDiag.exec();
        if (colorDiag.result() == QDialog::Accepted) {
            if (editor != nullptr) {
                editor->getRedoHandler()->pushFileSnapshot(themeData);
            }
            uint c = colorDiag.currentColor().rgb();
            themeData->Modify(index, c);
            SetItemColor(item,c);
        }
    }

}

void EditorUI::SetItemColor(QStandardItem* item, uint c)
{
    QPixmap tmp = transPix;
    QPainter pt(&tmp);
    pt.setOpacity(1.0*(c>>24)/0xff);
    pt.fillRect(tmp.rect(),c);
    pt.end();
    item->setBackground(QBrush(tmp));
}

void EditorUI::setThemeEditor(ThemeEditor* _editor) {
    editor = _editor;
}
