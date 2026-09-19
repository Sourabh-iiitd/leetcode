# Write your MySQL query statement below
select b.name as Department, 
a.name as Employee,
a.salary as Salary

  from Employee as a
   join Department as b 
   on a.departmentId=b.id 
   where(a.departmentId, a.salary) IN (select departmentID, max(salary) from Employee group by departmentId);