# Write your MySQL query statement below
select
    activity_date as day,
    count(distinct user_id) as active_users
from 
    activity
where activity_date <= '2019-07-27' and datediff('2019-07-27', activity_date) < 30
group by activity_date;