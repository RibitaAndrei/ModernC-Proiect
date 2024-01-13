#include "PromptDialog.h"

PromptDialog::PromptDialog(QWidget* parent) : QDialog(parent)
{
    m_player1LineEdit = new QLineEdit(this);
    m_player2LineEdit = new QLineEdit(this);
    m_boardSizeLineEdit = new QLineEdit(this);

    setWindowTitle("Set game options");

    QLabel* player1Label = new QLabel("Player 1 Name:", this);
    QLabel* player2Label = new QLabel("Player 2 Name:", this);
    QLabel* boardSizeLabel = new QLabel("Board Size:", this);

    QFormLayout* formLayout = new QFormLayout(this);
    formLayout->addRow(player1Label, m_player1LineEdit);
    formLayout->addRow(player2Label, m_player2LineEdit);
    formLayout->addRow(boardSizeLabel, m_boardSizeLineEdit);

    QPushButton* startButton = new QPushButton("Set options", this);
    QPushButton* cancelButton = new QPushButton("Cancel", this);

    connect(startButton, &QPushButton::clicked, this, &PromptDialog::getInfo);
    connect(startButton, &QPushButton::clicked, this, &PromptDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &PromptDialog::reject);
    formLayout->addRow(startButton, cancelButton);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);

    setLayout(mainLayout);
}