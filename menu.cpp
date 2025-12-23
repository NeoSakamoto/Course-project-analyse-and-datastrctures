#include "menu.h"
#include "funcs.h"
#include "./ui_menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    ui->treeWidget->header()->setSectionResizeMode(QHeaderView::Stretch);
    ui->treeWidget->header()->setDefaultAlignment(Qt::AlignCenter);
    Menu_Load("cars.txt", ui->treeWidget);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{

}

