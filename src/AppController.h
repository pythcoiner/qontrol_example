#pragma once

#include <QObject>
#include <Qontrol>

class AppController : public Controller {
    Q_OBJECT 
public:
    void loadPanels() override;
    static void init();
    static auto get() -> AppController*;
    static auto window() -> QWidget*;



public slots:
    void onNext();
    void onPrevious();
};
