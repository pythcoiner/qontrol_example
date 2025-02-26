#include "MainWindow.h"
#include "Controller.h"
#include "Column.h"
#include "Row.h"
#include <qpushbutton.h>

MainWindow::MainWindow(QWidget *parent) : Window(parent) {
    Controller::init();
    Controller::get()->start(this);
    this->initWindow();
    Controller::get()->loadPanels();
    this->dumpObjectTree();
}

void MainWindow::initWindow() {
    if (m_side_menu == nullptr) {
        auto *aBtn = new QPushButton("A");
        aBtn->setFixedSize(150, 150);
        auto *bBtn = new QPushButton("B");
        bBtn->setFixedSize(150, 150);
        auto *cBtn = new QPushButton("C");
        cBtn->setFixedSize(150, 150);
        m_side_menu = (new qontrol::Column(this))
            ->push(aBtn)
            ->push(bBtn)
            ->push(cBtn)
            ->pushSpacer()
            ;
        m_side_menu->setFixedWidth(151);
        m_side_menu->setObjectName("menu");

        connect(aBtn, &QPushButton::clicked, Controller::get(), &Controller::aClicked);
        connect(bBtn, &QPushButton::clicked, Controller::get(), &Controller::bClicked);
        connect(cBtn, &QPushButton::clicked, Controller::get(), &Controller::cClicked);
    }

    if (m_panel_widget == nullptr) {
        this-> m_panel_widget = new QWidget(this);
        m_panel_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

    auto *mainLayout = (new qontrol::Row(this))
        ->push(m_side_menu)
        ->push(m_panel_widget)
        ;

    // avoid setCentralWidget() to remove the previous widget
    auto *taken = this->takeCentralWidget(); // NOLINT
    this->setCentralWidget(mainLayout->widget());
}

MainWindow::~MainWindow() = default;

void MainWindow::loadLayout(QLayout *layout) {
    m_panel_widget->setLayout(layout);
}

auto MainWindow::centralWidget() -> QWidget* {
    return m_panel_widget;
}

void MainWindow::loadPanel(QWidget *widget) {
    m_panel_widget = widget;
    this->initWindow();
}

auto MainWindow::takePanel() -> QWidget* {
    auto *panel = m_panel_widget;
    return panel;
}
