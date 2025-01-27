#pragma once

#include <QObject>
#include <Qontrol>

class AppController : public qontrol::Controller {
    Q_OBJECT 
public:
    void loadPanels() override;
    static void init();
    static auto get() -> AppController*;
    static auto window() -> QWidget*;



public slots:
    void onNext();
    void onPrevious();

    void aClicked();
    void bClicked();
    void cClicked();
};
