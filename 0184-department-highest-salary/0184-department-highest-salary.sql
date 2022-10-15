# Write your MySQL query statement below
select 
    Department.name as department,
    employee.name as employee, 
    salary
from 
    employee
        inner join
    department on employee.departmentid = department.id
where 
    (employee.departmentid, salary) in 
    (
        select 
            departmentid, max(salary)
        from 
            employee
        group by departmentid
    )
;