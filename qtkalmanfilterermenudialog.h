#ifndef QTKALMANFILTERERMENUDIALOG_H
#define QTKALMANFILTERERMENUDIALOG_H

#pragma GCC diagnostic push

#include "qthideandshowdialog.h"
#pragma GCC diagnostic pop

namespace Ui {
  class QtKalmanFiltererMenuDialog;
}

namespace ribi {
namespace kalman {

class QtKalmanFiltererMenuDialog : public QtHideAndShowDialog
{
    Q_OBJECT //!OCLINT

public:
  explicit QtKalmanFiltererMenuDialog(QWidget *parent = 0);
  ~QtKalmanFiltererMenuDialog() noexcept;

  QtKalmanFiltererMenuDialog(const QtKalmanFiltererMenuDialog&) = delete;
  QtKalmanFiltererMenuDialog& operator=(const QtKalmanFiltererMenuDialog&) = delete;

protected:
  void keyPressEvent(QKeyEvent * event);

private:
  Ui::QtKalmanFiltererMenuDialog *ui;

private slots:
  void on_button_about_clicked();
  void on_button_quit_clicked();
  void on_button_start_clicked();
};

} //~namespace kalman
} //~namespace ribi

#endif // QTKALMANFILTERERMENUDIALOG_H
