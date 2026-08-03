# Write your MySQL query statement below
select distinct a.num as ConsecutiveNums
from Logs a
 join Logs b
on a.id+1 = b.id
 join Logs c
on b.id+1 = c.id
where a.num = b.num and b.num = c.num
