#include "Next.h"
#include "AppController.h"
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
    connect(m_btn, &QPushButton::clicked, AppController::get(), &AppController::onPrevious, UNIQUE);
}

void Next::view() {
    auto *mainLayout = (new Column(this))
        ->pushSpacer()
        ->push(m_btn)
        ->pushSpacer()
        ;

    this->setLayout(mainLayout->layout());
}
