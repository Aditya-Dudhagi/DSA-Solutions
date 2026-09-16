# Write your MySQL query statement below

select distinct num as ConsecutiveNums
from (
    select num,
    lag(num) over (order by id) as prevnum,
    lead(num) over(order by id) as nextnum
    from Logs
) t
where prevnum = num and nextnum = num;
