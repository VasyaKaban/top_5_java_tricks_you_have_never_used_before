CREATE DATABASE books_lab7;
USE books_lab7;

CREATE TABLE genre
(
	id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
	name VARCHAR(32)
);

INSERT INTO genre VALUES
(0, "Новелла"),
(0, "Повесть"),
(0, "Эпопея"),
(0, "Комедия"),
(0, "Пародия"),
(0, "Трагедия"),
(0, "Драма"),
(0, "Поэма"),
(0, "Роман");

CREATE TABLE book
(
	id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
	author VARCHAR(128),
	name VARCHAR(128),
	year_of_publishing INT UNSIGNED,
	genre_id INT NOT NULL,
	FOREIGN KEY (genre_id) REFERENCES genre(id)
);

INSERT INTO book VALUES
(0, "Amogus Amogusovich", "book1", 2001, 1),
(0, "Abobus Cooler", "book2", 1864, 7),
(0, "Aboba Ivanovich", "book3", 2017, 5);
