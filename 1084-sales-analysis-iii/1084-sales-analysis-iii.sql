# Write your MySQL query statement below
select 
    s.product_id,
    product_name
from
    product p
        inner join
    sales s on p.product_id = s.product_id
group by s.product_id
having
    min(sale_date) >= '2019-01-01' and max(sale_date) <= '2019-03-31';