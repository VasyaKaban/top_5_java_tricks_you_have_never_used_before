CREATE DATABASE webpr_6lab;

USE webpr_6lab;

CREATE TABLE programmers
(
	Programmer_id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
	Name VARCHAR(50) DEFAULT NULL,
	Location VARCHAR(50) DEFAULT NULL,
	Qualification VARCHAR(50) DEFAULT NULL
);
