# Write your MySQL query statement below


-- Use dense_rank() to rank salaried with same amount same without skipping through ranks 
with rankedSalaries as (
    select salary,
    name,
    departmentId ,
    dense_rank() over(partition by departmentId order by salary desc) as salary_rnk
from Employee
) 
select d.name as Department ,
    rs.name as Employee ,
    rs.salary  
from rankedSalaries rs 
join Department d 
On d.id=rs.departmentId
where rs.salary_rnk <=3
order by d.name,rs.salary desc ,rs.name
