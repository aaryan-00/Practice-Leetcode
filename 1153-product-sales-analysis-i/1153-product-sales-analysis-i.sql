# Write your MySQL query statement below
# select product_name,year,price
# from Product, Sales
# where Product.product_id=Sales.product_id;

# select product_name,year,price
# from Product join Sales
# on Product.product_id=Sales.product_id;


select p.product_name,s.year,s.price
from Product as p join Sales as s
on p.product_id=s.product_id;