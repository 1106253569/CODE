DESC product;

DESC customer;

DESC individual;

SELECT *
FROM individual;

DESC business;

SELECT 1 num,'abc' str
UNION
SELECT 9 num,'xyz' str;

SELECT 'IND' AS type_cd, cust_id, lname AS name
FROM individual
UNION ALL
SELECT 'BUS' AS type_cd,cust_id,name
FROM business
ORDER BY name;

SELECT 
    emp_id
FROM
    employee
WHERE
    assigned_branch_id = 2
        AND (title = 'Teller'
        OR title = 'Head Teller') 
UNION SELECT DISTINCT
    open_emp_id
FROM
    account
WHERE
    open_branch_id = 2;
