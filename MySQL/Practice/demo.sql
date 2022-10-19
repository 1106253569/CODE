-- Active: 1662366682577@@127.0.0.1@3306@homework

CREATE DATABASE Homework DEFAULT CHARACTER SET = 'utf8mb4';

CREATE TABLE
    ST(
        sno CHAR(10) PRIMARY KEY,
        sname CHAR(20),
        ssex CHAR(10),
        age INT,
        dept CHAR(20)
    );

CREATE TABLE
    course(
        cno CHAR(5) PRIMARY KEY,
        cname CHAR(20),
        credit INT
    );

CREATE TABLE
    SC(
        sno CHAR(10),
        cno CHAR(5),
        grade INT,
        PRIMARY KEY (sno, cno)
    );

SELECT sno,sname FROM ST WHERE age > 20;

SELECT AVG(grade) FROM SC WHERE sno=20001;

SELECT cno,MAX(grade) FROM SC GROUP BY sno;

SELECT ST.sno, ST.sname
FROM ST
    JOIN SC ON ST.sno = SC.sno
WHERE SC.cno = 2;