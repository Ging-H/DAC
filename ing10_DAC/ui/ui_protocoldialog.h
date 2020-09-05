/********************************************************************************
** Form generated from reading UI file 'protocoldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTOCOLDIALOG_H
#define UI_PROTOCOLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_protocolDialog
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbiregList;
    QTableWidget *tabRegList;

    void setupUi(QDialog *protocolDialog)
    {
        if (protocolDialog->objectName().isEmpty())
            protocolDialog->setObjectName(QStringLiteral("protocolDialog"));
        protocolDialog->resize(700, 491);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(protocolDialog->sizePolicy().hasHeightForWidth());
        protocolDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/general/general/\345\215\217\350\256\256.png"), QSize(), QIcon::Normal, QIcon::Off);
        protocolDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(protocolDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(protocolDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 698, 489));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        lbiregList = new QLabel(scrollAreaWidgetContents);
        lbiregList->setObjectName(QStringLiteral("lbiregList"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        lbiregList->setFont(font);
        lbiregList->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(lbiregList);

        tabRegList = new QTableWidget(scrollAreaWidgetContents);
        if (tabRegList->columnCount() < 18)
            tabRegList->setColumnCount(18);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tabRegList->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        if (tabRegList->rowCount() < 10)
            tabRegList->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tabRegList->setVerticalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tabRegList->setVerticalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tabRegList->setVerticalHeaderItem(2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tabRegList->setVerticalHeaderItem(3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tabRegList->setVerticalHeaderItem(4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tabRegList->setVerticalHeaderItem(5, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tabRegList->setVerticalHeaderItem(6, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tabRegList->setVerticalHeaderItem(7, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tabRegList->setVerticalHeaderItem(8, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tabRegList->setVerticalHeaderItem(9, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tabRegList->setItem(0, 0, __qtablewidgetitem28);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setFont(font1);
        tabRegList->setItem(0, 1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tabRegList->setItem(1, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setFont(font1);
        tabRegList->setItem(1, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tabRegList->setItem(2, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setFont(font1);
        tabRegList->setItem(2, 1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tabRegList->setItem(3, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setFont(font1);
        tabRegList->setItem(3, 1, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tabRegList->setItem(4, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setFont(font1);
        tabRegList->setItem(4, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tabRegList->setItem(5, 0, __qtablewidgetitem38);
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setFont(font2);
        tabRegList->setItem(5, 1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tabRegList->setItem(6, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setFont(font1);
        tabRegList->setItem(6, 1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tabRegList->setItem(7, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setFont(font1);
        tabRegList->setItem(7, 1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tabRegList->setItem(8, 0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setFont(font1);
        tabRegList->setItem(8, 1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tabRegList->setItem(9, 0, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setFont(font1);
        tabRegList->setItem(9, 1, __qtablewidgetitem47);
        tabRegList->setObjectName(QStringLiteral("tabRegList"));
        tabRegList->setMinimumSize(QSize(0, 285));
        tabRegList->horizontalHeader()->setCascadingSectionResizes(false);
        tabRegList->horizontalHeader()->setDefaultSectionSize(40);
        tabRegList->verticalHeader()->setCascadingSectionResizes(false);

        verticalLayout_2->addWidget(tabRegList);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(protocolDialog);

        QMetaObject::connectSlotsByName(protocolDialog);
    } // setupUi

    void retranslateUi(QDialog *protocolDialog)
    {
        protocolDialog->setWindowTitle(QApplication::translate("protocolDialog", "Dialog", Q_NULLPTR));
        lbiregList->setText(QApplication::translate("protocolDialog", "\345\257\204\345\255\230\345\231\250\350\241\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tabRegList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("protocolDialog", "\345\234\260\345\235\200", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tabRegList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("protocolDialog", "\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tabRegList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("protocolDialog", "15", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tabRegList->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("protocolDialog", "14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tabRegList->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("protocolDialog", "13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tabRegList->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("protocolDialog", "12", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tabRegList->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("protocolDialog", "11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tabRegList->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("protocolDialog", "10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tabRegList->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("protocolDialog", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tabRegList->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("protocolDialog", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tabRegList->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("protocolDialog", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tabRegList->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("protocolDialog", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tabRegList->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("protocolDialog", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tabRegList->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("protocolDialog", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tabRegList->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("protocolDialog", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tabRegList->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("protocolDialog", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tabRegList->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("protocolDialog", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tabRegList->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QApplication::translate("protocolDialog", "0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tabRegList->verticalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("protocolDialog", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tabRegList->verticalHeaderItem(1);
        ___qtablewidgetitem19->setText(QApplication::translate("protocolDialog", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tabRegList->verticalHeaderItem(2);
        ___qtablewidgetitem20->setText(QApplication::translate("protocolDialog", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tabRegList->verticalHeaderItem(3);
        ___qtablewidgetitem21->setText(QApplication::translate("protocolDialog", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tabRegList->verticalHeaderItem(4);
        ___qtablewidgetitem22->setText(QApplication::translate("protocolDialog", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tabRegList->verticalHeaderItem(5);
        ___qtablewidgetitem23->setText(QApplication::translate("protocolDialog", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tabRegList->verticalHeaderItem(6);
        ___qtablewidgetitem24->setText(QApplication::translate("protocolDialog", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tabRegList->verticalHeaderItem(7);
        ___qtablewidgetitem25->setText(QApplication::translate("protocolDialog", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tabRegList->verticalHeaderItem(8);
        ___qtablewidgetitem26->setText(QApplication::translate("protocolDialog", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tabRegList->verticalHeaderItem(9);
        ___qtablewidgetitem27->setText(QApplication::translate("protocolDialog", "10", Q_NULLPTR));

        const bool __sortingEnabled = tabRegList->isSortingEnabled();
        tabRegList->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem28 = tabRegList->item(0, 0);
        ___qtablewidgetitem28->setText(QApplication::translate("protocolDialog", "0x03E8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tabRegList->item(0, 1);
        ___qtablewidgetitem29->setText(QApplication::translate("protocolDialog", "\350\256\276\345\244\207\346\240\207\345\277\227\345\257\204\345\255\230\345\231\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tabRegList->item(1, 0);
        ___qtablewidgetitem30->setText(QApplication::translate("protocolDialog", "0x03E9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = tabRegList->item(1, 1);
        ___qtablewidgetitem31->setText(QApplication::translate("protocolDialog", "\351\200\232\344\277\241\345\217\202\346\225\2601", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = tabRegList->item(2, 0);
        ___qtablewidgetitem32->setText(QApplication::translate("protocolDialog", "0x03EA", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem33 = tabRegList->item(2, 1);
        ___qtablewidgetitem33->setText(QApplication::translate("protocolDialog", "\351\200\232\344\277\241\345\217\202\346\225\2602", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem34 = tabRegList->item(3, 0);
        ___qtablewidgetitem34->setText(QApplication::translate("protocolDialog", "0x03EB", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem35 = tabRegList->item(3, 1);
        ___qtablewidgetitem35->setText(QApplication::translate("protocolDialog", "\351\200\232\344\277\241\345\217\202\346\225\2603", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem36 = tabRegList->item(4, 0);
        ___qtablewidgetitem36->setText(QApplication::translate("protocolDialog", "0x03EC", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem37 = tabRegList->item(4, 1);
        ___qtablewidgetitem37->setText(QApplication::translate("protocolDialog", "\351\200\232\344\277\241\345\217\202\346\225\2604", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem38 = tabRegList->item(5, 0);
        ___qtablewidgetitem38->setText(QApplication::translate("protocolDialog", "0x03ED", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem39 = tabRegList->item(5, 1);
        ___qtablewidgetitem39->setText(QApplication::translate("protocolDialog", "\347\263\273\347\273\237\345\257\204\345\255\230\345\231\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem40 = tabRegList->item(6, 0);
        ___qtablewidgetitem40->setText(QApplication::translate("protocolDialog", "0x03EE", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem41 = tabRegList->item(6, 1);
        ___qtablewidgetitem41->setText(QApplication::translate("protocolDialog", "\350\276\223\345\207\272\351\200\232\351\201\223A", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem42 = tabRegList->item(7, 0);
        ___qtablewidgetitem42->setText(QApplication::translate("protocolDialog", "0x03EF", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem43 = tabRegList->item(7, 1);
        ___qtablewidgetitem43->setText(QApplication::translate("protocolDialog", "\350\276\223\345\207\272\351\200\232\351\201\223B", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem44 = tabRegList->item(8, 0);
        ___qtablewidgetitem44->setText(QApplication::translate("protocolDialog", "0x03F0", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem45 = tabRegList->item(8, 1);
        ___qtablewidgetitem45->setText(QApplication::translate("protocolDialog", "\346\240\241\345\207\206\351\200\232\351\201\223A", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem46 = tabRegList->item(9, 0);
        ___qtablewidgetitem46->setText(QApplication::translate("protocolDialog", "0x03F1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem47 = tabRegList->item(9, 1);
        ___qtablewidgetitem47->setText(QApplication::translate("protocolDialog", "\346\240\241\345\207\206\351\200\232\351\201\223B", Q_NULLPTR));
        tabRegList->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class protocolDialog: public Ui_protocolDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTOCOLDIALOG_H
