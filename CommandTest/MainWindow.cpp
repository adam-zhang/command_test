#include "MainWindow.h"
#include "MainWidget.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent)
{
	initialize();
};

MainWindow::~MainWindow()
{

}

void MainWindow::initialize()
{
	setCentralWidget(new MainWidget);
}
