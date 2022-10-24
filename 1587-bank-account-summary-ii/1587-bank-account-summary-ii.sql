# Write your MySQL query statement below
select
    name,
    sum(amount) as balance
from    
    users
        inner join
    transactions on users.account = transactions.account
group by users.account
having sum(amount) > 10000;