# Write your MySQL query statement below
select c.name as Customers from customers c
left join 
orders o on c.id = o.customerid
where o.customerid is null;
