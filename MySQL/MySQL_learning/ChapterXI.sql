SELECT 
    c.cust_id,
    c.fed_id,
    (CASE
        WHEN c.cust_type_cd = 'I' THEN CONCAT(i.fname, ' ', i.lname)
        WHEN c.cust_type_cd = 'B' THEN b.name
        ELSE 'Unknown'
    END) AS name
FROM
    customer AS c
        LEFT OUTER JOIN
    individual AS i ON c.cust_id = i.cust_id
        LEFT OUTER JOIN
    business AS b ON c.cust_id = b.cust_id;
    
SELECT 
    c.cust_id,
    c.fed_id,
    (CASE
        WHEN
            c.cust_type_cd = 'I'
        THEN
            (SELECT 
                    CONCAT(i.fname, ' ', i.lname)
                FROM
                    individual AS i
                WHERE
                    i.cust_id = c.cust_id)
        WHEN
            c.cust_type_cd = 'B'
        THEN
            (SELECT 
                    b.name
                FROM
                    business AS b
                WHERE
                    b.cust_id = c.cust_id)
        ELSE 'Unknown'
    END) AS name
FROM
    customer AS c;

SELECT 
    YEAR(open_date) AS year, COUNT(*) AS how_many
FROM
    account
WHERE
    open_date > '1999-12-31'
        AND open_date < '2006-01-01'
GROUP BY YEAR(open_date);

SELECT 
    CONCAT('ALERT!:Account #',
            a.account_id,
            'Has Incorrect Balance!') AS '\'ALERT!:Account #\'+a.account_id+\'Has Incorrect Balance!\''
FROM
    account AS a
WHERE
    (a.avail_balance , a.pending_balance) <> (SELECT 
            SUM(CASE
                    WHEN t.funds_avail_date > CURRENT_TIMESTAMP() THEN 0
                    WHEN t.txn_type_cd = 'DBT' THEN t.amount * - 1
                    ELSE t.amount
                END),
                SUM(CASE
                    WHEN t.txn_type_cd = 'DBT' THEN t.amount * - 1
                    ELSE t.amount
                END)
        FROM
            transaction AS t
        WHERE
            t.account_id = a.account_id);

