/*
SELECT now()
FROM dual;

SHOW CHARACTER SET;
*/

CREATE TABLE person (
    person_id SMALLINT UNSIGNED,
    fname VARCHAR(20),
    lname VARCHAR(20),
    gender ENUM('M', 'F'),
    birth_date DATE,
    street VARCHAR(30),
    city VARCHAR(20),
    state VARCHAR(20),
    country VARCHAR(20),
    postal_code VARCHAR(20),
    CONSTRAINT pk_person PRIMARY KEY (person_id)
);

DESC person;

DESC favorite_food;

CREATE TABLE favorite_food (
    person_id SMALLINT UNSIGNED,
    food VARCHAR(20),
    CONSTRAINT pk_favorite_food PRIMARY KEY (person_id , food),
    CONSTRAINT fk_fav_food_person_id FOREIGN KEY (person_id)
        REFERENCES person (person_id)
);


## You can work around this by temporarily disabling foreign key checks.
set foreign_key_checks=0;

ALTER TABLE person MODIFY person_id SMALLINT UNSIGNED AUTO_INCREMENT;

INSERT INTO person
    (person_id,fname,lname,gender,birth_date)
VALUES (NULL,'Willam','Turner','M','1972-05-27');

SELECT *
FROM person
WHERE person_id=1;

INSERT INTO person
    (person_id,fname,lname,gender,birth_date)
VALUES (NULL,'Lili','Ya','M','1984-05-27');

SELECT *
FROM person
WHERE fname='Lili';

INSERT INTO favorite_food (person_id,food)
VALUE(1,'pizza');

INSERT INTO favorite_food (person_id,food)
VALUE(1,'cookies');

INSERT INTO favorite_food (person_id,food)
VALUE(1,'nachos');

SELECT *
FROM favorite_food
ORDER BY food;

insert into person 
    (person_id, fname, lname, gender, birth_date, street, city, state, country, postal_code)
values (null, 'Susan', 'Simth', 'F', '1975-11-2', '23 Maple st', 'Arlington', 'VA', 'USA', '20220');

DELETE FROM person
WHERE person_id=2;

UPDATE person
SET street='1225 Trement St. ',
    city='Boston',
    state='MA',
    country='USA',
    postal_code='02138'
WHERE person_id=1;

SELECT *
FROM person;

UPDATE person
SET birth_date=str_to_date('DEC-21-1980','%b-%d-%Y')
WHERE person_id =3;

SELECT *
FROM account;

SHOW TABLES;

DROP TABLE favorite_food;

DROP TABLE person;