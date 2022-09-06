-- Active: 1662366682577@@127.0.0.1@3306@datascience
USE datascience;

SELECT * FROM products;

DROP TABLE products;

ALTER TABLE products ADD account_id VARCHAR(100);

ALTER TABLE products
ADD
    CONSTRAINT account_id FOREIGN KEY(account_id) REFERENCES accounts(account_id);

INSERT INTO
    products(
        product_id,
        product_name,
        account_id
    )
VALUES (
        DEFAULT,
        'Visual TurboBuilder',
        1
    );

SELECT * FROM products;

INSERT INTO accounts(account_id) VALUES(123);

UPDATE products
SET
    account_id = account_id || ',' || 56
WHERE product_id = 123;

ALTER TABLE products DROP FOREIGN KEY account_id;

ALTER TABLE products DROP KEY account_id;

ALTER TABLE products MODIFY COLUMN account_id VARCHAR(100);

CREATE TABLE Comments(
    comment_id SERIAL PRIMARY KEY,
    parent_id BIGINT UNSIGNED,
    comment TEXT NOT NULL,
    FOREIGN KEY(parent_id) REFERENCES Comments(comment_id)
);

