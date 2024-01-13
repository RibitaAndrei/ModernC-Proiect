#include <QDialog>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class PromptDialog : public QDialog {

public:
    PromptDialog(QWidget* parent = nullptr);
    // Accessor functions to get the entered values
    std::string GetPlayer1Name() const;
    std::string GetPlayer2Name() const;
    int GetBoardSize() const;

private:
    QLineEdit* m_player1LineEdit;
    QLineEdit* m_player2LineEdit;
    QLineEdit* m_boardSizeLineEdit;

    std::string m_player1Name;
    std::string m_player2Name;
    int m_boardSize;
};
