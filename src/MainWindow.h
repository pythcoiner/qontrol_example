#pragma once

#include <QMainWindow>
#include <qevent.h>
#include <qnamespace.h>
#include <qwidget.h>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void loadLayout(QLayout *layout);
    auto centralWidget() -> QWidget*;

private:
    QWidget* m_central_widget;
    bool m_allow_close = false;
};
