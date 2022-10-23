# Write your MySQL query statement below
select  
    user_id as buyer_id,
    join_date, 
    ifnull(count(order_date),0) as orders_in_2019
from
    (
        select 
            order_date, 
            order_id,
            buyer_id
        from 
            orders
        where year(order_date) = '2019'
    ) o
        right join
    users u on o.buyer_id = u.user_id
group by user_id;