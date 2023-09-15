# Write your MySQL query statement below
select name,sum(amount) as balance 
from users u
join 
Transactions t
on u.account=t.account
group by name having balance>10000;