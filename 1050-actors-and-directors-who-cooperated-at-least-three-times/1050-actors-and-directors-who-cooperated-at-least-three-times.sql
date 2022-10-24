# Write your MySQL query statement below
select
    actor_id,
    director_id
from    
    actorDirector ad
group by actor_id, director_id
having count(1) >= 3;