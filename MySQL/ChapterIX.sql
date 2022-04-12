SELECT account_id, product_cd,cust_id,avail_balance
FROM account 
WHERE account_id=(SELECT max(account_id) FROM account);

SELECT account_id, product_cd, cust_id, avail_balance
FROM account
WHERE open_emp_id <> (SELECT e.emp_id
    FROM employee AS e INNER JOIN branch AS b
    ON e.assigned_branch_id=b.branch_id
    WHERE e.title='Head Teller' AND b.city='Woburn');
    
SELECT emp_id,fname,lname,title
FROM employee
WHERE emp_id <> ALL (SELECT superior_emp_id
    FROM employee
    WHERE superior_emp_id IS NOT NULL);
    
SELECT emp_id,fname,lname,title
FROM employee
WHERE emp_id NOT IN (1,2,NULL);

SELECT account_id,cust_id,product_cd,avail_balance
FROM account
WHERE avail_balance < ALL(SELECT a.avail_balance
    FROM account AS a INNER JOIN individual AS i
        ON a.cust_id=i.cust_id
    WHERE i.fname='Frank' AND i.lname='Tucker');
    
SELECT account_id,cust_id,product_cd,avail_balance
FROM account
WHERE avail_balance>ANY(SELECT a.avail_balance
    FROM account AS a INNER JOIN individual AS i
        ON a.cust_id=i.cust_id
    WHERE i.fname='Frank' AND i.lname='Tucker');
    
SELECT account_id,product_cd, cust_id
FROM account
WHERE open_branch_id = (
    SELECT branch_id
    FROM branch 
    WHERE name='Woburn Branch')
    AND open_emp_id IN (SELECT emp_id
    FROM employee
    WHERE title='Teller' OR title = 'Head Teller');
    
SELECT c.cust_id, c.cust_type_cd, c.city
FROM customer AS c
WHERE (SELECT sum(a.avail_balance)
    FROM account AS a
    WHERE a.cust_id=c.cust_id)
    BETWEEN 5000 AND 10000;
    
SELECT a.account_id,a.product_cd,a.cust_id,a.avail_balance
FROM account AS a
WHERE EXISTS (SELECT 1
    FROM transaction AS t
    WHERE t.account_id=a.account_id
        AND t.txn_date='2008-09-22');
        
SELECT a.account_id,a.product_cd,a.cust_id,a.avail_balance
FROM account AS a
WHERE NOT EXISTS (SELECT 1
    FROM transaction AS t
    WHERE t.account_id=a.account_id
        AND t.txn_date='2008-09-22');
        
UPDATE account AS a
SET a.last_activity_date=(SELECT max(t.txn_date)
    FROM transaction AS t
    WHERE t.account_id=a.account_id)
WHERE EXISTS (SELECT 1
    FROM transaction AS t
    WHERE t.account_id=a.account_id);

##解除安全模式
SET SQL_SAFE_UPDATES = 0;
    
DELETE FROM department
WHERE NOT EXISTS (SELECT 1
    FROM employee
    WHERE employee.dept_id=department.dept_id);
    
SELECT 'Small Fry' AS name,0 AS low_limit,4999.99 AS high_limit
UNION ALL
SELECT 'Average Joes' AS name, 5000 AS low_limit, 9999.99 AS high_limit
UNION ALL
SELECT 'Heavy Hitters' AS name, 10000 AS low_limit,999999.99 AS high_limit;

SELECT `groups`.name, COUNT(*) AS num_customers
FROM (SELECT SUM(a.avail_balance) cust_balance
    FROM account AS a INNER JOIN product p 
        ON a.product_cd = p.product_cd
    WHERE p.product_type_cd = 'ACCOUNT'
    GROUP BY a.cust_id) AS cust_rollup
    INNER JOIN (SELECT 'Small Fry' AS name,0 AS low_limit,4999.99 AS high_limit
        UNION ALL
        SELECT 'Average Joes' AS name, 5000 AS low_limit, 9999.99 AS high_limit
        UNION ALL
        SELECT 'Heavy Hitters' AS name, 10000 AS low_limit,999999.99 AS high_limit) AS `groups`
    ON cust_rollup.cust_balance BETWEEN `groups`.low_limit AND `groups`.high_limit
GROUP BY `groups`.name;
