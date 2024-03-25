#include "themeeditor.h"

#include <QApplication>

#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QListView>
#include <QPushButton>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThemeEditor w;

    //窗体设定：标题，图标
    w.setWindowTitle("Ableton Live Theme Editor");
    w.setWindowIcon(QIcon(":/ico/resource/logo.ico"));


//    w.setWindowFlags(Qt::FramelessWindowHint);

    w.show();
    return a.exec();

//    QApplication app(argc, argv);

//    // 创建主窗口和布局
//    QWidget window;
//    QVBoxLayout *layout = new QVBoxLayout(&window);

//    // 创建一个字符串列表
//    QStringList stringList;
//    stringList << "苹果" << "香蕉" << "橙子" << "葡萄" << "梨";

//    // 创建一个标准项模型
//    QStandardItemModel model;
//    model.setHorizontalHeaderLabels(QStringList() << "水果");

//    // 将字符串列表添加到模型中
//    foreach(QString fruit, stringList) {
//        QStandardItem *item = new QStandardItem(fruit);
//        model.appendRow(item);
//    }

//    // 创建一个列表视图并设置模型
//    QListView listView;
//    listView.setModel(&model);

//    // 创建一个按钮，用于在点击时添加新的元素
//    QPushButton addButton("添加新水果");
//    QObject::connect(&addButton, &QPushButton::clicked, [&]() {
//        QString newFruit = "新水果" + QString::number(model.rowCount() + 1);
//        QStandardItem *item = new QStandardItem(newFruit);
//        model.appendRow(item);
//    });

//    // 将列表视图和按钮添加到布局中
//    layout->addWidget(&listView);
//    layout->addWidget(&addButton);

//    // 设置主窗口的布局
//    window.setLayout(layout);

//    // 设置主窗口的大小并显示
//    window.resize(400, 300);
//    window.show();

//    return app.exec();
}
