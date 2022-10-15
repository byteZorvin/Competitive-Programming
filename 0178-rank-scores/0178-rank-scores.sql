# Write your MySQL query statement below

SELECT S.score, count(distinct t.score) as 'rank'
from scores s
inner join
scores t where s.score <= t.score
group by s.id
order by s.score desc;