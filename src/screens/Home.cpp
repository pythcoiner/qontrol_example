#include "Home.h"
#include "Controller.h"
#include <qlabel.h>
#include <qpushbutton.h>

Home::Home() {
    this->init();
    this->doConnect();
    this->view();
}

void Home::init() {
    m_btn = new QPushButton("Next");
}

void Home::doConnect() {
    connect(m_btn, &QPushButton::clicked, Controller::get(), &Controller::onNext, qontrol::UNIQUE);
}

void Home::view() {
    auto *mainLayout = (new qontrol::Column(this))
        ->pushSpacer()
        ->push(m_btn)
        ->pushSpacer()
        ;

    this->setLayout(mainLayout->layout());
}

