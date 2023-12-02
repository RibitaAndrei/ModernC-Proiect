// twixtboardui.h

#ifndef TWIXTBOARDUI_H
#define TWIXTBOARDUI_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

class TwixtBoardUI : public QWidget
{
	Q_OBJECT

public:
	explicit TwixtBoardUI(QWidget* parent = nullptr);
	~TwixtBoardUI();

private:
	QGridLayout* gridLayout;
	QPushButton*** boardButtons;  // Matrice de butoane pentru reprezentarea tablei de joc
	int boardSize;  // Dimensiunea tablei de joc (poate fi ajustat? în func?ie de necesit??i)

	// Alte func?ii private pentru ini?ializare, gestionarea evenimentelor etc.

private slots:
	// Func?ii pentru tratarea evenimentelor butoanelor

signals:
	// Semnale pentru comunicarea cu alte p?r?i ale programului (dac? este necesar)
};

#endif // TWIXTBOARDUI_H
