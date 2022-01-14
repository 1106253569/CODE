/*
SELECT *
FROM customers
WHERE birth_date > '1990-01-01' OR points > 1000
*/

/*
SELECT *
FROM order_items
WHERE order_id = 6 AND unit_price * quantity > 30 
*/

/*
SELECT *
FROM customers
WHERE state IN ('VA','FL','GA')
*/

/*
SELECT *
FROM customers
WHERE birth_date BETWEEN '1990-01-01' AND '2000-01-01'
*/

/*
SELECT *
FROM customers
WHERE last_name LIKE 'b%'
-- %任意数量字符
-- _单字符
*/

/*
SELECT *
FROM customers
WHERE address LIKE '%TRAIL%' OR 
	address LIKE '%AVENUE%' 
*/

/*
SELECT *
FROM customers
WHERE last_name REGEXP 'field'
-- ^查询开头
-- $查询结尾
*/

/*
SELECT *
FROM customers 
WHERE last_name REGEXP 'field|mac|rose'
-- [abc]e=ae|be|ce
-- [a-c]e=ae|be|ce
*/

/*
SELECT *
FROM customers
WHERE first_name = 'ELKA' OR first_name = 'AMBUR'
*/

/*
SELECT *
FROM customers
WHERE first_name REGEXP 'EY$|ON$' 
*/

/*
SELECT *
FROM customers
WHERE first_name REGEXP '^MY|SE'
*/

/*
SELECT *
FROM customers
WHERE first_name REGEXP 'B[RU]'
*/

/*
SELECT *
FROM orders
WHERE shipper_id IS NULL
*/

/*
SELECT *
FROM customers
ORDER BY state DESC, first_name DESC
*/

/*
SELECT *
FROM customers
WHERE  customer_id > 1000 AND customer_id < 1100
ORDER BY state , first_name 
*/

/*
SELECT *
FROM customers
ORDER BY points DESC
LIMIT 300 , 3
*/