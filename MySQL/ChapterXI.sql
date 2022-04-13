SELECT  c.cust_id, c.fed_id,
    CASE
        WHERE c.cust_type_cd='I'
            THEN concat(i.fname,' ',i.lname)
        WHEN c.cust_type_cd='B'
            THEN b.name
        ELSE 'Unknown'
    END AS name
FROM customer AS c LEFT OUTER JOIN individual AS i
    ON c.cust_id=i.cust_id
    LEFT OUTER JOIN business AS b
    ON c.cust_id=b.cust_id;