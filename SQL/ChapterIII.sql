/*
SELECT order_id , customers.customer_id , first_name , last_name
FROM orders
JOIN customers
	on orders.customer_id = customers.customer_id
*/

/*
SELECT order_id , oi.product_id , quantity , oi.unit_price
FROM order_items oi
JOIN products p ON oi.product_id = p.product_id
*/

/*
USE sql_store;

SELECT *
FROM order_items oi
JOIN sql_inventory.products p
	ON oi.product_id = p.product_id
*/

/*
USE sql_hr;

SELECT *
FROM employees e
JOIN employees m
	ON e.reports_to = m.employee_id
*/

/*
SELECT 
	e.employee_id,
    e.first_name,
    m.employee_id AS manager_id,
    m.first_name AS manager
FROM employees e
JOIN employees m
	ON e.reports_to = m.employee_id
*/

/*
USE sql_store;

SELECT *
FROM orders o
JOIN customers c
	ON o.customer_id = c.customer_id
JOIN order_statuses os
	ON o.status = os.order_status_id
*/

/*
SELECT *
FROM order_items oi
JOIN order_item_notes oin
	ON oi.order_id = oin.order_id
    AND oi.product_id = oin.product_id
*/

/*
SELECT *
FROM customers c
LEFT JOIN orders o
	ON c.customer_id = o.customer_id
ORDER BY c.customer_id
*/



-- USE sql_hr;

/*
SELECT *
FROM employees e
JOIN employees m
	ON e.reports_to = m.employee_id
*/

SELECT 
	customer_id,
    first_name,
    points,
    'Bronze' AS type
FROM customers
WHERE points <= 1000
UNiON
SELECT 
	customer_id,
    first_name,
    points,
    'Silver' AS type
FROM customers
WHERE points > 1000 AND points <=3000
UNION
SELECT 
	customer_id,
    first_name,
    points,
    'Gold' AS type
FROM customers
WHERE points >3000
ORDER BY first_name