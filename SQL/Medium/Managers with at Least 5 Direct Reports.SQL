SELECT name FROM employee 
WHERE id IN
(select managerId from Employee
group by managerId
having count(managerId)>=5) 
