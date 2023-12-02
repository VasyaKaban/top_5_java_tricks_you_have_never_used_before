#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QValidator>
#include <QErrorMessage>
#include <QSqlQuery>
#include <QSqlResult>
#include <QDebug>
#include <QTextStream>
#include <array>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	  , ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connect(ui->delete_btn, &QPushButton::clicked, this, &MainWindow::DeleteItem);
	connect(ui->add_btn, &QPushButton::clicked, this, &MainWindow::AddItem);
	connect(ui->update_btn, &QPushButton::clicked, this, &MainWindow::UpdateItem);
	connect(ui->items_table, &QTableWidget::itemSelectionChanged, this, &MainWindow::SetDataFromRowIntoLines);

	ui->items_table->setColumnCount(5);
	ui->items_table->setHorizontalHeaderLabels({"id", "Автор", "Название", "Год издания", "Жанр"});
	ui->items_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	ui->author_line->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{1,128}"), this));
	ui->name_line->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{1,128}"), this));
	ui->publishing_year_line->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,4}"), this));

	ui->items_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->items_table->setSelectionMode(QAbstractItemView::SingleSelection);

	db = QSqlDatabase::addDatabase("QMYSQL", "connection");
	db.setHostName("localhost");
	db.setDatabaseName("books_lab7");
	db.setUserName("vasyakaban");
	db.setPassword("384557");
	if(!db.open())
	{
		QErrorMessage *err_msg = new QErrorMessage(this);
		err_msg->showMessage("Database connection failied!");
		err_msg->exec();
		exit(1);
	}

	QSqlQuery query(db);
	QString query_str = "SELECT book.id AS id, book.author AS author, book.name AS name, book.year_of_publishing AS year_of_publishing, genre.name AS genre "
						"FROM book INNER JOIN genre ON book.genre_id = genre.id;";

	query.exec(query_str);
	while(query.next())
	{
		ui->items_table->insertRow(ui->items_table->rowCount());
		int last_row = ui->items_table->rowCount() - 1;
		auto item = new QTableWidgetItem(query.value(id_pos).toString());
		item->setFlags(item->flags() ^ Qt::ItemIsEditable);
		ui->items_table->setItem(last_row, id_pos, item);

		item = new QTableWidgetItem(query.value(author_pos).toString());
		item->setFlags(item->flags() ^ Qt::ItemIsEditable);
		ui->items_table->setItem(last_row, author_pos, item);

		item = new QTableWidgetItem(query.value(name_pos).toString());
		item->setFlags(item->flags() ^ Qt::ItemIsEditable);
		ui->items_table->setItem(last_row, name_pos, item);

		item = new QTableWidgetItem(query.value(year_of_publiching_pos).toString());
		item->setFlags(item->flags() ^ Qt::ItemIsEditable);
		ui->items_table->setItem(last_row, year_of_publiching_pos, item);

		item = new QTableWidgetItem(query.value(genre_pos).toString());
		item->setFlags(item->flags() ^ Qt::ItemIsEditable);
		ui->items_table->setItem(last_row, genre_pos, item);
	}

	query_str = "SELECT name FROM genre;";
	query.clear();
	query.exec(query_str);
	while(query.next())
		ui->genre_cbox->addItem(query.value(0).toString());
}

MainWindow::~MainWindow()
{
	delete ui;
}

auto MainWindow::DeleteItem() -> void
{
	auto model = ui->items_table->selectionModel();
	if(!model->hasSelection())
		return;

	auto selected_row = model->selectedRows().back().row();
	QSqlQuery query(db);
	QString query_str = "DELETE FROM book WHERE id = ";
	query_str += ui->items_table->item(selected_row, 0)->text().toUtf8() + ";";
	query.exec(query_str);

	ui->items_table->removeRow(selected_row);
}

auto MainWindow::AddItem() -> void
{
	QSqlQuery query(db);
	QString str;
	str.reserve(16);
	QTextStream stream(&str);
	stream<<"INSERT INTO book VALUES (0, "<<
		"'"<<ui->author_line->text().toUtf8()<<"', "<<
		"'"<<ui->name_line->text().toUtf8()<<"', "<<
		ui->publishing_year_line->text().toUtf8()<<", "<<
		QString::number(ui->genre_cbox->currentIndex() + 1).toUtf8()<<");";

	query.exec(*stream.string());

	ui->items_table->insertRow(ui->items_table->rowCount());
	int last_row = ui->items_table->rowCount() - 1;
	auto item = new QTableWidgetItem(query.lastInsertId().toString());
	item->setFlags(item->flags() ^ Qt::ItemIsEditable);
	ui->items_table->setItem(last_row, id_pos, item);

	item = new QTableWidgetItem(ui->author_line->text());
	item->setFlags(item->flags() ^ Qt::ItemIsEditable);
	ui->items_table->setItem(last_row, author_pos, item);

	item = new QTableWidgetItem(ui->name_line->text());
	item->setFlags(item->flags() ^ Qt::ItemIsEditable);
	ui->items_table->setItem(last_row, name_pos, item);

	item = new QTableWidgetItem(ui->publishing_year_line->text());
	item->setFlags(item->flags() ^ Qt::ItemIsEditable);
	ui->items_table->setItem(last_row, year_of_publiching_pos, item);

	item = new QTableWidgetItem(ui->genre_cbox->currentText());
	item->setFlags(item->flags() ^ Qt::ItemIsEditable);
	ui->items_table->setItem(last_row, genre_pos, item);
}

auto MainWindow::UpdateItem() -> void
{
	auto model = ui->items_table->selectionModel();
	if(!model->hasSelection())
		return;

	QString text = ui->author_line->text();
	int pos = 0;
	if(!ui->author_line->validator()->validate(text, pos))
		return;

	text = ui->name_line->text();
	pos = 0;
	if(!ui->name_line->validator()->validate(text, pos))
		return;

	text = ui->publishing_year_line->text();
	pos = 0;
	if(!ui->publishing_year_line->validator()->validate(text, pos))
		return;

	auto selected_row = model->selectedRows().back().row();

	QSqlQuery query(db);
	QString str;
	str.reserve(16);
	QTextStream stream(&str);
	stream<<"UPDATE book SET author = "<<
		"'"<<ui->author_line->text().toUtf8()<<"', name = "<<
		"'"<<ui->name_line->text().toUtf8()<<"', year_of_publishing = "<<
		ui->publishing_year_line->text().toUtf8()<<", genre_id = "<<
		QString::number(ui->genre_cbox->currentIndex() + 1)<<
		" WHERE id = "<< ui->items_table->item(selected_row, id_pos)->text()<<";";

	qDebug()<<*stream.string();
	query.exec(*stream.string());

	ui->items_table->item(selected_row, author_pos)->setText(ui->author_line->text());
	ui->items_table->item(selected_row, name_pos)->setText(ui->name_line->text());
	ui->items_table->item(selected_row, year_of_publiching_pos)->setText(ui->publishing_year_line->text());
	ui->items_table->item(selected_row, genre_pos)->setText(ui->genre_cbox->currentText());
}

auto MainWindow::SetDataFromRowIntoLines() -> void
{
	auto model = ui->items_table->selectionModel();
	if(!model->hasSelection())
		return;

	auto selected_row = model->selectedRows().back().row();
	ui->author_line->setText(ui->items_table->item(selected_row, author_pos)->text());
	ui->name_line->setText(ui->items_table->item(selected_row, name_pos)->text());
	ui->publishing_year_line->setText(ui->items_table->item(selected_row, year_of_publiching_pos)->text());
	ui->genre_cbox->setCurrentText(ui->items_table->item(selected_row, genre_pos)->text());
}

