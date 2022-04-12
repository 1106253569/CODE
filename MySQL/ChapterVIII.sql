SELECT open_emp_id
FROM account;

SELECT open_emp_id
FROM account
GROUP BY open_emp_id;

SELECT open_emp_id, count(*) AS how_many
FROM account
WHERE count(*) >4
GROUP BY open_emp_id;

SELECT open_emp_id,count(*) AS how_many
FROM account
GROUP BY open_emp_id
HAVING count(*)>4;

SELECT 
    product_cd,
    max(avail_balance) max_balance,
    min(avail_balance) min_balance,
    avg(avail_balance) avg_balance,
    sum(avail_balance) sum_bablance,
    count(*) num_accounts
FROM account
WHERE product_cd = 'CHK';

SELECT 
    product_cd,
    max(avail_balance) max_balance,
    min(avail_balance) min_balance,
    avg(avail_balance) avg_balance,
    sum(avail_balance) sum_bablance,
    count(*) num_accounts
FROM account
GROUP BY product_cd;

SELECT *
FROM account;

SELECT *,count(*) AS how_many
FROM account
GROUP BY product_cd;

SELECT account_id,open_emp_id
FROM account
ORDER BY open_emp_id;

SELECT *
FROM account;

SELECT count(DISTINCT open_emp_id)
FROM account
GROUP BY product_cd;

SELECT max(pending_balance - avail_balance) AS max_uncleared
FROM account;

CREATE TABLE number_tbl(val SMALLINT);

INSERT INTO number_tbl VALUE(1);

INSERT INTO number_tbl VALUE(3);

INSERT INTO number_tbl VALUE(5);

SELECT *
FROM number_tbl;

INSERT INTO number_tbl VALUE(NULL);

SELECT extract(YEAR FROM start_date) AS year,
    count(*) AS how_many
FROM employee
GROUP BY extract(YEAR FROM start_date);

SELECT product_cd,open_branch_id,
    SUM(avail_balance) AS total
FROM account
GROUP BY product_cd, open_branch_id WITH ROLLUP;

