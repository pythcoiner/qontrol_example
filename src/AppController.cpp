#include "AppController.h"
#include "screens/Home.h"
#include "screens/Next.h"


void AppController::loadPanels() {
    auto *home = new qontrol::Panel(new Home(), "home");
    this->insertPanel(home);

    auto *next = new qontrol::Panel(new Next(), "next");
    this->insertPanel(next);
    this->loadPanel("home");
}

void AppController::onNext() {
    this->loadPanel("next");
}

void AppController::onPrevious() {
    this->loadPanel("home");
}

void AppController::aClicked() {
    this->loadPanel("home");
}

void AppController::bClicked() {

}

void AppController::cClicked() {
    this->loadPanel("next");
}

auto AppController::get() -> AppController* {
    auto *ctrl = qontrol::Controller::get();
    auto *controller = dynamic_cast<AppController*>(ctrl);
    return controller;
}

void AppController::init() {
    if (qontrol::Controller::isInit()) {
        qFatal() << "Controller have already been initiated!";
    }
    qontrol::Controller::init(new AppController);
}

auto AppController::window() -> QWidget* {

    return qontrol::Controller::window();
}

