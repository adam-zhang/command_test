/********************************************************************************
> FileName:	Shifter.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Mon Apr 12 18:24:50 2021
********************************************************************************/
#ifndef __SHIFTER__H
#define __SHIFTER__H

#include <QObject>
#include <vector>
#include <memory>

enum class Direction
{
	Left,
	Right
};

class QWidget;
class QTimer;
class CommandButton;

class Shifter : public QObject
{
	Q_OBJECT
public:
	Shifter(Direction direction, const std::vector<CommandButton*>& buttons);
	~Shifter();
private:
	void initialize();
	void shiftLeft();
	void shiftRight();
private:
	std::shared_ptr<QTimer> timer_;
	Direction direction_;
	std::vector<CommandButton*> buttons_;
private slots:
	void onTimeOut();
signals:
	void done(CommandButton*);
};
#endif//__SHIFTER__H
