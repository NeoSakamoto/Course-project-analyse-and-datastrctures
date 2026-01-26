#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QTreeWidget>
#include "funcs.h"
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui {
class Menu;
}
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(const QString &role, const QString& login, QWidget *parent = nullptr);
    ~Menu();
    void AddToWidget(Car car);
    void Structures_Load(vector<Car>& cars);

    void UpdateCarInFile(const Car& car);
    void AppendCarToFile(const Car& car);

    void InsertEl(int structure, int count);
    void StructureAddEl(int structureind);
    bool CheckFields(Car& car);

    void RemoveFromStruct(int struc);

    void SearchInStruct(int struc);
    void RentInStruct(int struc);

private slots:
    void on_comboBox_2_activated(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Menu *ui;
    QTreeWidgetItem *editeditem = nullptr;
    vector <Car> cars;
    QString userRole;
    QString userLogin;

    HashTable hash;
    CarSearchTree searchtree;
    CarBTree btree;
    List list;
    BinaryHeap heap;
};
#endif // MENU_H
