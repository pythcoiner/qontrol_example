#pragma once

#include <Qontrol>
#include <qpushbutton.h>
#include <qtmetamacros.h>

class Home : public qontrol::Screen {
    Q_OBJECT
public:
    explicit Home();

protected:
    void init() override;
    void doConnect() override;
    void view() override;

    [[nodiscard]]  auto hasValue() const -> bool override {
        return false;
    };
    [[nodiscard]]  auto value() const -> QJsonValue override {
        return QJsonValue::Null;
    };
    [[nodiscard]]  auto isIterable() const -> bool override {
        return false;
    };

private:
    QPushButton *m_btn = nullptr;
};
