#include "AppController.h"
#include "screens/Home.h"
#include "screens/Next.h"


void AppController::loadPanels() {
    auto *home = new Panel(new Home(), "home");
    this->insertPanel(home);

    auto *next = new Panel(new Next(), "next");
    this->insertPanel(next);
    this->loadPanel("home");
}

void AppController::onNext() {
    this->loadPanel("next");
}

void AppController::onPrevious() {
    this->loadPanel("home");

}

auto AppController::get() -> AppController* {
    auto *ctrl = Controller::get();
    auto *controller = dynamic_cast<AppController*>(ctrl);
    return controller;
}

void AppController::init() {
    if (Controller::isInit()) {
        qFatal() << "Controller have already been initiated!";
    }
    Controller::init(new AppController);
}

auto AppController::window() -> QWidget* {

    return Controller::window();
}

