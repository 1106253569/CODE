-- Active: 1662366682577@@127.0.0.1@3306@student

CREATE DATABASE
    student ON PRIMARY(
        name = 'stu',
        filename = 'D:\stu_data.mdf',
        size = 15 MB,
        maxsize = 200 MB,
        filegrowth = 10 %
    ) LOG ON (
        name = 'stu_log',
        filename = 'D:\stu_log.ldf',
        size = 15 MB,
        maxsize = 100 MB,
        filegrowth = 1 MB
    );

CREATE TABLE
    student(
        sno CHAR(10) PRIMARY KEY,
        sname CHAR(20) not null,
        ssex CHAR(2),
        sage INT,
        sdept CHAR(20)
    );

CREATE TABLE
    course(
        cno CHAR(10) PRIMARY KEY,
        cname CHAR(20) not null,
        cpno CHAR(10),
        ccredit INT
    );

CREATE TABLE
    sc(
        sno CHAR(10),
        cno CHAR(10),
        grade INT,
        PRIMARY KEY(sno, cno)
    );

INSERT INTO
    student (sno, sname, ssex, sage, sdept)
VALUES ( "200515001", "赵菁菁", "女", "23", "CS"),
        ( "200515002", "李勇", "男", "20", "CS" ),
        ( "200515003", "张力", "男", "25", "CS" ),
        ( "200515004", "张衡", "男", "18", "IS"),
        ( "200515005", "张向东", "男", "25", "IS" ),
        ( "200515006", "张向丽", "女", "20", "IS" ),
        ( "200515007", "王芳", "女", "20", "CS" ),
        ( "200515008", "刘民生", "男", "22", "MA" ),
        ( "200515009", "王小民", "女", "21", "MA" ),
        ( "200515010", "李晨", "女", "22", "MA"),
        ( "200515011", "张毅", "男", "20", "WM" ),
        ( "200515012", "杨磊", "女", "20", "EN" ),
        ( "200515013", "王丽", "女", "19", NULL );

INSERT INTO
    course (cno, cname, cpno, ccredit)
VALUES ( "1", "数据库", "5.0", "4" ),
        ( "2", "数学", "nan", "2" ),
        ( "3", "信息系统", "1.0", "1" ),
        ( "4", "操作系统", "6.0", "3" ),
        ( "5", "数据结构", "7.0", "4"),
        ( "6", "数据处理", "nan", "2" ),
        ( "7", "PASCAL语言", "6.0", "4" ),
        ( "8", "大学英语", "nan", "4" );

INSERT INTO
    sc(sno, cno, grade)
VALUES ( "200515001", "1", "75" ),
        ( "200515002", "1", "85" ),
        ( "200515002", "2", "53" ),
        ( "200515003", "1", "86" ),
        ( "200515004", "2", "74" ),
        ( "200515005", "1", "58" ),
        ( "200515006", "1", "84" ),
        ( "200515004", "5", "46" ),
        ( "200515005", "4", "79" ),
        ( "200515006", "7", "65" ),
        ( "200515008", "2", "72" ),
        ( "200515009", "8", "76" );

ALTER TABLE student ADD COLUMN sclass VARCHAR(10);

ALTER TABLE student DROP sclass;

ALTER TABLE student CHANGE sname sname CHAR(9);

ALTER TABLE student CHANGE sdept dept VARCHAR(8);

DROP TABLE SC;

ALTER TABLE course ADD UNIQUE(cname);

EXEC SQL BEGIN DECLARE SELECT;

UPDATE student SET sname = '刘兵' WHERE sdept='IS' AND sname='张向东';

UPDATE course SET ccredit=3 WHERE cname='数据处理';

UPDATE sc SET grade=grade-5 WHERE cno=1;

SELECT s.*, c.cname FROM sc AS s JOIN course AS c WHERE s.cno=c.cno;

UPDATE sc AS s
    INNER JOIN course AS c ON s.cno = c.cno
SET grade = grade + 10
WHERE c.cname = '大学英语';

UPDATE student
SET
    sname = "王丹丹",
    ssex = "女",
    sage = 20,
    sdept = "MA"
WHERE sno = '200515010';

DELETE FROM student WHERE sdept IS NULL;

DELETE FROM student WHERE sdept='CS' AND sage>23;

DELETE FROM course WHERE ccredit<2;

SELECT * FROM student WHERE sname NOT LIKE '王%';

SELECT * FROM student WHERE sname LIKE '王_';

SELECT * FROM course WHERE cname LIKE '%系统%';

SELECT * FROM sc WHERE cno='1' ORDER BY grade;

SELECT
    c.sno,
    s.sname,
    c.cno,
    c.grade
FROM sc AS c
    JOIN student AS s ON s.sno = c.sno
WHERE cno = '1'
ORDER BY c.grade;

SELECT sno
FROM sc
WHERE
    cno = '1'
    OR cno = '2'
GROUP BY sno
HAVING COUNT(cno) = 2;

SELECT *
FROM student
WHERE sage > (
        SELECT AVG(sage)
        FROM student
    )
ORDER BY sage DESC;

SELECT *
FROM student
ORDER BY sage;

SELECT * FROM sc WHERE grade>80 ORDER BY sno,cno DESC;

SELECT COUNT(sno) AS "学生总人数" ,AVG(sage) AS "平均年龄" FROM student;

SELECT sno
FROM sc
GROUP BY sno
HAVING COUNT(cno) >= 2;

SELECT cno ,COUNT(sno),MAX(grade),MIN(grade),AVG(grade)
FROM sc
GROUP BY cno
ORDER BY cno DESC;

SELECT sno, AVG(grade)
FROM sc
GROUP BY sno
HAVING AVG(grade) > (
        SELECT AVG(grade)
        FROM sc
        WHERE
            sno = '200515001'
    );

SELECT sno, AVG(grade)
FROM sc
WHERE sno IN (
        SELECT sno
        FROM sc
        WHERE grade<60
    )
GROUP BY sno;


