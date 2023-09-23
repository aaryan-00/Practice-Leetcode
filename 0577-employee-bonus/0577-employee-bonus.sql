# Write your MySQL query statement below
SELECT e.name as name,
b.bonus as bonus 
from Employee e 
LEFT JOIN 
Bonus b on e.empId=b.empId
having bonus<1000 or bonus is NULL;