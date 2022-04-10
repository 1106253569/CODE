CREATE TABLE string_tbl
    (char_fld CHAR(30),
    vchar_fld VARCHAR(30),
    text_fld TEXT
    );

DROP TABLE string_tbl;

DESC string_tbl;

INSERT INTO string_tbl (char_fld,vchar_fld,text_fld)
VALUES('This is char data',
    'This is varchar data',
    'This is text data');
    
SELECT *
FROM string_tbl;

UPDATE string_tbl
SET vchar_fld='This is a pirce of extremely long varchar data';
##字符过长

SELECT @@session.sql_mode;

##MySQL默认为'strict'模式
SET sql_mode='ANSI';

SET sql_mode='strict';

SELECT @@session.sql_mode;

SHOW WARNINGS;

SELECT vchar_fld
FROM string_tbl;

UPDATE string_tbl
SET text_fld='This string didn\'t work';

SHOW WARNINGS;