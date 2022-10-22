# Write your MySQL query statement below
select 
    name, 
    balance
from 
   ( select 
        account,
        sum(amount) as balance
    from transactions
    group by account
    having sum(amount) > 10000
   )a
inner join users on a.account = users.account;
