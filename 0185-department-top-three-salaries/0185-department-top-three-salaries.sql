# Write your MySQL query statement below

-- check other solution by dense rank 
-- in submitted solutions also

select 
    d.name as department,
    a.name as employee, 
    a.salary
from 
    employee as a
        inner join
    department as d on d.id = a.departmentid
where
    3 > (
        select
            count(distinct e.salary)
        from 
            employee as e
        where e.salary > a.salary and e.departmentid = a.departmentid
    )
;
    