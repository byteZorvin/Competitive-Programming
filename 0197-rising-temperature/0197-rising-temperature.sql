# Write your MySQL query statement below
select 
    weather.id as id
from 
    weather 
        join
    weather w on datediff(weather.recorddate, w.recorddate) = 1
        and weather.temperature > w.temperature
;