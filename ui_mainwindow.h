/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAddUser;
    QAction *actionDeleteUser;
    QAction *actionSetWaterRate;
    QAction *actionExit;
    QAction *actionSetCleanRate;
    QAction *actionAbout;
    QAction *actionHelp;
    QAction *actionManageMeter;
    QAction *actionRecord;
    QAction *actionincome;
    QWidget *centralWidget;
    QGridLayout *gridLayout_10;
    QStackedWidget *pages;
    QWidget *welcomePage;
    QGridLayout *gridLayout_5;
    QLabel *label_6;
    QLabel *label_5;
    QWidget *addUserPage;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLineEdit *editAddUserName;
    QComboBox *cbAddUserFloor;
    QLabel *label_4;
    QLabel *label_7;
    QComboBox *cbAddUserNumber1;
    QComboBox *cbAddUserUnit;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_8;
    QComboBox *cbAddUserNumber2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbAddUserNormal;
    QRadioButton *rbAddUserMerchant;
    QSpacerItem *verticalSpacer;
    QPushButton *btnAddUserSubmit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QWidget *queryPage;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_7;
    QComboBox *cbQueryYear;
    QLabel *label_10;
    QGroupBox *gbQueryPolicy;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *rbQueryByAddress;
    QComboBox *cbQueryFloor;
    QLabel *label_12;
    QComboBox *cbQueryUnit;
    QLabel *label_13;
    QComboBox *cbQueryNumber;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *rbQueryByName;
    QLineEdit *editQueryName;
    QGroupBox *gbQueryPay;
    QGridLayout *gridLayout_6;
    QRadioButton *rbQueryPay;
    QRadioButton *rbQueryNotPay;
    QPushButton *btnQuery;
    QTableView *tabQuery;
    QWidget *helpPage;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QWidget *incomePage;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarIncome;
    QPushButton *btnTodayIncome;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblIncome;
    QTableView *tabIncome;
    QMenuBar *menuBar;
    QMenu *menu_M;
    QMenu *menu_Q;
    QMenu *menu_S;
    QMenu *menu_H;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(825, 502);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/image/water.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAddUser = new QAction(MainWindow);
        actionAddUser->setObjectName(QStringLiteral("actionAddUser"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/image/addUser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddUser->setIcon(icon1);
        actionDeleteUser = new QAction(MainWindow);
        actionDeleteUser->setObjectName(QStringLiteral("actionDeleteUser"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/image/delUser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteUser->setIcon(icon2);
        actionSetWaterRate = new QAction(MainWindow);
        actionSetWaterRate->setObjectName(QStringLiteral("actionSetWaterRate"));
        actionSetWaterRate->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/image/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon3);
        actionSetCleanRate = new QAction(MainWindow);
        actionSetCleanRate->setObjectName(QStringLiteral("actionSetCleanRate"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/image/clean.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetCleanRate->setIcon(icon4);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout->setIcon(icon);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/image/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon5);
        actionManageMeter = new QAction(MainWindow);
        actionManageMeter->setObjectName(QStringLiteral("actionManageMeter"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/image/manageMeter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionManageMeter->setIcon(icon6);
        actionRecord = new QAction(MainWindow);
        actionRecord->setObjectName(QStringLiteral("actionRecord"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/image/record.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRecord->setIcon(icon7);
        actionincome = new QAction(MainWindow);
        actionincome->setObjectName(QStringLiteral("actionincome"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/image/income.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionincome->setIcon(icon8);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_10 = new QGridLayout(centralWidget);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        pages = new QStackedWidget(centralWidget);
        pages->setObjectName(QStringLiteral("pages"));
        pages->setLayoutDirection(Qt::LeftToRight);
        pages->setAutoFillBackground(false);
        welcomePage = new QWidget();
        welcomePage->setObjectName(QStringLiteral("welcomePage"));
        gridLayout_5 = new QGridLayout(welcomePage);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_6 = new QLabel(welcomePage);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/img/image/water.png")));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_6, 0, 0, 1, 1);

        label_5 = new QLabel(welcomePage);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_5->addWidget(label_5, 1, 0, 1, 1);

        pages->addWidget(welcomePage);
        addUserPage = new QWidget();
        addUserPage->setObjectName(QStringLiteral("addUserPage"));
        gridLayout_9 = new QGridLayout(addUserPage);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        groupBox_4 = new QGroupBox(addUserPage);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        groupBox_4->setFont(font1);
        groupBox_4->setFlat(true);
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        editAddUserName = new QLineEdit(groupBox_4);
        editAddUserName->setObjectName(QStringLiteral("editAddUserName"));
        editAddUserName->setFont(font1);
        editAddUserName->setClearButtonEnabled(true);

        gridLayout_4->addWidget(editAddUserName, 0, 1, 1, 1);

        cbAddUserFloor = new QComboBox(groupBox_4);
        cbAddUserFloor->setObjectName(QStringLiteral("cbAddUserFloor"));

        gridLayout_4->addWidget(cbAddUserFloor, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        gridLayout_4->addWidget(label_7, 3, 0, 1, 1);

        cbAddUserNumber1 = new QComboBox(groupBox_4);
        cbAddUserNumber1->setObjectName(QStringLiteral("cbAddUserNumber1"));

        gridLayout_4->addWidget(cbAddUserNumber1, 5, 1, 1, 1);

        cbAddUserUnit = new QComboBox(groupBox_4);
        cbAddUserUnit->setObjectName(QStringLiteral("cbAddUserUnit"));

        gridLayout_4->addWidget(cbAddUserUnit, 4, 1, 1, 1);

        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);

        gridLayout_4->addWidget(label_17, 5, 0, 1, 1);

        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font1);

        gridLayout_4->addWidget(label_18, 6, 0, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        gridLayout_4->addWidget(label_8, 4, 0, 1, 1);

        cbAddUserNumber2 = new QComboBox(groupBox_4);
        cbAddUserNumber2->setObjectName(QStringLiteral("cbAddUserNumber2"));

        gridLayout_4->addWidget(cbAddUserNumber2, 6, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        rbAddUserNormal = new QRadioButton(groupBox_4);
        rbAddUserNormal->setObjectName(QStringLiteral("rbAddUserNormal"));
        rbAddUserNormal->setChecked(true);

        horizontalLayout_2->addWidget(rbAddUserNormal);

        rbAddUserMerchant = new QRadioButton(groupBox_4);
        rbAddUserMerchant->setObjectName(QStringLiteral("rbAddUserMerchant"));

        horizontalLayout_2->addWidget(rbAddUserMerchant);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_4, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer, 0, 1, 1, 1);

        btnAddUserSubmit = new QPushButton(addUserPage);
        btnAddUserSubmit->setObjectName(QStringLiteral("btnAddUserSubmit"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        btnAddUserSubmit->setFont(font2);

        gridLayout_9->addWidget(btnAddUserSubmit, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_2, 4, 1, 1, 1);

        label = new QLabel(addUserPage);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label, 1, 1, 1, 1);

        pages->addWidget(addUserPage);
        queryPage = new QWidget();
        queryPage->setObjectName(QStringLiteral("queryPage"));
        gridLayout_8 = new QGridLayout(queryPage);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_3 = new QGroupBox(queryPage);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFont(font1);
        gridLayout_7 = new QGridLayout(groupBox_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        cbQueryYear = new QComboBox(groupBox_3);
        cbQueryYear->setObjectName(QStringLiteral("cbQueryYear"));
        cbQueryYear->setFont(font1);

        gridLayout_7->addWidget(cbQueryYear, 0, 0, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        gridLayout_7->addWidget(label_10, 0, 1, 1, 1);


        horizontalLayout_3->addWidget(groupBox_3);

        gbQueryPolicy = new QGroupBox(queryPage);
        gbQueryPolicy->setObjectName(QStringLiteral("gbQueryPolicy"));
        gbQueryPolicy->setFont(font1);
        gbQueryPolicy->setCheckable(true);
        gbQueryPolicy->setChecked(false);
        gridLayout_3 = new QGridLayout(gbQueryPolicy);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        rbQueryByAddress = new QRadioButton(gbQueryPolicy);
        rbQueryByAddress->setObjectName(QStringLiteral("rbQueryByAddress"));
        rbQueryByAddress->setFont(font1);
        rbQueryByAddress->setChecked(true);

        horizontalLayout_4->addWidget(rbQueryByAddress);

        cbQueryFloor = new QComboBox(gbQueryPolicy);
        cbQueryFloor->setObjectName(QStringLiteral("cbQueryFloor"));
        cbQueryFloor->setFont(font1);

        horizontalLayout_4->addWidget(cbQueryFloor);

        label_12 = new QLabel(gbQueryPolicy);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);

        horizontalLayout_4->addWidget(label_12);

        cbQueryUnit = new QComboBox(gbQueryPolicy);
        cbQueryUnit->setObjectName(QStringLiteral("cbQueryUnit"));
        cbQueryUnit->setFont(font1);

        horizontalLayout_4->addWidget(cbQueryUnit);

        label_13 = new QLabel(gbQueryPolicy);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        horizontalLayout_4->addWidget(label_13);

        cbQueryNumber = new QComboBox(gbQueryPolicy);
        cbQueryNumber->setObjectName(QStringLiteral("cbQueryNumber"));
        cbQueryNumber->setFont(font1);

        horizontalLayout_4->addWidget(cbQueryNumber);

        label_14 = new QLabel(gbQueryPolicy);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);

        horizontalLayout_4->addWidget(label_14);


        gridLayout_3->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        rbQueryByName = new QRadioButton(gbQueryPolicy);
        rbQueryByName->setObjectName(QStringLiteral("rbQueryByName"));
        rbQueryByName->setFont(font1);

        horizontalLayout_6->addWidget(rbQueryByName);

        editQueryName = new QLineEdit(gbQueryPolicy);
        editQueryName->setObjectName(QStringLiteral("editQueryName"));
        editQueryName->setEnabled(false);
        editQueryName->setFont(font1);
        editQueryName->setClearButtonEnabled(true);

        horizontalLayout_6->addWidget(editQueryName);


        gridLayout_3->addLayout(horizontalLayout_6, 1, 0, 1, 1);


        horizontalLayout_3->addWidget(gbQueryPolicy);

        gbQueryPay = new QGroupBox(queryPage);
        gbQueryPay->setObjectName(QStringLiteral("gbQueryPay"));
        gbQueryPay->setEnabled(false);
        gbQueryPay->setFont(font1);
        gbQueryPay->setFlat(false);
        gbQueryPay->setCheckable(true);
        gbQueryPay->setChecked(false);
        gridLayout_6 = new QGridLayout(gbQueryPay);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        rbQueryPay = new QRadioButton(gbQueryPay);
        rbQueryPay->setObjectName(QStringLiteral("rbQueryPay"));
        rbQueryPay->setFont(font1);
        rbQueryPay->setChecked(true);

        gridLayout_6->addWidget(rbQueryPay, 0, 0, 1, 1);

        rbQueryNotPay = new QRadioButton(gbQueryPay);
        rbQueryNotPay->setObjectName(QStringLiteral("rbQueryNotPay"));
        rbQueryNotPay->setFont(font1);

        gridLayout_6->addWidget(rbQueryNotPay, 1, 0, 1, 1);


        horizontalLayout_3->addWidget(gbQueryPay);

        btnQuery = new QPushButton(queryPage);
        btnQuery->setObjectName(QStringLiteral("btnQuery"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnQuery->sizePolicy().hasHeightForWidth());
        btnQuery->setSizePolicy(sizePolicy);
        btnQuery->setFont(font2);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/image/query.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnQuery->setIcon(icon9);
        btnQuery->setIconSize(QSize(32, 32));
        btnQuery->setCheckable(false);
        btnQuery->setAutoDefault(false);
        btnQuery->setFlat(false);

        horizontalLayout_3->addWidget(btnQuery);


        gridLayout_8->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        tabQuery = new QTableView(queryPage);
        tabQuery->setObjectName(QStringLiteral("tabQuery"));

        gridLayout_8->addWidget(tabQuery, 1, 0, 1, 1);

        pages->addWidget(queryPage);
        helpPage = new QWidget();
        helpPage->setObjectName(QStringLiteral("helpPage"));
        gridLayout_2 = new QGridLayout(helpPage);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textBrowser = new QTextBrowser(helpPage);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setFrameShape(QFrame::Box);
        textBrowser->setFrameShadow(QFrame::Sunken);
        textBrowser->setOpenLinks(false);

        gridLayout_2->addWidget(textBrowser, 0, 0, 1, 1);

        pages->addWidget(helpPage);
        incomePage = new QWidget();
        incomePage->setObjectName(QStringLiteral("incomePage"));
        gridLayout = new QGridLayout(incomePage);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        calendarIncome = new QCalendarWidget(incomePage);
        calendarIncome->setObjectName(QStringLiteral("calendarIncome"));
        calendarIncome->setMaximumSize(QSize(256, 300));
        calendarIncome->setGridVisible(true);
        calendarIncome->setNavigationBarVisible(true);
        calendarIncome->setDateEditEnabled(true);

        verticalLayout->addWidget(calendarIncome);

        btnTodayIncome = new QPushButton(incomePage);
        btnTodayIncome->setObjectName(QStringLiteral("btnTodayIncome"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnTodayIncome->sizePolicy().hasHeightForWidth());
        btnTodayIncome->setSizePolicy(sizePolicy1);
        btnTodayIncome->setFont(font2);

        verticalLayout->addWidget(btnTodayIncome);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lblIncome = new QLabel(incomePage);
        lblIncome->setObjectName(QStringLiteral("lblIncome"));
        lblIncome->setFont(font2);
        lblIncome->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(lblIncome);

        tabIncome = new QTableView(incomePage);
        tabIncome->setObjectName(QStringLiteral("tabIncome"));

        verticalLayout_2->addWidget(tabIncome);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        pages->addWidget(incomePage);

        gridLayout_10->addWidget(pages, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 825, 23));
        menu_M = new QMenu(menuBar);
        menu_M->setObjectName(QStringLiteral("menu_M"));
        menu_M->setEnabled(true);
        menu_Q = new QMenu(menuBar);
        menu_Q->setObjectName(QStringLiteral("menu_Q"));
        menu_S = new QMenu(menuBar);
        menu_S->setObjectName(QStringLiteral("menu_S"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu_M->menuAction());
        menuBar->addAction(menu_Q->menuAction());
        menuBar->addAction(menu_S->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_M->addAction(actionAddUser);
        menu_M->addAction(actionDeleteUser);
        menu_M->addSeparator();
        menu_M->addAction(actionincome);
        menu_M->addAction(actionExit);
        menu_Q->addAction(actionManageMeter);
        menu_Q->addAction(actionRecord);
        menu_S->addAction(actionSetWaterRate);
        menu_S->addAction(actionSetCleanRate);
        menu_H->addAction(actionAbout);
        menu_H->addAction(actionHelp);
        mainToolBar->addAction(actionAddUser);
        mainToolBar->addAction(actionDeleteUser);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionManageMeter);
        mainToolBar->addAction(actionRecord);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionincome);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExit);

        retranslateUi(MainWindow);

        pages->setCurrentIndex(4);
        btnQuery->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\261\261\350\245\277\345\244\247\345\255\246\345\244\247\344\270\234\345\205\263\346\240\241\345\214\272\346\260\264\350\264\271\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        actionAddUser->setText(QApplication::translate("MainWindow", "\345\274\200\346\210\267", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionAddUser->setToolTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\260\347\224\250\346\210\267", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionDeleteUser->setText(QApplication::translate("MainWindow", "\351\224\200\346\210\267", Q_NULLPTR));
        actionSetWaterRate->setText(QApplication::translate("MainWindow", "\346\260\264\350\264\271", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSetWaterRate->setToolTip(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\257\217\345\272\246\346\260\264\347\232\204\344\273\267\346\240\274", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\263\273\347\273\237", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionSetCleanRate->setText(QApplication::translate("MainWindow", "\345\215\253\347\224\237\350\264\271", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSetCleanRate->setToolTip(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\257\217\345\271\264\347\232\204\345\215\253\347\224\237\350\264\271", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("MainWindow", "\345\246\202\344\275\225\344\275\277\347\224\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionHelp->setToolTip(QApplication::translate("MainWindow", "\345\246\202\344\275\225\344\275\277\347\224\250\346\234\254\347\263\273\347\273\237", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionManageMeter->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\346\260\264\350\241\250", Q_NULLPTR));
        actionRecord->setText(QApplication::translate("MainWindow", "\350\256\260\350\241\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRecord->setToolTip(QApplication::translate("MainWindow", "\350\256\260\345\275\225\346\260\264\350\241\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionincome->setText(QApplication::translate("MainWindow", "\346\227\245\346\224\266\345\205\245", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionincome->setToolTip(QApplication::translate("MainWindow", "\346\227\245\346\224\266\345\205\245", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_6->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\346\254\242\350\277\216\346\235\245\345\210\260\345\261\261\350\245\277\345\244\247\345\255\246\345\244\247\344\270\234\345\205\263\346\240\241\345\214\272\346\260\264\350\264\271\347\256\241\347\220\206\347\263\273\347\273\237\357\274\201", Q_NULLPTR));
        groupBox_4->setTitle(QString());
        editAddUserName->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\346\210\267\344\270\273\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\346\245\274\346\240\213\357\274\232 ", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "\351\227\250\347\211\2141\357\274\232", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "\351\227\250\347\211\2142\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\345\215\225\345\205\203\357\274\232", Q_NULLPTR));
        cbAddUserNumber2->clear();
        cbAddUserNumber2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\227\240", Q_NULLPTR)
        );
        rbAddUserNormal->setText(QApplication::translate("MainWindow", "\346\231\256\351\200\232\347\224\250\346\210\267", Q_NULLPTR));
        rbAddUserMerchant->setText(QApplication::translate("MainWindow", "\345\225\206\346\210\267", Q_NULLPTR));
        btnAddUserSubmit->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\347\224\250\346\210\267", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\227\266\351\227\264", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\345\271\264", Q_NULLPTR));
        gbQueryPolicy->setTitle(QApplication::translate("MainWindow", "\346\237\245\350\257\242\344\276\235\346\215\256", Q_NULLPTR));
        rbQueryByAddress->setText(QApplication::translate("MainWindow", "\345\234\260\345\235\200", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\346\240\213", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\345\215\225\345\205\203", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "\345\217\267", Q_NULLPTR));
        rbQueryByName->setText(QApplication::translate("MainWindow", "\346\210\267\344\270\273", Q_NULLPTR));
        gbQueryPay->setTitle(QApplication::translate("MainWindow", "\347\274\264\350\264\271", Q_NULLPTR));
        rbQueryPay->setText(QApplication::translate("MainWindow", "\346\230\257", Q_NULLPTR));
        rbQueryNotPay->setText(QApplication::translate("MainWindow", "\345\220\246", Q_NULLPTR));
        btnQuery->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:600;\">\345\260\212\346\225\254\347\232\204\347\224\250\346\210\267\357\274\214\346\254\242\350\277\216\346\202\250\344\275\277\347\224\250\346\260\264\350\264\271\345\217\212\345\215\253\347\224\237\350\264\271\347\256\241\347\220\206\347\263\273\347\273\237\357\274\201</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\345\274\200\346\210\267\345\212\237\350\203\275</span><span style"
                        "=\" font-size:16pt;\">\357\274\232\346\202\250\345\217\257\344\273\245\345\234\250\350\277\231\351\207\214\346\267\273\345\212\240\346\226\260\347\224\250\346\210\267\357\274\214\345\271\266\346\214\207\345\256\232\345\234\260\345\235\200\357\274\214\345\211\215\346\217\220\346\230\257\344\270\215\350\203\275\345\222\214\345\267\262\346\234\211\347\232\204\347\224\250\346\210\267\345\234\260\345\235\200\351\207\215\345\244\215\343\200\202\345\246\202\346\236\234\351\207\215\345\244\215\347\232\204\350\257\235\357\274\214\346\202\250\345\277\205\351\241\273\345\205\210\350\247\243\345\206\263\350\277\231\344\272\233\345\206\262\347\252\201\357\274\201</span></p>\n"
"<p align=\"justify\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\351\224\200\346\210\267\345\212\237\350\203\275</span><span style=\" font-size:16pt;\">\357\274\232\346\202\250\345\217\257\344\273\245\345\210\240\351\231\244"
                        "\344\273\273\346\204\217\347\224\250\346\210\267\357\274\214\350\257\267\346\263\250\346\204\217\345\222\214\344\273\226\347\233\270\345\205\263\350\201\224\347\232\204\344\273\273\344\275\225\344\277\241\346\201\257\351\203\275\345\260\206\350\242\253\345\210\240\351\231\244\357\274\210\345\214\205\346\213\254\357\274\232\346\260\264\350\241\250\350\256\260\345\275\225\357\274\214\347\274\264\350\264\271\350\256\260\345\275\225\357\274\211\343\200\202</span><span style=\" font-size:16pt; color:#ff0000;\">\345\210\240\351\231\244\345\220\216\344\270\215\345\217\257\346\201\242\345\244\215\357\274\214\350\257\267\346\205\216\351\207\215\344\275\277\347\224\250\346\255\244\345\212\237\350\203\275\357\274\201</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\346\260\264\350\241\250\347\256\241\347\220\206</span><span style=\" font-size:16pt;\">\357\274\232\346\202\250\345\217\257"
                        "\344\273\245\345\234\250\350\277\231\351\207\214\350\275\273\346\235\276\347\256\241\347\220\206\346\211\200\346\234\211\347\224\250\346\210\267\347\232\204\346\260\264\350\241\250\343\200\202</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\346\237\245\350\257\242\345\212\237\350\203\275</span><span style=\" font-size:16pt;\">\357\274\232\346\202\250\345\217\257\344\273\245\351\200\211\346\213\251\346\240\271\346\215\256\346\227\266\351\227\264\346\237\245\350\257\242\357\274\214\346\240\271\346\215\256\345\234\260\345\235\200\346\210\226\346\210\267\344\270\273\346\237\245\350\257\242\357\274\214\346\240\271\346\215\256\346\230\257\345\220\246\347\274\264\350\264\271\346\237\245\350\257\242\347\224\250\346\210\267\347\232\204\345\220\204\351\241\271\347\272\252\345\275\225\343\200\202</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin"
                        "-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\347\274\264\350\264\271\345\212\237\350\203\275</span><span style=\" font-size:16pt;\">\357\274\232\344\275\240\345\217\257\344\273\245\344\275\277\347\224\250\346\255\244\345\212\237\350\203\275\350\275\273\346\235\276\345\256\214\346\210\220\347\224\250\346\210\267\347\274\264\350\264\271\343\200\202\347\263\273\347\273\237\345\260\206\350\207\252\345\212\250\346\211\223\345\215\260\345\207\255\350\257\201\343\200\202</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\350\256\260\345\275\225\345\212\237\350\203\275</span><span style=\" font-size:16pt;\">\357\274\232\345\234\250\350\277\231\351\207\214\357\274\214\346\202\250\345\217\257\344\273\245\345\275\225\345\205\245\347\224\250\346\210\267\347\232\204\346\260\264\350\241\250\344\277\241\346\201\257\357\274\201</span>"
                        "</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\351\200\200\345\207\272\345\212\237\350\203\275</span><span style=\" font-size:16pt;\">\357\274\232\346\202\250\345\217\257\344\273\245\344\275\277\347\224\250\346\255\244\345\212\237\350\203\275\351\200\200\345\207\272\347\263\273\347\273\237\357\274\201</span></p></body></html>", Q_NULLPTR));
        btnTodayIncome->setText(QApplication::translate("MainWindow", "\344\273\212\345\244\251", Q_NULLPTR));
        lblIncome->setText(QApplication::translate("MainWindow", "2017-6-7\346\200\273\346\224\266\345\205\245\357\274\23212.12", Q_NULLPTR));
        menu_M->setTitle(QApplication::translate("MainWindow", "\347\224\250\346\210\267(&M)", Q_NULLPTR));
        menu_Q->setTitle(QApplication::translate("MainWindow", "\346\260\264\350\241\250(&T)", Q_NULLPTR));
        menu_S->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256(&S)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
