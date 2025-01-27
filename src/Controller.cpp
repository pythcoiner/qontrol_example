#include "Controller.h"
#include "screens/Home.h"
#include "screens/Next.h"


void Controller::loadPanels() {
    auto *home = new qontrol::Panel(new Home(), "home");
    this->insertPanel(home);

    auto *next = new qontrol::Panel(new Next(), "next");
    this->insertPanel(next);
    this->loadPanel("home");
}

void Controller::onNext() {
    this->loadPanel("next");
}

void Controller::onPrevious() {
    this->loadPanel("home");
}

void Controller::aClicked() {
    this->loadPanel("home");
}

void Controller::bClicked() {

}

void Controller::cClicked() {
    this->loadPanel("next");
}

auto Controller::get() -> Controller* {
    auto *ctrl = qontrol::Controller::get();
    auto *controller = dynamic_cast<Controller*>(ctrl);
    return controller;
}

void Controller::init() {
    if (qontrol::Controller::isInit()) {
        qFatal() << "Controller have already been initiated!";
    }
    qontrol::Controller::init(new Controller);
}

auto Controller::window() -> QWidget* {

    return qontrol::Controller::window();
}

