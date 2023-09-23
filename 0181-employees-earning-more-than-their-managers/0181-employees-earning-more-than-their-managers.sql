# Write your MySQL query statement below
# select name as Employee from Employee e1
# where salary >(select salary from Employee where e1.managerId=id);


SELECT e1.Name AS Employee
FROM Employee e1
JOIN Employee e2
ON e1.ManagerId = e2.Id where e1.Salary > e2.Salary;
