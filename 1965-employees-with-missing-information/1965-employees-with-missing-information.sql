# Write your MySQL query statement below

select * from
(    SELECT e.employee_id
        FROM employees e 
    left join 
        salaries s on e.employee_id = s.employee_id
    where s.salary is null
union 
    SELECT s.employee_id
        FROM employees e 
    right join 
        salaries s on e.employee_id = s.employee_id
    where e.name is null
) as t
order by t.employee_id asc;
