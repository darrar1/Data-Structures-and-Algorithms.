#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    timer = new QTimer(this);
    connect(timer, &QTimer::timeout,
 this, &MainWindow::onIncomingCall);
    timer->start(10000);

    quoteTimer = new QTimer(this);
    connect(quoteTimer, &QTimer::timeout, this, &MainWindow::displayRandomQuote);
    quoteTimer->start(30000);

    ui->quoteLabel->setText("This is the initial quote.");


    quotes << "The only way to do great work is to love what you do. - Steve Jobs"
           << "Strive not to be a success, but rather to be of value. - Albert Einstein"
           << "Believe you can and you're halfway there. - Theodore Roosevelt"

           << "The mind is everything. What you think you become. - Buddha"
           << "I have not failed. I've just found 10,000 ways that won't work. - Thomas Edison"

           << "The best and most beautiful things in the world cannot be seen or even touched - they must be felt with the heart. - Helen Keller"
           << "The future belongs to those who believe in the beauty of their dreams. - Eleanor Roosevelt"

           << "It is during our darkest moments that we must focus to see the light. - Aristotle"

           << "The only person you are destined to become is the person you decide to be. - Ralph Waldo Emerson"
           << "Life is what happens when you're busy making other plans. - John Lennon";



    callReasons << "Inquiry about a product" << "Technical support"
                << "Billing issue" << "Appointment scheduling"
                << "General feedback" << "Complaint"
                << "Pabili ng Balut" << "Pabili ng Yelo";


    connect(ui->clearAllDoneButton, &QPushButton::clicked, this, &MainWindow::onClearAllDoneButtonClicked);
    connect(ui->IncomingCall, &QListWidget::itemClicked, this, &MainWindow::onIncomingCallItemClicked);
    connect(ui->AnswerButton, &QPushButton::clicked, this, &MainWindow::onAnswerButtonClicked);
    connect(ui->ForwardButton, &QPushButton::clicked, this, &MainWindow::onForwardButtonClicked);
    connect(ui->HandleButton, &QPushButton::clicked, this, &MainWindow::onHandleButtonClicked);
    connect(ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::onQueueLogItemClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::displayRandomQuote()
{
    int randomIndex = QRandomGenerator::global()->bounded(quotes.size());
    ui->quoteLabel->setText(quotes[randomIndex]);
}

void MainWindow::onIncomingCallItemClicked(QListWidgetItem* item)
{

    selectedIncomingCallItem = item;
}

void MainWindow::onIncomingCall()
{
    QString phoneNumber = "09";
    for (int i = 0; i < 9; ++i) {
        phoneNumber += QString::number(QRandomGenerator::global()->bounded(10));
    }

    int randomReasonIndex = QRandomGenerator::global()->bounded(callReasons.size());
    QString reason = callReasons[randomReasonIndex];
    currentIncomingCall = "Incoming call from: " + phoneNumber + "\nReason: " + reason;

    ui->IncomingCall->addItem(currentIncomingCall);
}

void MainWindow::onForwardButtonClicked()
{
    if (selectedIncomingCallItem != nullptr) {
        QString selectedCall = selectedIncomingCallItem->text();


        callStack.push(selectedCall);


        delete selectedIncomingCallItem;
        selectedIncomingCallItem = nullptr;
    }
}

void MainWindow::updateQueueLogs()
{
    ui->listWidget->clear();
    for (const QString& caller : callQueue) {
        ui->listWidget->addItem(caller);
    }
}

void MainWindow::onQueueLogItemClicked(QListWidgetItem* item)
{
    selectedItem = item;
}

void MainWindow::onHandleButtonClicked()
{
    if (selectedItem != nullptr) {
        QString currentText = selectedItem->text();
        int index = currentText.indexOf(" - ");
        if (index != -1) {
            QString newText = currentText.left(index + 3) + "Done";
            selectedItem->setText(newText);

            for (int i = 0; i < callQueue.size(); ++i) {
                if (callQueue[i] == currentText) {
                    callQueue[i] = newText;
                    break;
                }
            }

            if (callStack.contains(currentText)) {
                callStack.replace(callStack.indexOf(currentText), newText);
            }

            selectedItem = nullptr;
        }
    }
}

void MainWindow::onAnswerButtonClicked()
{
    if (selectedIncomingCallItem != nullptr) {
        QString selectedCall = selectedIncomingCallItem->text();


        if (selectedCall.contains(" - Done")) {
            delete selectedIncomingCallItem;
            selectedIncomingCallItem = nullptr;
            return;
        }

        QString status = "On call";
        QString logEntry = QString::number(queueNumber) + ". " + selectedCall + " - " + status;

        callQueue.enqueue(logEntry);
        updateQueueLogs();
        queueNumber++;

        delete selectedIncomingCallItem;
        selectedIncomingCallItem = nullptr;
    }
}

void MainWindow::onClearAllDoneButtonClicked()
{
    QStack<QListWidgetItem*> tempStack;


    for (int i = ui->listWidget->count() - 1; i >= 0; --i) {
        QListWidgetItem* item = ui->listWidget->item(i);
        if (item->text().contains(" - Done")) {
            QString currentText = item->text();


            for (int j = 0; j < callQueue.size(); ++j) {
                if (callQueue[j] == currentText) {
                    callQueue.removeAt(j);
                    break;
                }
            }

            tempStack.push(ui->listWidget->takeItem(i));
        }
    }


    while (!tempStack.isEmpty()) {
        delete tempStack.pop();
    }

    updateQueueLogs();
}


void MainWindow::on_HandleButton2_clicked()
{
    if (selectedItem != nullptr) {
        QString currentText = selectedItem->text();
        int index = currentText.indexOf(" - ");
        if (index != -1) {
            QString newText = currentText.left(index + 3) + "Cancelled";
            selectedItem->setText(newText);

            for (int i = 0; i < callQueue.size(); ++i) {
                if (callQueue[i] == currentText) {
                    callQueue[i] = newText;
                    break;
                }
            }

            if (callStack.contains(currentText)) {
                callStack.replace(callStack.indexOf(currentText), newText);
            }

            selectedItem = nullptr;
        }
    }
}


void MainWindow::on_clearAllCancelButton_clicked()
{
    QQueue<QString> tempQueue;
    while (!callQueue.isEmpty()) {
        QString call = callQueue.dequeue();
        if (!call.contains(" - Cancelled")) {
            tempQueue.enqueue(call);
        }
    }
    callQueue = tempQueue;


    updateQueueLogs();
}

