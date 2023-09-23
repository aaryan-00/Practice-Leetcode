-- Retrieving employees with primary_flag set to 'Y'
# SELECT 
#   employee_id, 
#   department_id 
# FROM 
#   Employee 
# WHERE 
#   primary_flag = 'Y' 
# UNION 
# -- Retrieving employees that appear exactly once in the Employee table
# SELECT 
#   employee_id, 
#   department_id 
# FROM 
#   Employee 
# GROUP BY 
#   employee_id 
# HAVING 
#   COUNT(employee_id) = 1;


select employee_id, department_id
from Employee
where primary_flag = 'Y' or employee_id in (
select employee_id from employee group by employee_id having count(department_id) = 1)