# Write your MySQL query statement below
select
ifnull (( select distinct salary 
from employee
order by salary desc 
limit 1 offset 1), null)
as secondhighestsalary;