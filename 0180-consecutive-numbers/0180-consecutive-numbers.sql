# Write your MySQL query statement below
select distinct num as ConsecutiveNums
from (
    select num,
    LAG(num) over (order by id) as prevnum,
    LEAD(num) over (order by id) as nextnum
    from Logs
) t
where prevnum = num and nextnum = num