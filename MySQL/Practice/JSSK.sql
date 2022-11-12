-- Active: 1662366682577@@127.0.0.1@3306@JSSK

CREATE DATABASE JSSK;

CREATE TABLE
    teachers(
        tno CHAR(7) PRIMARY KEY,
        tname CHAR(10) NOT NULL,
        tsex CHAR(2),
        birthday DATETIME,
        dept CHAR(20),
        sid CHAR(18)
    );

CREATE TABLE
    lessons(
        cno CHAR(10) PRIMARY KEY,
        cname CHAR(20) NOT NULL,
        credit INT,
        property CHAR(10)
    );

CREATE TABLE
    shouke(
        tno CHAR(7),
        cno CHAR(10),
        hours INT,
        PRIMARY KEY(tno, cno)
    );

ALTER TABLE shouke ADD COLUMN type CHAR(4);

ALTER TABLE shouke CHANGE hours hours SMALLINT;

ALTER TABLE lessons DROP property;