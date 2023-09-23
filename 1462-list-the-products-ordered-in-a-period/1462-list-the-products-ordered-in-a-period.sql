# Write your MySQL query statement below
# select p.product_name, sum(o.unit) as unit from Products p left join Orders o on p.product_id=o.product_id
# where (order_date BETWEEN '2020-02-01' AND '2020-02-29')
# group by product_name having unit>=100;

SELECT product_name, sum(unit) AS unit
FROM Products p LEFT JOIN Orders o
ON p.product_id = o.product_id WHERE MONTH(order_date)=2 AND YEAR(order_date)=2020
GROUP BY o.product_id HAVING unit >= 100