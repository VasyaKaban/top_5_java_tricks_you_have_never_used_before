#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>

QT_BEGIN_NAMESPACE
	namespace Ui { class MainWindow; }
QT_END_NAMESPACE

	class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow(QWidget *parent = nullptr);
		~MainWindow();

	private:
		auto DeleteItem() -> void;
		auto AddItem() -> void;
		auto UpdateItem() -> void;
		auto SetDataFromRowIntoLines() -> void;

private:
	Ui::MainWindow *ui;
	QSqlDatabase db;

	constexpr static int id_pos = 0;
	constexpr static int author_pos = 1;
	constexpr static int name_pos = 2;
	constexpr static int year_of_publiching_pos = 3;
	constexpr static int genre_pos = 4;
};
#endif // MAINWINDOW_H
