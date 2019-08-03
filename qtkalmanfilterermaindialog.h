#ifndef QTKALMANFILTERERMAINDIALOG_H
#define QTKALMANFILTERERMAINDIALOG_H

#include <vector>




#include <boost/shared_ptr.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "qthideandshowdialog.h"
#include <QTableWidget>

#include "qwt_plot.h"

#include "kalmanfilterexperiment.h"
#include "qthideandshowdialog.h"
#include "qtkalmanfilterexperimentdialog.h"
#include "qtkalmanfilterexperimentmodel.h"
#include "qtstandardkalmanfiltercalculationdialog.h"
#include "qtsteadystatekalmanfiltercalculationdialog.h"
#include "qtwhitenoisesystemparametersdialog.h"




namespace Ui {
  class QtKalmanFiltererMainDialog;
}

namespace ribi {
namespace kalman {

class QtKalmanFiltererMainDialog : public QtHideAndShowDialog
{
    Q_OBJECT //!OCLINT

public:
  QtKalmanFiltererMainDialog(const QtKalmanFiltererMainDialog&) = delete;
  QtKalmanFiltererMainDialog& operator=(const QtKalmanFiltererMainDialog&) = delete;

  explicit QtKalmanFiltererMainDialog(
    const boost::shared_ptr<QtKalmanFilterExperimentModel> model,
    QWidget *parent = 0);
  ~QtKalmanFiltererMainDialog() noexcept;

  ///Get the dialog to set the experiment its parameters
  const QtKalmanFilterExperimentDialog * GetExperimentDialog() const noexcept
  {
    return m_experiment_dialog;
  }

  QtKalmanFilterExperimentDialog * GetExperimentDialog() noexcept
  {
    return m_experiment_dialog;
  }

  boost::shared_ptr<QtKalmanFilterExperimentModel> GetModel() noexcept { return m_model; }

  ///Set the checkbox to show the calculation
  void SetShowCalculation(const bool do_show);

  ///Set the checkbox to show the graphs
  void SetShowGraph(const bool do_show);

  ///Set the checkbox to show the statistics
  void SetShowStatistics(const bool do_show);

  ///Set the checkbox to show the table
  void SetShowTable(const bool do_show);

  ///Create a QtKalmanFiltererMainDialog
  static boost::shared_ptr<QtKalmanFiltererMainDialog> Create();

protected:
  void keyPressEvent(QKeyEvent * event);
  
private:
  Ui::QtKalmanFiltererMainDialog *ui;

  ///The dialog to set the experiment its parameters
  QtKalmanFilterExperimentDialog * const m_experiment_dialog;

  ///The model
  const boost::shared_ptr<QtKalmanFilterExperimentModel> m_model;

  ///Contains the plots, these must be stored because deleting
  ///the layout that contains these does not work properly
  std::vector<boost::shared_ptr<QwtPlot>> m_plots;

  ///Contains the widgets that must be deleted at a new run
  ///these must be stored because deleting
  ///the layout that contains these does not work properly
  std::vector<boost::shared_ptr<QWidget>> m_to_delete_at_new_run;


  static const std::vector<std::vector<double> > CreateData(
    const std::vector<boost::numeric::ublas::vector<double> >& a,
    const std::vector<boost::numeric::ublas::vector<double> >& b,
    const std::vector<boost::numeric::ublas::vector<double> >& c,
    const std::vector<boost::numeric::ublas::vector<double> >& d
    );

  const boost::shared_ptr<QtKalmanFilterCalculationDialog>
    CreateKalmanFilterCalculationDialog(
    const KalmanFilterType type
  ) const;

  const std::vector<double> ExtractAverageSquaredError(
    const boost::shared_ptr<const KalmanFilterExperiment>& experiment);

  ///Called when a new context is set in m_model
  void OnNewContext(const std::string context);

  ///Show the results of an experiment in a calculation
  void ShowCalculation(const boost::shared_ptr<const KalmanFilterExperiment>& experiment);

  ///Show the results of an experiment in a graph
  void ShowGraph(const boost::shared_ptr<const KalmanFilterExperiment>& experiment);

  ///Show the results of an experiment its statistics
  void ShowStatistics(const boost::shared_ptr<const KalmanFilterExperiment>& experiment);

  ///Show the results of an experiment in a table
  void ShowTable(const boost::shared_ptr<const KalmanFilterExperiment>& experiment);

public slots:
  void on_button_start_clicked();
private slots:
  void on_button_save_graph_clicked();
  void on_tab_context_currentChanged(int index);
  void on_edit_context_textChanged();
};

} //~namespace kalman
} //~namespace ribi

#endif // QTKALMANFILTERERMAINDIALOG_H
