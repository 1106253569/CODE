DESC employee;

DESC department;

SELECT e.fname, e.lname, d.name
FROM employee AS e JOIN department AS d;

SELECT e.fname ,e.lname, d.name
FROM employee AS e JOIN department AS d
    ON e.dept_id=d.dept_id;
    
SELECT e.fname, e.lname, d.name
FROM employee AS e INNER JOIN department AS d
    USING(dept_id);
    
SELECT a.account_id, a.cust_id,a.open_date,a.product_cd
FROM account AS a,branch AS b,employee AS e
WHERE a.open_emp_id=e.emp_id
    AND e.start_date<'2007-01-01';
    
SELECT a.account_id, a.cust_id,a.open_date,a.product_cd
FROM account AS a INNER JOIN employee AS e
    ON a.open_emp_id=e.emp_id
    INNER JOIN branch AS b
    ON e.assigned_branch_id=b.branch_id
WHERE e.start_date<'2007-01-01'
    AND (e.title='Teller' OR e.title='Head Teller')
    AND b.name='Woburn Branch';
    
SELECT a.account_id, a.cust_id,a.open_date,a.product_cd
FROM account AS a 
    INNER JOIN(
    SELECT emp_id,assigned_branch_id
        FROM employee
        WHERE start_date<'2007-01-01'
            AND (title='Teller' OR title='Head Teller')) AS e
        ON a.open_emp_id=e.emp_id
    INNER JOIN(
    SELECT branch_id
        FROM branch
        WHERE name='Woburn Branch') AS b
    ON e.assigned_branch_id=b.branch_id;
    
SELECT e1.fname,e1.lname,'VS' AS vs,e2.fname,e2.lname
FROM employee AS e1 INNER JOIN employee AS e2
    ON e1.emp_id < e2.emp_id
WHERE e1.title='Teller' AND e2.title='Teller';
    
    