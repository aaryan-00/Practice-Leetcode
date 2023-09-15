# Write your MySQL query statement below
# select customer_id, count(v.visit_id) as count_no_trans from Visits v left join transactions t 
# on v.visit_id=t.visit_id 
# where t.amount is null
# group by customer_id


SELECT v.customer_id, COUNT(v.customer_id) as count_no_trans
FROM visits v
WHERE v.visit_id NOT IN (SELECT t.visit_id
FROM transactions t)
GROUP BY v.customer_id;