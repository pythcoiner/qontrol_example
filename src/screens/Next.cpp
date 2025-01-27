#include "Next.h"
#include "Controller.h"
#include <qpushbutton.h>

Next::Next() {
    this->init();
    this->doConnect();
    this->view();
}

void Next::init() {
    m_btn = new QPushButton("Previous");
}

void Next::doConnect() {
    connect(m_btn, &QPushButton::clicked, Controller::get(), &Controller::onPrevious, qontrol::UNIQUE);
}

void Next::view() {
    auto *mainLayout = (new qontrol::Column(this))
        ->pushSpacer()
        ->push(m_btn)
        ->pushSpacer()
        ;

    this->setLayout(mainLayout->layout());
}
