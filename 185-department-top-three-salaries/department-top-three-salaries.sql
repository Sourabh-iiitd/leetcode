# Write your MySQL query statement below
select b.name as Department, a.name as Employee , a.salary as Salary
From Employee a join Department b
on a.departmentId=b.id
where 3> (select count(distinct c.salary)
from Employee c where c.departmentId= a.departmentId and c.salary>a.salary);