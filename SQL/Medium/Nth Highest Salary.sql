-- CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
-- BEGIN
-- SET N = N-1;
--   RETURN (
--       SELECT DISTINCT(salary) 
--       FROM Employee 
--       ORDER BY salary DESC
--       LIMIT 1 OFFSET N
--   );
-- END
SELECT
  DISTINCT(salary)
FROM
  Employee E1
WHERE
  N -1 = (
    SELECT
      COUNT(DISTINCT(E2.salary))
    FROM
      Employee E2
    WHERE
      E2.salary > E1.salary
  )