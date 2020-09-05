#ifndef PROTOCOLDIALOG_H
#define PROTOCOLDIALOG_H

#include <QDialog>

namespace Ui {
class protocolDialog;
}

class protocolDialog : public QDialog
{
    Q_OBJECT

public:
    explicit protocolDialog(QWidget *parent = 0);
    ~protocolDialog();
    void setInitRegList();
    void insertTable(quint16 data, QStringList discription, quint16 lastHeight=143) ;
private:
    Ui::protocolDialog *ui;
};

#endif // PROTOCOLDIALOG_H
