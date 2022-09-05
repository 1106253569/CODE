SELECT *
FROM employee
WHERE end_date IS NULL
    AND title!='Teller' 
    AND start_date >= '2007-01-01';

SELECT pt.name AS product_type, p.name AS product
FROM product AS p INNER JOIN product_type AS pt
    ON p.product_type_cd = pt.product_type_cd
WHERE pt.name = 'Customer Accounts';

SELECT pt.name AS product_type, p.name AS product
FROM product AS p INNER JOIN product_type AS pt
    ON p.product_type_cd = pt.product_type_cd
WHERE pt.name <> 'Customer Accounts'; ##'<>'=='!='


DELETE FROM account
WHERE status = 'CLOSED' AND year(close_date) = 2002;

SELECT emp_id, fname ,lname,start_date
FROM employee
WHERE start_date BETWEEN '1989-06-04' AND '2007-01-01';

SELECT cust_id,fed_id
FROM customer
WHERE cust_type_cd = 'I'
    AND fed_id BETWEEN '500-00-0000' AND '999-99-9999';
    
SELECT account_id, product_cd, cust_id, avail_balance
FROM account
WHERE product_cd IN ('CHK','SAV','CD','MM');

SELECT account_id, product_cd, cust_id, avail_balance
FROM account
WHERE product_cd IN (SELECT product_cd FROM product
    WHERE product_type_cd ='ACCOUNT');
    
SELECT *
FROM employee
WHERE left(lname,1)='T';

SELECT lname
FROM employee
WHERE lname LIKE '_a%e%';

SELECT cust_id, fed_id
FROM customer
WHERE fed_id LIKE '___-__-____';

SELECT emp_id, fname, lname
FROM employee
WHERE lname REGEXP '^[FG]';

SELECT emp_id, fname, lname ,superior_emp_id
FROM employee
WHERE superior_emp_id IS NULL;

SELECT emp_id, fname, lname, superior_emp_id
FROM employee
WHERE superior_emp_id != 6 OR superior_emp_id IS NULL;