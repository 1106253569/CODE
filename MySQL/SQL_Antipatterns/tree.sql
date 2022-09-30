-- Active: 1662366682577@@127.0.0.1@3306@datascience

USE datascience;

CREATE TABLE
    Comments(
        comment_id SERIAL PRIMARY KEY,
        parent_id BIGINT UNSIGNED,
        comment TEXT NOT NULL,
        FOREIGN KEY (parent_id) REFERENCES Comments(comment_id)
    );

DROP TABLE comments;

CREATE TABLE
    Comments(
        comment_id SERIAL PRIMARY KEY,
        parent_id BIGINT UNSIGNED,
        bug_id BIGINT UNSIGNED NOT NULL,
        author BIGINT UNSIGNED NOT NULL,
        comment_date DATETIME NOT NULL,
        comment TEXT NOT NULL,
        FOREIGN KEY (parent_id) REFERENCES Comments(comment_id),
        FOREIGN KEY (bug_id) REFERENCES bugs(bug_id),
        FOREIGN KEY (author) REFERENCES accounts(account_id)
    );

INSERT INTO accounts(account_id, account_name) VALUES('Fran', '57');

INSERT INTO
    comments (
        comment_id,
        parent_id,
        bug_id,
        author,
        comment_date,
        comment
    )
VALUES (
        7,
        NULL,
        1234,
        3,
        NOW(),
        '这个bug的成因是什么'
    );

INSERT INTO
    comments(
        bug_id,
        parent_id,
        author,
        comments
    )
VALUES (1234, 7, 'Kukla', 'Thanks');

SELECT * FROM bugs;

CREATE TABLE
    comments1(
        comment_id SERIAL PRIMARY KEY,
        nsleft INTEGER NOT NULL,
        nsright INTEGER NOT NULL,
        bug_id BIGINT UNSIGNED NOT NULL,
        author BIGINT UNSIGNED NOT NULL,
        comment_date DATETIME NOT NULL,
        comment TEXT NOT NULL
    );

INSERT INTO
    comments1(
        comment_id,
        nsleft,
        nsright,
        bug_id,
        author,
        comment_date,
        comment
    )
VALUES (1, 1, 14, 1, 001, NOW(), "成因");

INSERT INTO
    comments1(
        comment_id,
        nsleft,
        nsright,
        bug_id,
        author,
        comment_date,
        comment
    )
VALUES (2, 2, 5, 1, 002, NOW(), "空"), (3, 3, 4, 1, 003, NOW(), "成因"), (4, 6, 13, 1, 004, NOW(), "成因"), (5, 7, 8, 1, 005, NOW(), "成因"), (6, 9, 12, 1, 006, NOW(), "成因");

INSERT INTO
    comments1(
        comment_id,
        nsleft,
        nsright,
        bug_id,
        author,
        comment_date,
        comment
    )
VALUES (7, 10, 11, 1, 007, NOW(), "成因");

SELECT c2.*
FROM comments1 AS c1
    JOIN comments1 AS c2 ON c2.nsleft BETWEEN c1.nsleft AND c1.nsright
WHERE c1.comment_id = 4;

SELECT
    c1.comment_id,
    COUNT(c2.comment_id) AS depth
FROM comments1 AS c1
    JOIN comments1 AS c2 ON c1.nsleft BETWEEN c2.nsleft AND c2.nsright
WHERE c1.comment_id = 7
GROUP BY c1.comment_id;