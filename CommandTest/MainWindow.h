#ifndef __MAINWINDOW__H
#define __MAINWINDOW__H
#include <QMainWindow>

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = 0);
	~MainWindow();
private:
	void initialize();
};

#endif//__MAINWINDOW__H
