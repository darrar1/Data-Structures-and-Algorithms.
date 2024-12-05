#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QStringList>
#include <QListWidget>
#include <QStack>
#include <QQueue>
#include <QLabel>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onIncomingCall();
    void onIncomingCallItemClicked(QListWidgetItem* item);
    void onForwardButtonClicked();
    void onHandleButtonClicked();
    void onQueueLogItemClicked(QListWidgetItem* item);
    void onAnswerButtonClicked();
    void displayRandomQuote();
    void onClearAllDoneButtonClicked();
    void on_HandleButton2_clicked();

    void on_clearAllCancelButton_clicked();

private:
    void updateQueueLogs();
    QLabel* quoteLabel;
    QStringList quotes;
    QTimer* quoteTimer;

    Ui::MainWindow *ui;
    QTimer *timer;
    QStringList callReasons;
    int queueNumber{ 1 };
    QStack<QString> callStack;
    QQueue<QString> callQueue;
    QListWidgetItem* selectedItem{ nullptr };
    QString currentIncomingCall;
    QListWidgetItem* selectedIncomingCallItem{ nullptr };
};

#endif
