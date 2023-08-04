# Write your MySQL query statement below
WITH cte_rnk AS(
  SELECT *, RANK() OVER(ORDER BY salary) AS rnk
  FROM Employee
)
SELECT salary AS SecondHighestSalary
FROM cte_rnk
WHERE CASE WHEN rnk=2 THEN salary 
      ELSE null END;

SELECT salary AS SecondHighestSalary
FROM (
  SELECT *, DENSE_RANK() OVER(ORDER BY salary) AS rnk
  FROM Employee
) a
WHERE CASE WHEN rnk=2 THEN salary
WHEN rnk=1 THEN null
ELSE null END;

SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (
  SELECT MAX(salary) 
  FROM Employee
);