import MySQLdb

db = MySQLdb.connect(host='127.0.0.1',
                     user='root',
                     passwd='asdf8296776',
                     db='datascience',
                     charset='UTF8')

c = db.cursor()
SQL="SHOW tables;"
c.execute(SQL)

result = c.fetchall()

print(result)

SQL="INSERT INTO products (product_id,product_name,account_id) VALUES (19,'HERO',45)"
c.execute(SQL)
SQL="SELECT * FROM products"
c.execute(SQL)
result = c.fetchall()

print(result)
