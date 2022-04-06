USE test;

SELECT emp_id,'ACTIVE',emp_id*3.14159 AS empid_x_pi ,lname,upper(lname) AS last_name_upper
FROM employee;

SELECT version(),user(),database();

SELECT cust_id
FROM account;

SELECT DISTINCT cust_id
FROM account;

CREATE VIEW employee_vw AS 
SELECT emp_id,fname,lname,
    year(start_date) AS start_year
FROM employee;

SELECT *
FROM employee_vw;

SELECT DISTINCT *
FROM employee INNER JOIN branch
    ON emp_id=branch_id;
    
SELECT 
    d.name, count(e.emp_id) AS num_employees
FROM department AS d INNER JOIN employee AS e 
    ON d.dept_id = e.dept_id
GROUP BY d.name
HAVING count(e.emp_id) > 2
ORDER BY num_employees DESC;

SELECT *
FROM customer
ORDER BY right(fed_id,3);

SELECT *
FROM employee
ORDER BY 2, 5;
    
