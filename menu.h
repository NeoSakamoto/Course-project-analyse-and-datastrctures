#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QTreeWidget>
#include "funcs.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Menu;
}
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();
    void AddToWidget(Car car);

    void InsertEl(int structure, int count);
    void StructureAddEl(int structureind, int addcount);
    bool CheckFields(Car& car);

    void RemoveFromStruct(int struc);

    void SearchInStruct(int struc);

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Menu *ui;
    QTreeWidgetItem *editeditem = nullptr;
    vector <Car> cars;

    HashTable hash;
    CarSearchTree searchtree;
    CarBTree btree;
    List list;
    BinaryHeap heap;
};
#endif // MENU_H
