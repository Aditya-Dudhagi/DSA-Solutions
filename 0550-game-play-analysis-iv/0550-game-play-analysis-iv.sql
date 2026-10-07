# Write your MySQL query statement below
select round(
    count(distinct a.player_id) / (select count(distinct player_id) from Activity), 
    2 ) as fraction
from Activity a
join Activity b
on a.player_id = b.player_id and b.event_date = date_add(a.event_date, interval 1 day)
where (a.player_id, a.event_date) in (
    select player_id, min(event_date)
    from Activity
    group by player_id
);