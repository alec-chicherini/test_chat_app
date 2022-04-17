#include <QWidget>
#include <QMessageBox>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QScreen>
#include <QWindow>
#include <QDebug>
#include <QSizeGrip>

class chatWidget : public QWidget
{
public:
	chatWidget(QObject* parent = nullptr);
};