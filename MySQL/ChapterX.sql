SELECT account_id, cust_id
FROM account;

SELECT cust_id
FROM customer;

SELECT a.account_id,c.cust_id
FROM account AS a INNER JOIN customer AS c
    ON a.cust_id =c.cust_id;
    
SELECT a.account_id, a.cust_id,b.name
FROM account AS a INNER JOIN business AS b
    ON a.cust_id=b.cust_id;
    
##LEFT与RIGHT仅用于判断哪边数据可以不足    
SELECT a.account_id, a.cust_id,b.name
FROM account AS a LEFT OUTER JOIN business AS b
    ON a.cust_id=b.cust_id;
    
SELECT c.cust_id,b.name
FROM customer AS c RIGHT OUTER JOIN business AS b
    ON c.cust_id=b.cust_id;
    
SELECT a.account_id, a.product_cd,
    concat(i.fname,' ',i.lname) AS person_name,
    b.name AS business_name
FROM account AS a LEFT OUTER JOIN individual AS i
    ON a.cust_id=i.cust_id
    LEFT OUTER JOIN business AS b
    ON a.cust_id=b.cust_id;
    
SELECT 
    account_ind.account_id,
    account_ind.product_cd,
    account_ind.person_name,
    b.name AS business_name
FROM
    (SELECT 
        a.account_id,
            a.product_cd,
            a.cust_id,
            CONCAT(i.fname, ' ', i.lname) AS person_name
    FROM
        account AS a
    LEFT OUTER JOIN individual AS i ON a.cust_id = i.cust_id) AS account_ind
        LEFT OUTER JOIN
    business AS b ON account_ind.cust_id = b.cust_id;