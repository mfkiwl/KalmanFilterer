#ifndef QTWHITENOISESYSTEMPARAMETERSDIALOG
#define QTWHITENOISESYSTEMPARAMETERSDIALOG

#include <map>
#include <vector>




#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/shared_ptr.hpp>
#include "qthideandshowdialog.h"
#include <QTableWidget>


///NEVER FORGET: Do never use forward declarations in header files parsed by MOC
#include "laggedwhitenoisesystemparameters.h"
#include "qtkalmanfiltererparameterdialog.h"
#include "qtkalmanfilterexperimentmodel.h"
#include "standardwhitenoisesystemparameters.h"
#include "whitenoisesystem.h"
#include "whitenoisesystemparametertype.h"
#include "whitenoisesystemtype.h"

namespace Ui {
  class QtWhiteNoiseSystemParametersDialog;
}

namespace ribi {
namespace kalman {

class QtWhiteNoiseSystemParametersDialog : public QtHideAndShowDialog
{
  Q_OBJECT //!OCLINT
  
public:
  QtWhiteNoiseSystemParametersDialog(const QtWhiteNoiseSystemParametersDialog&) = delete;
  QtWhiteNoiseSystemParametersDialog& operator=(const QtWhiteNoiseSystemParametersDialog&) = delete;

  explicit QtWhiteNoiseSystemParametersDialog(
    const boost::shared_ptr<QtKalmanFilterExperimentModel> model,
    QWidget *parent = 0);
  ~QtWhiteNoiseSystemParametersDialog() noexcept;

  ///Find a WhiteNoiseSystemParameterType its corresponding table
  QtParameterDialog * Find(const WhiteNoiseSystemParameterType type);
  const QtParameterDialog * Find(const WhiteNoiseSystemParameterType type) const;

  ///Read the lag (in timesteps) from the dialog
  int GetLag() const;

  #ifndef NDEBUG
  ///Obtain the GUI
  Ui::QtWhiteNoiseSystemParametersDialog * GetUi() { return ui; }

  bool IsValid() const;
  #endif

  ///Obtain the white noise system type
  WhiteNoiseSystemType GetWhiteNoiseSystemType() const;

  ///Set the white noise system type
  void SetWhiteNoiseSystemType(const WhiteNoiseSystemType type);

protected:
  void keyPressEvent(QKeyEvent * event);

private:
  Ui::QtWhiteNoiseSystemParametersDialog *ui;

  ///The model
  const boost::shared_ptr<QtKalmanFilterExperimentModel> m_model;

  ///The parameter type and its corresponding dialog
  std::map<WhiteNoiseSystemParameterType,QtParameterDialog *> m_parameters;

private slots:

  void on_box_white_noise_system_type_currentIndexChanged(int index);

  void on_box_lag_valueChanged(int arg1);
};

} //~namespace kalman
} //~namespace ribi

#endif // QTWHITENOISESYSTEMPARAMETERSDIALOG
